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
        
        auto& fileMenu = mMenuBar.addMenu( L"&File" );
        fileMenu.addMenuItem( L"&New" );
        fileMenu.addMenuItem( L"&Open" );
        fileMenu.addMenuItem( L"&Save" );
        fileMenu.addSeparator( );
        auto& quit = fileMenu.addMenuItem( L"&Quit" );
        
        quit.addClickHandler( [&]( Win33::MenuEvents::ClickData& data ) {
            close( );
        } );
        
        auto& helpMenu = mMenuBar.addMenu( L"&Help" );
        auto& miscMenu = helpMenu.addSubMenu( L"&Misc." );
        miscMenu.addMenuItem( L"Go to website" );
        miscMenu.addMenuItem( L"Leave feedback" );
        helpMenu.addSeparator( );
        helpMenu.addMenuItem( L"&About" );
        
        setMenuBar( &mMenuBar );
        
        auto& greet = mContextMenu.addMenuItem( L"Say hello" );
        mContextMenu.addSeperator( );
        auto& english = mContextMenu.addMenuItem( L"English", true );
        auto& espanol = mContextMenu.addMenuItem( L"Espanol", true  );
        
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