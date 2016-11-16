#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33MenuBar.h>
#include <Win33ContextMenu.h>
#include <Win33PopupBox.h>

class MenuWindow : public Win33::Window {
public:
    MenuWindow( )
    :
    Window       ( Win33::DefaultPosition, { 640, 480 } ),
    mMenuBar     ( ),
    mContextMenu ( ),
    mLanguage    ( Language::English )
    {
        setTitle( L"MenuWindow" );
        
        auto& fileMenu = mMenuBar.appendMenu( L"&File" );
        fileMenu.appendMenuItem( L"&New" );
        fileMenu.appendMenuItem( L"&Open" );
        fileMenu.appendMenuItem( L"&Save" );
        fileMenu.appendSeparator( );
        auto& quit = fileMenu.appendMenuItem( L"&Quit" );
        
        quit.addClickHandler( [&]( Win33::MenuEvents::ClickData& data ) {
            close( );
        } );
        
        auto& helpMenu = mMenuBar.appendMenu( L"&Help" );
        auto& miscMenu = helpMenu.appendSubMenu( L"&Misc." );
        miscMenu.appendMenuItem( L"Go to website" );
        miscMenu.appendMenuItem( L"Leave feedback" );
        helpMenu.appendSeparator( );
        auto& about = helpMenu.appendMenuItem( L"&About" );
        
        about.addClickHandler( [&]( Win33::MenuEvents::ClickData& data ) {
            Win33::PopupBox::information( L"This is a test." );
        } );
        
        setMenuBar( &mMenuBar );
        
        auto& greet = mContextMenu.appendMenuItem( L"Say hello" );
        mContextMenu.appendSeperator( );
        auto& english = mContextMenu.appendMenuItem( L"English", true );
        auto& espanol = mContextMenu.appendMenuItem( L"Espanol", true  );
        
        english.setChecked( true );
        
        greet.addClickHandler( [&]( Win33::MenuEvents::ClickData& data ) {
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
        } );
        english.addClickHandler( [&]( Win33::MenuEvents::ClickData& data ) {
            mLanguage = Language::English;
            espanol.setChecked( false );
            greet.setText( L"Say hello" );
        } );
        espanol.addClickHandler( [&]( Win33::MenuEvents::ClickData& data ) {
            mLanguage = Language::Espanol;
            english.setChecked( false );
            greet.setText( L"Di hola" );
        } );
        
        setContextMenu( &mContextMenu );
    }
    ~MenuWindow( ) = default;
    
private:
    Win33::MenuBar     mMenuBar;
    Win33::ContextMenu mContextMenu;
    
    enum Language {
        English,
        Espanol
    };
    Language mLanguage;
};

class MenuApplication : public Win33::Application {
public:
    MenuApplication( )
    :
    Application( ),
    mMenuWindow( )
    {
        mMenuWindow.show( );
    }
    ~MenuApplication( ) = default;
    
private:
    MenuWindow mMenuWindow;
};