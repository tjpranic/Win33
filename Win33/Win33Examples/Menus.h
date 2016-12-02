#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33MenuBar.h>
#include <Win33ContextMenu.h>
#include <Win33PopupBox.h>

class MenusWindow : public Win33::Window {
public:
    MenusWindow( )
    :
    Win33::Window ( Win33::Window::DefaultPosition, { 640, 480 } ),
    mMenuBar      ( this ),
    mContextMenu  ( this ),
    mLanguage     ( Language::English )
    {
        setTitle( L"MenusWindow" );
        
        auto& fileMenu = mMenuBar.appendMenu( L"&File" );
        fileMenu.appendMenuItem( L"&New" );
        fileMenu.appendMenuItem( L"&Open" );
        fileMenu.appendMenuItem( L"&Save" );
        fileMenu.appendSeparator( );
        auto& quit = fileMenu.appendMenuItem( L"&Quit" );
        
        quit.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            close( );
        };
        
        auto& helpMenu = mMenuBar.appendMenu( L"&Help" );
        auto& miscMenu = helpMenu.appendSubMenu( L"&Misc." );
        miscMenu.appendMenuItem( L"Go to website" );
        miscMenu.appendMenuItem( L"Leave feedback" );
        helpMenu.appendSeparator( );
        auto& about = helpMenu.appendMenuItem( L"&About" );
        
        about.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            Win33::PopupBox::information( L"This is a test." );
        };
        
        auto& greet = mContextMenu.appendMenuItem( L"Say hello" );
        mContextMenu.appendSeperator( );
        auto& english = mContextMenu.appendMenuItem( L"English", true );
        auto& espanol = mContextMenu.appendMenuItem( L"Espanol", true  );
        
        english.setChecked( true );
        
        greet.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            switch( mLanguage ) {
                case Language::English: {
                    Win33::PopupBox::exclamation( L"Hello, world!" );
                    break;
                }
                case Language::Espanol: {
                    Win33::PopupBox::exclamation( L"¡Hola, Mundo!" );
                    break;
                }
                default: {
                    throw std::runtime_error( "Unknown language." );
                }
            }
        };
        english.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            mLanguage = Language::English;
            english.setChecked( true );
            espanol.setChecked( false );
            greet.setText( L"Say hello" );
        };
        espanol.onClick += [&]( Win33::MenuItemEvents::ClickData& data ) {
            mLanguage = Language::Espanol;
            english.setChecked( false );
            espanol.setChecked( true );
            greet.setText( L"Di hola" );
        };
        
        onRightClick += [&]( ) {
            mContextMenu.show( );
        };
    }
    ~MenusWindow( ) = default;
    
private:
    Win33::MenuBar     mMenuBar;
    Win33::ContextMenu mContextMenu;
    
    enum Language {
        English,
        Espanol
    };
    Language mLanguage;
};

class MenusApplication : public Win33::Application {
public:
    MenusApplication( )
    :
    Win33::Application ( ),
    mMenuWindow        ( )
    {
        mMenuWindow.show( );
    }
    ~MenusApplication( ) = default;
    
private:
    MenusWindow mMenuWindow;
};