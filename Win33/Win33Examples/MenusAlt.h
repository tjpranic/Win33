#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33ContextMenuAlt.h>
#include <Win33MenuBarAlt.h>
#include <Win33PopupBox.h>

class MenusAltWindow : public Win33::Window {
public:
    MenusAltWindow( )
    :
    Win33::Window( Win33::Window::DefaultPosition, { 640, 480 } )
    {
        setTitle( L"MenusAltWindow" );
        
        //...
    }
    MenusAltWindow            ( const MenusAltWindow&  other ) = delete;
    MenusAltWindow            (       MenusAltWindow&& other ) = default;
    MenusAltWindow& operator= ( const MenusAltWindow&  other ) = delete;
    MenusAltWindow& operator= (       MenusAltWindow&& other ) = default;
    ~MenusAltWindow           ( )                              = default;
    
private:
    //...
};

class MenusAltApplication : public Win33::Application {
public:
    MenusAltApplication( )
    :
    Win33::Application ( ),
    mMenusAltWindow    ( )
    {
        mMenusAltWindow.show( );
    }
    MenusAltApplication            ( const MenusAltApplication&  other ) = delete;
    MenusAltApplication            (       MenusAltApplication&& other ) = default;
    MenusAltApplication& operator= ( const MenusAltApplication&  other ) = delete;
    MenusAltApplication& operator= (       MenusAltApplication&& other ) = default;
    ~MenusAltApplication           ( )                                = default;
    
private:
    MenusAltWindow mMenusAltWindow;
};