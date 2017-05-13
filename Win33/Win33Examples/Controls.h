#pragma once

#include <iostream>

#include <Win33/Application.h>
#include <Win33/Window.h>
#include <Win33/Label.h>
#include <Win33/TextBox.h>
#include <Win33/MultilineTextBox.h>
#include <Win33/PasswordBox.h>
#include <Win33/Button.h>
#include <Win33/CheckBox.h>
#include <Win33/RadioButton.h>
#include <Win33/GroupBox.h>
#include <Win33/ComboBox.h>
#include <Win33/DropDown.h>
#include <Win33/ListBox.h>
#include <Win33/MultiSelectListBox.h>
#include <Win33/BitfieldOperators.h>

class ControlsWindow : public Win33::Window {
public:
    ControlsWindow( )
    :
    Win33::Window       ( Win33::Window::DefaultPosition, { 545, 220 } ),
    mTextBoxTypes       ( this, {   7,   7 }, { 100,  20 }, L"TextBox Types", Win33::StaticStyle::Center ),
    mTextBox            ( this, {   7,  25 }, { 100,  20 }, L"TextBox" ),
    mMultilineTextBox   ( this, {   7,  50 }, { 100, 100 }, L"MultilineTextBox", Win33::EditStyle::AutoVerticalScroll | Win33::WindowStyle::VerticalScroll ),
    mPasswordBox        ( this, {   7, 155 }, { 100,  20 } ),
    mButtonTypes        ( this, { 112,   7 }, { 100,  20 }, L"Button Types", Win33::StaticStyle::Center ),
    mButton             ( this, { 112,  25 }, { 100,  20 }, L"Button" ),
    mCheckBox1          ( this, { 112,  50 }, { 100,  20 }, L"CheckBox 1" ),
    mCheckBox2          ( this, { 112,  70 }, { 100,  20 }, L"CheckBox 2" ),
    mRadioButton1       ( this, { 112,  90 }, { 100,  20 }, L"RadioButton 1", false, true ),
    mRadioButton2       ( this, { 112, 110 }, { 100,  20 }, L"RadioButton 2" ),
    mRadioButton3       ( this, { 112, 130 }, { 100,  20 }, L"RadioButton 3", true ),
    mMiscTypes          ( this, { 217,   7 }, { 100,  20 }, L"Misc. Types", Win33::StaticStyle::Center ),
    mGroupBox           ( this, { 217,  25 }, { 100, 150 }, L"GroupBox" ),
    mComboBoxTypes      ( this, { 323,   7 }, { 100,  20 }, L"ComboBox Types", Win33::StaticStyle::Center ),
    mComboBox           ( this, { 323,  25 }, { 100,  80 }, { L"ComboBox", L"Option 1", L"Option 2", L"Option 3" } ),
    mDropDown1          ( this, { 323, 105 }, { 100,  80 }, { L"DropDown 1", L"Option 1", L"Option 2", L"Option 3" } ),
    mDropDown2          ( this, { 323, 130 }, { 100,  80 }, { L"DropDown 2", L"Option 1", L"Option 2", L"Option 3" }, true ),
    mListBoxTypes       ( this, { 428,   7 }, { 100,  20 }, L"ListBox Types", Win33::StaticStyle::Center ),
    mListBox            ( this, { 428,  25 }, {  95,  80 }, { L"ListBox", L"Option 1", L"Option 2", L"Option 3" } ),
    mMultiSelectListBox ( this, { 428,  85 }, {  95,  80 }, { L"MultiSelectListBox", L"Option 1", L"Option 2", L"Option 3" } )
    {
        setTitle       ( L"ControlsWindow" );
        setMinimizable ( false );
        setMaximizable ( false );
        setResizable   ( false );
        
        mPasswordBox.setText( L"PasswordBox" );
        
        mComboBox.setSelection  ( 0 );
        mDropDown1.setSelection ( 0 );
        mDropDown2.setSelection ( 0 );
        
        mListBox.setSelection( 0 );
        
        mMultiSelectListBox.setSelection( { 0, 1 } );
    }
    ControlsWindow            ( const ControlsWindow&  other ) = delete;
    ControlsWindow            (       ControlsWindow&& other ) = delete;
    ControlsWindow& operator= ( const ControlsWindow&  other ) = delete;
    ControlsWindow& operator= (       ControlsWindow&& other ) = delete;
    ~ControlsWindow           ( )                              = default;
    
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
    
    Win33::Label    mComboBoxTypes;
    Win33::ComboBox mComboBox;
    Win33::DropDown mDropDown1;
    Win33::DropDown mDropDown2;
    
    Win33::Label              mListBoxTypes;
    Win33::ListBox            mListBox;
    Win33::MultiSelectListBox mMultiSelectListBox;
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
    ControlsApplication            ( const ControlsApplication&  other ) = delete;
    ControlsApplication            (       ControlsApplication&& other ) = delete;
    ControlsApplication& operator= ( const ControlsApplication&  other ) = delete;
    ControlsApplication& operator= (       ControlsApplication&& other ) = delete;
    ~ControlsApplication           ( )                                   = default;
    
private:
    ControlsWindow mControlsWindow;
};