#pragma once

#include <sstream>

#include <Win33/Application.h>
#include <Win33/Window.h>
#include <Win33/TextBox.h>
#include <Win33/Button.h>

enum class Input : wchar_t {
    One          = L'1',
    Two          = L'2',
    Three        = L'3',
    Four         = L'4',
    Five         = L'5',
    Six          = L'6',
    Seven        = L'7',
    Eight        = L'8',
    Nine         = L'9',
    Zero         = L'0',
    Add          = L'+',
    Subtract     = L'-',
    Multiply     = L'\u00D7',
    Divide       = L'\u00F7',
    Backspace    = L'\u2190',
    Clear        = L'C',
    Dot          = L'.',
    OpenBracket  = L'(',
    CloseBracket = L')',
    Equals       = L'='
};

class Calculator {
public:
    Calculator            ( );
    Calculator            ( const Calculator&  other ) = default;
    Calculator            (       Calculator&& other ) = default;
    Calculator& operator= ( const Calculator&  other ) = default;
    Calculator& operator= (       Calculator&& other ) = default;
    ~Calculator           ( )                          = default;
    
    void addInput( Input input );
    
    std::wstring getExpression( ) const;
    
private:
    wchar_t peek( );
    wchar_t get( );
    
    double number( );
    double factor( );
    double term( );
    double expression( );
    
    std::wstring        mExpression;
    std::wistringstream mWISS;
};

class CalculatorWindow : public Win33::Window {
public:
    CalculatorWindow            ( );
    CalculatorWindow            ( const CalculatorWindow&  other ) = delete;
    CalculatorWindow            (       CalculatorWindow&& other ) = delete;
    CalculatorWindow& operator= ( const CalculatorWindow&  other ) = delete;
    CalculatorWindow& operator= (       CalculatorWindow&& other ) = delete;
    ~CalculatorWindow           ( )                                = default;
    
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
    Win33::Button  mClear;
    Win33::Button  mZero;
    Win33::Button  mDot;
    Win33::Button  mAdd;
    Win33::Button  mSubtract;
    Win33::Button  mMultiply;
    Win33::Button  mDivide;
    Win33::Button  mBackspace;
    Win33::Button  mOpenBracket;
    Win33::Button  mCloseBracket;
    Win33::Button  mEquals;
    
    Calculator mCalculator;
};

class CalculatorApplication : public Win33::Application {
public:
    CalculatorApplication            ( );
    CalculatorApplication            ( const CalculatorApplication&  other ) = delete;
    CalculatorApplication            (       CalculatorApplication&& other ) = delete;
    CalculatorApplication& operator= ( const CalculatorApplication&  other ) = delete;
    CalculatorApplication& operator= (       CalculatorApplication&& other ) = delete;
    ~CalculatorApplication           ( )                                     = default;
    
    int run( );
    
private:
    CalculatorWindow mCalculatorWindow;
};