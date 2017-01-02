#include "Calculator.h"

#include <Win33PopupBox.h>
#include <Win33StringUtilities.h>

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
mMultiply     ( this, { 175, 155 }, {  50, 50 }, L"*" ),
mDivide       ( this, { 175, 210 }, {  50, 50 }, L"/" ),
mBackspace    ( this, { 230, 45  }, {  50, 50 }, L"\u2190" ), //left arrow
mOpenBracket  ( this, { 230, 100 }, {  50, 50 }, L"(" ),
mCloseBracket ( this, { 230, 155 }, {  50, 50 }, L")" ),
mEquals       ( this, { 230, 210 }, {  50, 50 }, L"=" )
{
    setTitle       ( L"Calculator" );
    setResizable   ( false );
    setMaximizable ( false );
    setMinimizable ( false );
    
    mResult.setReadOnly ( true );
    mResult.setFont     ( &SegoeUI24Bold );
    mResult.setText     ( L"0" );
    
    mOne.setFont          ( &SegoeUI18 );
    mTwo.setFont          ( &SegoeUI18 );
    mThree.setFont        ( &SegoeUI18 );
    mFour.setFont         ( &SegoeUI18 );
    mFive.setFont         ( &SegoeUI18 );
    mSix.setFont          ( &SegoeUI18 );
    mSeven.setFont        ( &SegoeUI18 );
    mEight.setFont        ( &SegoeUI18 );
    mNine.setFont         ( &SegoeUI18 );
    mClear.setFont        ( &SegoeUI18 );
    mZero.setFont         ( &SegoeUI18 );
    mAdd.setFont          ( &SegoeUI18 );
    mSubtract.setFont     ( &SegoeUI18 );
    mMultiply.setFont     ( &SegoeUI18 );
    mDivide.setFont       ( &SegoeUI18 );
    mEquals.setFont       ( &SegoeUI18 );
    mBackspace.setFont    ( &SegoeUI18 );
    mOpenBracket.setFont  ( &SegoeUI18 );
    mCloseBracket.setFont ( &SegoeUI18 );
    mDot.setFont          ( &SegoeUI18 );
    
    mOne.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"1" : mResult.getText( ) + L"1" );
    };
    mTwo.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"2" : mResult.getText( ) + L"2" );
    };
    mThree.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"3" : mResult.getText( ) + L"3" );
    };
    mFour.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"4" : mResult.getText( ) + L"4" );
    };
    mFive.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"5" : mResult.getText( ) + L"5" );
    };
    mSix.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"6" : mResult.getText( ) + L"6" );
    };
    mSeven.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"7" : mResult.getText( ) + L"7" );
    };
    mEight.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"8" : mResult.getText( ) + L"8" );
    };
    mNine.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"9" : mResult.getText( ) + L"9" );
    };
    mClear.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( L"0" );
    };
    mZero.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        if( mResult.getText( ) != L"0" ) {
            mResult.setText( mResult.getText( ) + L"0" );
        }
    };
    mDot.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        auto text = mResult.getText( );
        auto last = text.back( );
        if( last != L'+' && last != L'-' && last != L'*' && last != L'/' && last != L'.' && text != L"0" ) {
            mResult.setText( ( text == L"0" ) ? L"." : text + L"." );
        }
    };
    mAdd.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        auto text = mResult.getText( );
        auto last = text.back( );
        if( last != L'+' && last != L'-' && last != L'*' && last != L'/' && last != L'.' && text != L"0" ) {
            mResult.setText( text + L"+" );
        }
    };
    mSubtract.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        auto text = mResult.getText( );
        auto last = text.back( );
        if( last != L'+' && last != L'-' && last != L'*' && last != L'/' && last != L'.' ) {
            mResult.setText( ( text == L"0" ) ? L"-" : text + L"-" );
        }
    };
    mMultiply.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        auto text = mResult.getText( );
        auto last = text.back( );
        if( last != L'+' && last != L'-' && last != L'*' && last != L'/' && last != L'.' && text != L"0" ) {
            mResult.setText( text + L"*" );
        }
    };
    mDivide.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        auto text = mResult.getText( );
        auto last = text.back( );
        if( last != L'+' && last != L'-' && last != L'*' && last != L'/' && last != L'.' && text != L"0" ) {
            mResult.setText( text + L"/" );
        }
    };
    mBackspace.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        auto text = mResult.getText( );
        if( text.size( ) == 1 ) {
            mResult.setText( L"0" );
        }
        else if( text != L"0" ) {
            mResult.setText( text.substr( 0, text.size( ) - 1 ) );
        }
    };
    mOpenBracket.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L"(" : mResult.getText( ) + L"(" );
    };
    mCloseBracket.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        mResult.setText( ( mResult.getText( ) == L"0" ) ? L")" : mResult.getText( ) + L")" );
    };
    mEquals.onClick += [&]( Win33::ButtonEvents::ClickData& data ) {
        auto result = 0.0;
        //...arithmetic expression parser goes here...
        mResult.setText( Win33::String::format( L"%g", result ) );
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