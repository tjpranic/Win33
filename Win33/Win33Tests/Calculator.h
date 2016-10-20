#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33TextBox.h>
#include <Win33Button.h>

class CalculatorWindow : public Win33::Window {
public:
    CalculatorWindow( )
    :
    Window    ( Win33::DefaultPosition, { 183, 168 } ),
    mResult   ( this, {  11, 10 }, { 145, 20 }, Win33::TextAlignment::Right ),
    mOne      ( this, {  10, 35 }, { 25,  25 }, L"1" ),
    mTwo      ( this, {  40, 35 }, { 25,  25 }, L"2" ),
    mThree    ( this, {  70, 35 }, { 25,  25 }, L"3" ),
    mFour     ( this, {  10, 65 }, { 25,  25 }, L"4" ),
    mFive     ( this, {  40, 65 }, { 25,  25 }, L"5" ),
    mSix      ( this, {  70, 65 }, { 25,  25 }, L"6" ),
    mSeven    ( this, {  10, 95 }, { 25,  25 }, L"7" ),
    mEight    ( this, {  40, 95 }, { 25,  25 }, L"8" ),
    mNine     ( this, {  70, 95 }, { 25,  25 }, L"9" ),
    mDivide   ( this, { 100, 35 }, { 25,  25 }, L"/" ),
    mMultiply ( this, { 130, 35 }, { 25,  25 }, L"*" ),
    mSubtract ( this, { 100, 65 }, { 25,  25 }, L"-" ),
    mAdd      ( this, { 130, 65 }, { 25,  25 }, L"+" ),
    mEquals   ( this, { 100, 95 }, { 55,  25 }, L"=" )
    {
        setTitle       ( L"Calculator" );
        setResizable   ( false );
        setMaximizable ( false );
        setMinimizable ( false );
        
        mResult.setReadOnly( true );
        
        //...
    }
    
private:
    Win33::TextBox mResult;
    Win33::Button  mOne;
    Win33::Button  mTwo;
    Win33::Button  mThree;
    Win33::Button  mFour;
    Win33::Button  mFive;
    Win33::Button  mSix;
    Win33::Button  mSeven;
    Win33::Button  mEight;
    Win33::Button  mNine;
    Win33::Button  mDivide;
    Win33::Button  mMultiply;
    Win33::Button  mSubtract;
    Win33::Button  mAdd;
    Win33::Button  mEquals;
};

class CalculatorApplication : public Win33::Application {
public:
    CalculatorApplication( )
    :
    Application( ),
    mCalculatorWindow( )
    {
        mCalculatorWindow.show( );
    }
    ~CalculatorApplication( ) = default;
    
private:
    CalculatorWindow mCalculatorWindow;
};