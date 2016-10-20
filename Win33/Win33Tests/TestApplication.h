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
    mTestButton1          ( this, { 400, 375 }, { 100, 25  }, L"Test 1" ),
    mTestButton2          ( this, { 505, 375 }, { 100, 25  }, L"Test 2" ),
    mTestTextBox          ( this, { 400, 345 }, { 100, 25  }, L"Hello" ),
    mTestPasswordBox      ( this, { 505, 345 }, { 100, 25  }, L'x' ),
    mTestCheckBox         ( this, { 400, 325 }, { 100, 15  }, L"Test", false ),
    mTestLabel            ( this, { 505, 325 }, { 50,  15  }, L"Test Label" ),
    mTestMultilineTextBox ( this, { 400, 230 }, { 100, 90  }, Win33::ScrollBar::Vertical ),
    mTestGroupBox         ( this, { 390, 210 }, { 225, 200 }, L"TestGroupBox" ),
    mTestRadioButton1     ( this, { 505, 230 }, { 100, 15  }, L"Test 1", true, true ),
    mTestRadioButton2     ( this, { 505, 250 }, { 100, 15  }, L"Test 2", false ),
    mTestRadioButton3     ( this, { 505, 270 }, { 100, 15  }, L"Test 3", false ),
    mTestMenuBar          ( ),
    mTestMenu1            ( L"Test 1" ),
    mTestMenu1Item1       ( L"Test 2" ),
    mTestMenu1Item2       ( L"Test 3", true ),
    mTestMenu2            ( L"Test 4" ),
    mTestMenu2Item1       ( L"Test 5" ),
    mTestContextMenu      ( ),
    mTestMenu3            ( L"Test 6" ),
    mTestMenu3Item1       ( L"Test 7" ),
    mTestTrayIcon         ( this, Win33::Icon( L"TestIcon1.ico" ), L"TestTrayIcon" )
    {
        setTitle       ( L"TestWindow" );
        setMinimumSize ( { 260,  270 } );
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
        
        mTestMenu1.addMenuItem  ( &mTestMenu1Item1 );
        mTestMenu1.addMenuItem  ( &mTestMenu1Item2 );
        mTestMenu1.addSeparator ( );
        mTestMenu1.addSubMenu   ( &mTestMenu2 );
        mTestMenuBar.addMenu    ( &mTestMenu1 );
        
        mTestMenu2.addMenuItem( &mTestMenu2Item1 );
        
        setMenuBar( &mTestMenuBar );
        
        mTestMenu1Item1.addClickHandler(
            [&]( Win33::MenuEvents::ClickData& data ) {
                close( );
            }
        );
        mTestMenu1Item2.addClickHandler(
            [&]( Win33::MenuEvents::ClickData& data ) {
                mTestMenu2.setEnabled      ( !data.isChecked( ) );
                mTestMenu1Item1.setEnabled ( !data.isChecked( ) );
            }
        );
        mTestMenu2Item1.addClickHandler(
            [&]( Win33::MenuEvents::ClickData& data ) {
                Win33::PopupBox::exclamation( mTestMenu2.getText( ),      L"TestMenu2 text"      );
                Win33::PopupBox::exclamation( mTestMenu1Item1.getText( ), L"TestMenu1Item1 text" );
            }
        );
        
        mTestMenu1.setText      ( L"butts" );
        mTestMenu1Item1.setText ( L"wat" );
        mTestMenu2Item1.setText ( L"fak" );
        mTestMenu2.setText      ( L"ASS" );
        
        mTestContextMenu.addMenu ( &mTestMenu3 );
        mTestMenu3.addMenuItem   ( &mTestMenu3Item1 );
        
        setContextMenu( &mTestContextMenu );
        
        mTestMenu3.setText      ( L"bepis" );
        mTestMenu3Item1.setText ( L"benis" );
        
        mTestTrayIcon.setContextMenu( &mTestContextMenu );
        
        mTestTrayIcon.addLeftClickHandler(
            [&]( ) {
                toggleVisibility( );
            }
        );
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
    Win33::MenuBar          mTestMenuBar;
    Win33::Menu             mTestMenu1;
    Win33::MenuItem         mTestMenu1Item1;
    Win33::MenuItem         mTestMenu1Item2;
    Win33::Menu             mTestMenu2;
    Win33::MenuItem         mTestMenu2Item1;
    Win33::ContextMenu      mTestContextMenu;
    Win33::Menu             mTestMenu3;
    Win33::MenuItem         mTestMenu3Item1;
    Win33::TrayIcon         mTestTrayIcon;
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