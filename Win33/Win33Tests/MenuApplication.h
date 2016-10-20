#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33MenuBar.h>

class MenuWindow : public Win33::Window {
public:
    MenuWindow( )
    :
    Window    ( Win33::DefaultPosition, { 640, 480 } ),
    mMenuBar  ( ),
    mFileMenu ( L"&File" ),
    mNew      ( L"&New" ),
    mOpen     ( L"&Open" ),
    mSave     ( L"&Save" ),
    mQuit     ( L"&Quit" )
    {
        setTitle( L"MenuWindow" );
        
        mFileMenu.addMenuItem( &mNew );
        mFileMenu.addMenuItem( &mOpen );
        mFileMenu.addMenuItem( &mSave );
        mFileMenu.addSeparator( );
        mFileMenu.addMenuItem( &mQuit );
        
        mMenuBar.addMenu( &mFileMenu );
        
        setMenuBar( &mMenuBar );
    }
    ~MenuWindow( ) = default;
    
private:
    Win33::MenuBar  mMenuBar;
    Win33::Menu     mFileMenu;
    Win33::MenuItem mNew;
    Win33::MenuItem mOpen;
    Win33::MenuItem mSave;
    Win33::MenuItem mQuit;
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