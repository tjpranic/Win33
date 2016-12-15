#include "Calculator.h"

#include <Win33PopupBox.h>
#include <Win33Utility.h>

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
mZero         ( this, {  65, 210 }, {  50, 50 }, L"0" ),
mAdd          ( this, { 175,  45 }, {  50, 50 }, L"+" ),
mSubtract     ( this, { 175, 100 }, {  50, 50 }, L"-" ),
mMultiply     ( this, { 175, 155 }, {  50, 50 }, L"*" ),
mDivide       ( this, { 175, 210 }, {  50, 50 }, L"/" ),
mEquals       ( this, { 230, 210 }, {  50, 50 }, L"=" ),
mClear        ( this, { 230, 155 }, {  50, 50 }, L"C" ),
mDot          ( this, { 120, 210 }, {  50, 50 }, L"." )
{
    setTitle       ( L"Calculator" );
    setResizable   ( false );
    setMaximizable ( false );
    setMinimizable ( false );
    
    mResult.setReadOnly ( true );
    mResult.setFont     ( &SegoeUI24Bold );
    mResult.setText     ( L"0" );
    
    mOne.setFont      ( &SegoeUI18 );
    mTwo.setFont      ( &SegoeUI18 );
    mThree.setFont    ( &SegoeUI18 );
    mFour.setFont     ( &SegoeUI18 );
    mFive.setFont     ( &SegoeUI18 );
    mSix.setFont      ( &SegoeUI18 );
    mSeven.setFont    ( &SegoeUI18 );
    mEight.setFont    ( &SegoeUI18 );
    mNine.setFont     ( &SegoeUI18 );
    mZero.setFont     ( &SegoeUI18 );
    mAdd.setFont      ( &SegoeUI18 );
    mSubtract.setFont ( &SegoeUI18 );
    mMultiply.setFont ( &SegoeUI18 );
    mDivide.setFont   ( &SegoeUI18 );
    mEquals.setFont   ( &SegoeUI18 );
    mClear.setFont    ( &SegoeUI18 );
    mDot.setFont      ( &SegoeUI18 );
    
    mOne.onClick += [&]( ) {
        
    };
    mTwo.onClick += [&]( ) {
         
    };
    mThree.onClick += [&]( ) {
       
    };
    mFour.onClick += [&]( ) {
        
    };
    mFive.onClick += [&]( ) {
        
    };
    mSix.onClick += [&]( ) {
        
    };
    mSeven.onClick += [&]( ) {
        
    };
    mEight.onClick += [&]( ) {
        
    };
    mNine.onClick += [&]( ) {
        
    };
    mZero.onClick += [&]( ) {
        
    };
    mAdd.onClick += [&]( ) {
        
    };
    mSubtract.onClick += [&]( ) {
        
    };
    mMultiply.onClick += [&]( ) {
        
    };
    mDivide.onClick += [&]( ) {
        
    };
    mEquals.onClick += [&]( ) {
        
    };
    mClear.onClick += [&]( ) {
        
    };
    mDot.onClick += [&]( ) {
        
    };
}

CalculatorApplication::CalculatorApplication( )
:
Win33::Application( ),
mCalculatorWindow( )
{
    mCalculatorWindow.show( );
}

int CalculatorApplication::run( ) {
    try {
        return Win33::Application::run( );
    }
    catch( const std::exception& ex ) {
        mCalculatorWindow.setEnabled( false );
        Win33::PopupBox::error( Win33::Utility::widen( ex.what( ) ) );
    }
    return 0;
}