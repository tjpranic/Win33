#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33TextBox.h>
#include <Win33Button.h>

const Win33::Font SegoeUI18     = Win33::Font( L"SegoeUI", 18 );
const Win33::Font SegoeUI24Bold = Win33::Font( L"SegoeUI", 24, Win33::FontDecoration::Bold );

class CalculatorWindow : public Win33::Window {
public:
    CalculatorWindow  ( );
    ~CalculatorWindow ( ) = default;
    
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
    Win33::Button  mZero;
    Win33::Button  mDot;
    Win33::Button  mAdd;
    Win33::Button  mSubtract;
    Win33::Button  mMultiply;
    Win33::Button  mDivide;
    Win33::Button  mOpenBracket;
    Win33::Button  mCloseBracket;
    Win33::Button  mClear;
    Win33::Button  mEquals;
};

class CalculatorApplication : public Win33::Application {
public:
    CalculatorApplication  ( );
    ~CalculatorApplication ( ) = default;
    
    int run( );
    
private:
    CalculatorWindow mCalculatorWindow;
};