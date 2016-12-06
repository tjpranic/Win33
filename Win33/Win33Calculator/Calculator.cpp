#include "Calculator.h"

CalculatorWindow::CalculatorWindow( )
:
Win33::Window ( Win33::Window::DefaultPosition, { 306, 243 } ),
mResult       ( this, {  11,  10 }, { 270, 20 }, L"", Win33::EditStyle::Right ),
mOne          ( this, {  10,  35 }, {  50, 50 }, L"1" ),
mTwo          ( this, {  65,  35 }, {  50, 50 }, L"2" ),
mThree        ( this, { 120,  35 }, {  50, 50 }, L"3" ),
mFour         ( this, {  10,  90 }, {  50, 50 }, L"4" ),
mFive         ( this, {  65,  90 }, {  50, 50 }, L"5" ),
mSix          ( this, { 120,  90 }, {  50, 50 }, L"6" ),
mSeven        ( this, {  10, 145 }, {  50, 50 }, L"7" ),
mEight        ( this, {  65, 145 }, {  50, 50 }, L"8" ),
mNine         ( this, { 120, 145 }, {  50, 50 }, L"9" ),
mAdd          ( this, { 175,  35 }, {  50, 50 }, L"+" ),
mSubtract     ( this, { 230,  35 }, {  50, 50 }, L"-" ),
mMultiply     ( this, { 175,  90 }, {  50, 50 }, L"*" ),
mDivide       ( this, { 230,  90 }, {  50, 50 }, L"/" ),
mEquals       ( this, { 175, 145 }, {  50, 50 }, L"=" ),
mClear        ( this, { 230, 145 }, {  50, 50 }, L"C" )
{
    setTitle       ( L"Calculator" );
    setResizable   ( false );
    setMaximizable ( false );
    setMinimizable ( false );
    
    mResult.setReadOnly( true );
    
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
    
    mAdd.onClick += [&]( ) {
        
    };
    mSubtract.onClick += [&]( ) {
        
    };
    mMultiply.onClick += [&]( ) {
        
    };
    mDivide.onClick += [&]( ) {
        
    };
    
    mClear.onClick += [&]( ) {
        mResult.setText( L"" );
    };
}

CalculatorApplication::CalculatorApplication( )
:
Win33::Application( ),
mCalculatorWindow( )
{
    mCalculatorWindow.show( );
}