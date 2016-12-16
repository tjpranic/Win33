#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33Label.h>
#include <Win33TextBox.h>
#include <Win33MultilineTextBox.h>
#include <Win33PasswordBox.h>
#include <Win33Button.h>
#include <Win33CheckBox.h>
#include <Win33RadioButton.h>
#include <Win33GroupBox.h>
#include <Win33BitfieldOperators.h>

class ControlsWindow : public Win33::Window {
public:
    ControlsWindow( )
    :
    Win33::Window     ( Win33::Window::DefaultPosition, { 340, 220 } ),
    mTextBoxTypes     ( this, {   7,   7 }, { 100,  20 }, L"TextBox Types", Win33::StaticStyle::Center ),
    mTextBox          ( this, {   7,  25 }, { 100,  20 }, L"TextBox" ),
    mMultilineTextBox ( this, {   7,  50 }, { 100, 100 }, Win33::EditStyle::AutoVerticalScroll | Win33::WindowStyle::VerticalScroll, L"MultilineTextBox" ),
    mPasswordBox      ( this, {   7, 155 }, { 100,  20 } ),
    mButtonTypes      ( this, { 112,   7 }, { 100,  20 }, L"Button Types", Win33::StaticStyle::Center ),
    mButton           ( this, { 112,  25 }, { 100,  20 }, L"Button" ),
    mCheckBox1        ( this, { 112,  50 }, { 100,  20 }, L"CheckBox1" ),
    mCheckBox2        ( this, { 112,  70 }, { 100,  20 }, L"CheckBox2" ),
    mRadioButton1     ( this, { 112,  90 }, { 100,  20 }, L"RadioButton1", false, true ),
    mRadioButton2     ( this, { 112, 110 }, { 100,  20 }, L"RadioButton2" ),
    mRadioButton3     ( this, { 112, 130 }, { 100,  20 }, L"RadioButton3", true ),
    mMiscTypes        ( this, { 217,   7 }, { 100,  20 }, L"Misc. Types", Win33::StaticStyle::Center ),
    mGroupBox         ( this, { 217,  25 }, { 100, 150 }, L"GroupBox" )
    {
        setTitle       ( L"ControlsWindow" );
        setMinimizable ( false );
        setMaximizable ( false );
        setResizable   ( false );
        
        mPasswordBox.setText( L"PasswordBox" );
    }
    ~ControlsWindow( ) = default;
    
private:
    Win33::Label            mTextBoxTypes;
    Win33::TextBox          mTextBox;
    Win33::MultilineTextBox mMultilineTextBox;
    Win33::PasswordBox      mPasswordBox;
    
    Win33::Label       mButtonTypes;
    Win33::Button      mButton;
    Win33::CheckBox    mCheckBox1;
    Win33::CheckBox    mCheckBox2;
    Win33::RadioButton mRadioButton1;
    Win33::RadioButton mRadioButton2;
    Win33::RadioButton mRadioButton3;
    
    Win33::Label    mMiscTypes;
    Win33::GroupBox mGroupBox;
};

class ControlsApplication : public Win33::Application {
public:
    ControlsApplication( )
    :
    Win33::Application ( ),
    mControlsWindow    ( )
    {
        mControlsWindow.show( );
    }
    ~ControlsApplication( ) = default;
    
private:
    ControlsWindow mControlsWindow;
};