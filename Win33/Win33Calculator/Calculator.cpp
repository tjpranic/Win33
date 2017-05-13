#include "Calculator.h"

#include <Win33/PopupBox.h>
#include <Win33/StringUtilities.h>

#include "Resources.h"

Calculator::Calculator( )
:
mExpression ( L"0" ),
mWISS       ( )
{ }

//ensures the entered expression is as well-formed as possible by restricting certain
//inputs from being entered if entering them would result in a malformed expression.
void Calculator::addInput( Input input ) {
    auto character = static_cast<wchar_t>( input );
    switch( input ) {
        case Input::One:
        case Input::Two:
        case Input::Three:
        case Input::Four:
        case Input::Five:
        case Input::Six:
        case Input::Seven:
        case Input::Eight:
        case Input::Nine:
        case Input::Zero: {
            if( mExpression != L"0" && mExpression != L"Error" ) {
                auto lastCharacter = mExpression.back( );
                if( lastCharacter != L')' ) {
                    auto index      = mExpression.find_last_of( L"+-\u00D7\u00F7" );
                    auto lastNumber = index == std::wstring::npos ? mExpression : index == mExpression.size( ) - 1 ? L"" : mExpression.substr( index + 1 );
                    if( lastNumber != L"0" ) {
                        mExpression += character;
                    }
                    else {
                        mExpression = mExpression.substr( 0, mExpression.size( ) - 1 ) + character;
                    }
                }
            }
            else {
                mExpression = std::wstring( 1, character );
            }
            break;
        }
        case Input::Clear: {
            mExpression = L"0";
            break;
        }
        case Input::Dot: {
            if( mExpression != L"Error" ) {
                auto index      = mExpression.find_last_of( L"+-\u00D7\u00F7" );
                auto lastNumber = index == std::wstring::npos ? mExpression : index == mExpression.size( ) - 1 ? L"" : mExpression.substr( index + 1 );
                auto notDecimal = lastNumber != L"" && lastNumber.find_last_of( L'.' ) == std::wstring::npos;
                if( notDecimal ) {
                    mExpression += L'.';
                }
            }
            break;
        }
        case Input::Add:
        case Input::Subtract:
        case Input::Multiply:
        case Input::Divide: {
            if( mExpression != L"Error" ) {
                auto lastCharacter = mExpression.back( );
                if( lastCharacter == L'.' ) {
                    //do nothing and don't overwrite last input
                }
                else if( lastCharacter != L'+' && lastCharacter != L'-' && lastCharacter != L'\u00F7' && lastCharacter != L'\u00D7' ) {
                    mExpression += character;
                }
                else {
                    mExpression = mExpression.substr( 0, mExpression.size( ) - 1 ) + character;
                }
            }
            break;
        }
        case Input::Backspace: {
            if( mExpression.size( ) > 1 && mExpression != L"Error" ) {
                mExpression = mExpression.substr( 0, mExpression.size( ) - 1 );
            }
            else {
                mExpression = L"0";
            }
            break;
        }
        case Input::OpenBracket: {
            if( mExpression != L"Error" ) {
                if( mExpression != L"0" ) {
                    auto lastCharacter = mExpression.back( );
                    auto notNumber = !( lastCharacter >= L'0' && lastCharacter <= L'9' );
                    if( notNumber ) {
                        mExpression += L'(';
                    }
                }
                else {
                    mExpression = L"(";
                }
            }
            break;
        }
        case Input::CloseBracket: {
            if( mExpression != L"Error" ) {
                if( mExpression != L"0" ) {
                    auto lastCharacter = mExpression.back( );
                    if( lastCharacter != L'(' && lastCharacter != L'+' && lastCharacter != L'-' && lastCharacter != L'\u00F7' && lastCharacter != L'\u00D7' ) {
                        mExpression += L')';
                    }
                }
                else {
                    mExpression = L")";
                }
            }
            break;
        }
        case Input::Equals: {
            try {
                mWISS.str   ( mExpression );
                mWISS.clear ( );
                mExpression = Win33::String::format( L"%g", expression( ) );
            }
            catch( const std::exception& ) {
                mExpression = L"Error";
            }
            break;
        }
        default: {
            throw std::runtime_error( "Unknown input." );
        }
    }
}

std::wstring Calculator::getExpression( ) const {
    return mExpression;
}

wchar_t Calculator::peek( ) {
    return static_cast<wchar_t>( mWISS.peek( ) );
}
wchar_t Calculator::get( ) {
    return static_cast<wchar_t>( mWISS.get( ) );
}

//recursive descent parser that evaluates expressions, expects (mostly) well-formed expressions.
double Calculator::number( ) {
    double result;
    mWISS >> result;
    if( mWISS.fail( ) ) {
        throw std::runtime_error( "Malformed number in expression." ); 
    }
    return result;
}
double Calculator::factor( ) {
    if( peek( ) >= L'0' && peek( ) <= L'9' ) {
        return number( );
    }
    else if( peek( ) == L'(' ) {
        auto openBracket   = get( );
        auto result        = expression( );
        auto closedBracket = get( );
        return result;
    }
    else if( peek( ) == L'-' ) {
        auto negativeSign = get( );
        return -factor( );
    }
    else if( peek( ) == L'+' ) {
        auto positiveSign = get( );
        return factor( );
    }
    throw std::runtime_error( "Unable to evaluate expression." );
}
double Calculator::term( ) {
    auto result = factor( );
    while( peek( ) == L'\u00D7' || peek( ) == L'\u00F7' ) {
        if( get( ) == L'\u00D7' ) {
            result *= factor( );
        }
        else {
            result /= factor( );
        }
    }
    return result;
}
double Calculator::expression( ) {
    auto result = term( );
    while( peek( ) == L'+' || peek( ) == L'-' ) {
        if( get( ) == L'+' ) {
            result += term( );
        }
        else {
            result -= term( );
        }
    }
    return result;
}

CalculatorWindow::CalculatorWindow( )
:
Win33::Window ( Win33::Window::DefaultPosition, { 306, 308 } ),
mResult       ( this, {  11,  10 }, { 270, 30 }, L"", Win33::EditStyle::Right ),
mOne          ( this, {  10,  45 }, {  50, 50 }, L"1" ),
mTwo          ( this, {  65,  45 }, {  50, 50 }, L"2" ),
mThree        ( this, { 120,  45 }, {  50, 50 }, L"3" ),
mFour         ( this, {  10, 100 }, {  50, 50 }, L"4" ),
mFive         ( this, {  65, 100 }, {  50, 50 }, L"5" ),
mSix          ( this, { 120, 100 }, {  50, 50 }, L"6" ),
mSeven        ( this, {  10, 155 }, {  50, 50 }, L"7" ),
mEight        ( this, {  65, 155 }, {  50, 50 }, L"8" ),
mNine         ( this, { 120, 155 }, {  50, 50 }, L"9" ),
mClear        ( this, {  10, 210 }, {  50, 50 }, L"C" ),
mZero         ( this, {  65, 210 }, {  50, 50 }, L"0" ),
mDot          ( this, { 120, 210 }, {  50, 50 }, L"." ),
mAdd          ( this, { 175,  45 }, {  50, 50 }, L"+" ),
mSubtract     ( this, { 175, 100 }, {  50, 50 }, L"-" ),
mMultiply     ( this, { 175, 155 }, {  50, 50 }, L"\u00D7" ), //times symbol
mDivide       ( this, { 175, 210 }, {  50, 50 }, L"\u00F7" ), //division symbol
mBackspace    ( this, { 230, 45  }, {  50, 50 }, L"\u2190" ), //left arrow
mOpenBracket  ( this, { 230, 100 }, {  50, 50 }, L"(" ),
mCloseBracket ( this, { 230, 155 }, {  50, 50 }, L")" ),
mEquals       ( this, { 230, 210 }, {  50, 50 }, L"=" ),
mCalculator   ( )
{
    setTitle       ( L"Calculator" );
    setResizable   ( false );
    setMaximizable ( false );
    setMinimizable ( false );
    
    mResult.setReadOnly ( true );
    mResult.setFont     ( Fonts::getSegoeUI24Bold( ) );
    mResult.setText     ( mCalculator.getExpression( ) );
    
    mOne.setFont          ( Fonts::getSegoeUI18( ) );
    mTwo.setFont          ( Fonts::getSegoeUI18( ) );
    mThree.setFont        ( Fonts::getSegoeUI18( ) );
    mFour.setFont         ( Fonts::getSegoeUI18( ) );
    mFive.setFont         ( Fonts::getSegoeUI18( ) );
    mSix.setFont          ( Fonts::getSegoeUI18( ) );
    mSeven.setFont        ( Fonts::getSegoeUI18( ) );
    mEight.setFont        ( Fonts::getSegoeUI18( ) );
    mNine.setFont         ( Fonts::getSegoeUI18( ) );
    mClear.setFont        ( Fonts::getSegoeUI18( ) );
    mZero.setFont         ( Fonts::getSegoeUI18( ) );
    mAdd.setFont          ( Fonts::getSegoeUI18( ) );
    mSubtract.setFont     ( Fonts::getSegoeUI18( ) );
    mMultiply.setFont     ( Fonts::getSegoeUI18( ) );
    mDivide.setFont       ( Fonts::getSegoeUI18( ) );
    mEquals.setFont       ( Fonts::getSegoeUI18( ) );
    mBackspace.setFont    ( Fonts::getSegoeUI18( ) );
    mOpenBracket.setFont  ( Fonts::getSegoeUI18( ) );
    mCloseBracket.setFont ( Fonts::getSegoeUI18( ) );
    mDot.setFont          ( Fonts::getSegoeUI18( ) );
    
    mOne.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::One );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mTwo.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Two );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mThree.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Three );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mFour.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Four );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mFive.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Five );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mSix.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Six );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mSeven.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Seven );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mEight.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Eight );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mNine.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Nine );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mClear.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Clear );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mZero.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Zero );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mDot.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Dot );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mAdd.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Add );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mSubtract.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Subtract );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mMultiply.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Multiply );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mDivide.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Divide );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mBackspace.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Backspace );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mOpenBracket.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::OpenBracket );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mCloseBracket.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::CloseBracket );
        mResult.setText( mCalculator.getExpression( ) );
    };
    mEquals.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mCalculator.addInput( Input::Equals );
        mResult.setText( mCalculator.getExpression( ) );
    };
    
    onKeyDown += [&]( Win33::WindowEvents::KeyDownData& data ) {
        switch( data.getKey( ) ) {
            case Win33::Key::Zero:
            case Win33::Key::NumpadZero: {
                mCalculator.addInput( Input::Zero );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::One:
            case Win33::Key::NumpadOne: {
                mCalculator.addInput( Input::One );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Two:
            case Win33::Key::NumpadTwo: {
                mCalculator.addInput( Input::Two );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Three:
            case Win33::Key::NumpadThree: {
                mCalculator.addInput( Input::Three );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Four:
            case Win33::Key::NumpadFour: {
                mCalculator.addInput( Input::Four );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Five:
            case Win33::Key::NumpadFive: {
                mCalculator.addInput( Input::Five );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Six:
            case Win33::Key::NumpadSix: {
                mCalculator.addInput( Input::Six );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Seven:
            case Win33::Key::NumpadSeven: {
                mCalculator.addInput( Input::Seven );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Eight:
            case Win33::Key::NumpadEight: {
                mCalculator.addInput( Input::Eight );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Nine:
            case Win33::Key::NumpadNine: {
                mCalculator.addInput( Input::Nine );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Plus:
            case Win33::Key::NumpadAdd: {
                mCalculator.addInput( Input::Add );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Minus:
            case Win33::Key::NumpadSubtract: {
                mCalculator.addInput( Input::Subtract );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Asterisk:
            case Win33::Key::NumpadMultiply: {
                mCalculator.addInput( Input::Multiply );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Slash:
            case Win33::Key::NumpadDivide: {
                mCalculator.addInput( Input::Divide );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Backspace: {
                mCalculator.addInput( Input::Backspace );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::OpenBracket: {
                mCalculator.addInput( Input::OpenBracket );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::CloseBracket: {
                mCalculator.addInput( Input::CloseBracket );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            case Win33::Key::Equals:
            case Win33::Key::Enter:
            case Win33::Key::NumpadEnter: {
                mCalculator.addInput( Input::Equals );
                mResult.setText( mCalculator.getExpression( ) );
                break;
            }
            default: {
                break;
            }
        }
    };
}

CalculatorApplication::CalculatorApplication( )
:
Win33::Application ( ),
mCalculatorWindow  ( )
{
    mCalculatorWindow.show( );
}

int CalculatorApplication::run( ) {
    try {
        return Win33::Application::run( );
    }
    catch( const std::exception& ex ) {
        mCalculatorWindow.setEnabled( false );
        Win33::PopupBox::error( Win33::String::widen( ex.what( ) ) );
    }
    return 0;
}