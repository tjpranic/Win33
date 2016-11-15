#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33Dialog.h>
#include <Win33PopupBox.h>
#include <Win33Button.h>
#include <Win33CheckBox.h>
#include <Win33RadioButton.h>
#include <Win33TextBox.h>
#include <Win33PasswordBox.h>
#include <Win33MultilineTextBox.h>
#include <Win33Label.h>
#include <Win33GroupBox.h>
#include <Win33TrayIcon.h>

class TestDialog : public Win33::Dialog<std::wstring> {
public:
    TestDialog( Win33::Window* parent )
    :
    Dialog<std::wstring>( parent, Win33::DefaultPosition, { 320, 240 } )
    {
        setTitle  ( L"TestDialog" );
        setResult ( L"Hello, world!" );
    }
    ~TestDialog( ) = default;
};

class TestWindow : public Win33::Window {
public:
    TestWindow( )
    :
    Window                ( Win33::DefaultPosition, { 640, 480 } ),
    mTestButton1          ( this, { 400, 395 }, { 100, 25  }, L"Test 1" ),
    mTestButton2          ( this, { 505, 395 }, { 100, 25  }, L"Test 2" ),
    mTestTextBox          ( this, { 400, 365 }, { 100, 25  }, L"Hello" ),
    mTestPasswordBox      ( this, { 505, 365 }, { 100, 25  }, L'x' ),
    mTestCheckBox         ( this, { 400, 345 }, { 100, 15  }, L"Test", false ),
    mTestLabel            ( this, { 505, 345 }, { 50,  15  }, L"Test Label" ),
    mTestMultilineTextBox ( this, { 400, 250 }, { 100, 90  }, Win33::ScrollBar::Vertical ),
    mTestGroupBox         ( this, { 390, 230 }, { 225, 200 }, L"TestGroupBox" ),
    mTestRadioButton1     ( this, { 505, 250 }, { 100, 15  }, L"Test 1", true, true ),
    mTestRadioButton2     ( this, { 505, 270 }, { 100, 15  }, L"Test 2", false ),
    mTestRadioButton3     ( this, { 505, 290 }, { 100, 15  }, L"Test 3", false )
    {
        setTitle       ( L"TestWindow" );
        setMinimumSize ( { 260,  255 } );
        setMaximumSize ( { 1024, 768 } );
        setIcon        ( Win33::Icon( L"TestIcon2.ico" ) );
        
        mTestButton1.setAnchor( Win33::Anchor::RightBottom );
        mTestButton1.addClickHandler(
            [&]( ) {
                Win33::PopupBox::exclamation( mTestTextBox.getText( ), L"TestBox Text" );
            }
        );
        
        mTestButton2.setAnchor( Win33::Anchor::RightBottom );
        mTestButton2.addClickHandler(
            [&]( ) {
                if( mTestPasswordBox.getText( ) == L"password" ) {
                    auto result = TestDialog( this ).show( );
                    Win33::PopupBox::exclamation( result.c_str( ), L"TestDialog Result" );
                }
                else {
                    Win33::PopupBox::exclamation( L"Password incorrect.", L"Access denied" );
                }
            }
        );
        
        mTestTextBox.setAnchor( Win33::Anchor::RightBottom );
        
        mTestPasswordBox.setAnchor( Win33::Anchor::RightBottom );
        
        mTestCheckBox.setAnchor( Win33::Anchor::RightBottom );
        mTestCheckBox.addCheckHandler(
            [&]( Win33::CheckBoxEvents::CheckData& data ) {
                mTestTextBox.setEnabled( !data.isChecked( ) );
            }
        );
        
        mTestLabel.setAnchor( Win33::Anchor::RightBottom );
        mTestLabel.addClickHandler(
            [&]( ) {
                setResizable( !getResizable( ) );
            }
        );
        
        mTestMultilineTextBox.setAnchor( Win33::Anchor::RightBottom );
        
        mTestGroupBox.setAnchor( Win33::Anchor::RightBottom );
        
        mTestRadioButton1.setAnchor( Win33::Anchor::RightBottom );
        mTestRadioButton2.setAnchor( Win33::Anchor::RightBottom );
        mTestRadioButton3.setAnchor( Win33::Anchor::RightBottom );
    }
    ~TestWindow( ) = default;
    
private:
    Win33::Button           mTestButton1;
    Win33::Button           mTestButton2;
    Win33::TextBox          mTestTextBox;
    Win33::PasswordBox      mTestPasswordBox;
    Win33::CheckBox         mTestCheckBox;
    Win33::Label            mTestLabel;
    Win33::MultilineTextBox mTestMultilineTextBox;
    Win33::GroupBox         mTestGroupBox;
    Win33::RadioButton      mTestRadioButton1;
    Win33::RadioButton      mTestRadioButton2;
    Win33::RadioButton      mTestRadioButton3;
};

class TestApplication : public Win33::Application {
public:
    TestApplication( )
    :
    Application( ),
    mTestWindow( )
    {
        mTestWindow.show( );
    }
    ~TestApplication( ) = default;
    
private:
    TestWindow mTestWindow;
};