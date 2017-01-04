#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33ContextMenu.h>
#include <Win33MenuBar.h>
#include <Win33Menu.h>
#include <Win33MenuItem.h>
#include <Win33Separator.h>
#include <Win33PopupBox.h>

class MenusWindow : public Win33::Window {
public:
    MenusWindow( )
    :
    Win33::Window   ( Win33::Window::DefaultPosition, { 640, 480 } ),
    mContextMenu    ( this ),
    mGreet          ( &mContextMenu, L"Say hello" ),
    mGreetSeparator ( &mContextMenu ),
    mEnglish        ( &mContextMenu, L"English" ),
    mSpanish        ( &mContextMenu, L"Spanish" ),
    mMenuBar        ( this ),
    mFileMenu       ( &mMenuBar, L"File" ),
    mNew            ( &mFileMenu, L"New" ),
    mOpen           ( &mFileMenu, L"Open" ),
    mSave           ( &mFileMenu, L"Save" ),
    mQuitSeparator  ( &mFileMenu ),
    mQuit           ( &mFileMenu, L"Quit" ),
    mHelpMenu       ( &mMenuBar, L"Help" ),
    mMiscMenu       ( &mHelpMenu, L"Misc" ),
    mWebsite        ( &mMiscMenu, L"Go to website" ),
    mFeedback       ( &mMiscMenu, L"Leave feedback" ),
    mAboutSeparator ( &mHelpMenu ),
    mAbout          ( &mHelpMenu, L"About" ),
    mLanguage       ( Language::English )
    {
        setTitle( L"MenusWindow" );
        
        mQuit.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            close( );
        };
        
        mWebsite.setEnabled  ( false );
        mFeedback.setEnabled ( false );
        
        mAbout.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            Win33::PopupBox::information( L"This is a test." );
        };
        
        mEnglish.setChecked( true );
        
        mGreet.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            switch( mLanguage ) {
                case Language::English: {
                    Win33::PopupBox::exclamation( L"Hello, world!" );
                    break;
                }
                case Language::Spanish: {
                    Win33::PopupBox::exclamation( L"¡Hola, Mundo!" );
                    break;
                }
                default: {
                    throw std::runtime_error( "Unknown language." );
                }
            }
        };
        mEnglish.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            mLanguage = Language::English;
            mEnglish.setChecked( true );
            mSpanish.setChecked( false );
            mGreet.setText( L"Say hello" );
        };
        mSpanish.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            mLanguage = Language::Spanish;
            mEnglish.setChecked( false );
            mSpanish.setChecked( true );
            mGreet.setText( L"Di hola" );
        };
        
        onRightClick += [&]( Win33::WindowEvents::RightClickData& data ) {
            mContextMenu.show( );
        };
    }
    MenusWindow            ( const MenusWindow&  other ) = delete;
    MenusWindow            (       MenusWindow&& other ) = delete;
    MenusWindow& operator= ( const MenusWindow&  other ) = delete;
    MenusWindow& operator= (       MenusWindow&& other ) = delete;
    ~MenusWindow           ( )                           = default;
    
private:
    Win33::ContextMenu mContextMenu;
    Win33::MenuItem    mGreet;
    Win33::Separator   mGreetSeparator;
    Win33::MenuItem    mEnglish;
    Win33::MenuItem    mSpanish;
    
    Win33::MenuBar   mMenuBar;
    Win33::Menu      mFileMenu;
    Win33::MenuItem  mNew;
    Win33::MenuItem  mOpen;
    Win33::MenuItem  mSave;
    Win33::Separator mQuitSeparator;
    Win33::MenuItem  mQuit;
    Win33::Menu      mHelpMenu;
    Win33::Menu      mMiscMenu;
    Win33::MenuItem  mWebsite;
    Win33::MenuItem  mFeedback;
    Win33::Separator mAboutSeparator;
    Win33::MenuItem  mAbout;
    
    enum class Language : int {
        English,
        Spanish
    };
    Language mLanguage;
};

class MenusApplication : public Win33::Application {
public:
    MenusApplication( )
    :
    Win33::Application ( ),
    mMenusWindow       ( )
    {
        mMenusWindow.show( );
    }
    MenusApplication            ( const MenusApplication&  other ) = delete;
    MenusApplication            (       MenusApplication&& other ) = delete;
    MenusApplication& operator= ( const MenusApplication&  other ) = delete;
    MenusApplication& operator= (       MenusApplication&& other ) = delete;
    ~MenusApplication           ( )                                = default;
    
private:
    MenusWindow mMenusWindow;
};