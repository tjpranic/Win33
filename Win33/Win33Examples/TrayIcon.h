#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33TrayIcon.h>
#include <Win33Button.h>

const Win33::Icon TrayIcon = Win33::Icon( L"TestIcon1.ico" );

class TrayIconWindow : public Win33::Window {
public:
    TrayIconWindow( )
    :
    Win33::Window ( Win33::Window::DefaultPosition, { 640, 480 } ),
    mTrayIcon     ( this, &TrayIcon, L"TrayIcon" ),
    mQuit         ( this, { }, { }, L"Quit" )
    {
        setTitle( L"TrayIconWindow" );
        
        onClose += [&]( Win33::WindowEvents::CloseData& data ) {
            data.setCancelled( true );
            toggleVisibility( );
        };
        
        mTrayIcon.onLeftClick += [&]( Win33::TrayIconEvents::LeftClickData& data ) {
            toggleVisibility( );
        };
        
        mTrayIcon.setTooltip( L"I'm a tray icon" );
    }
    TrayIconWindow            ( const TrayIconWindow&  other ) = delete;
    TrayIconWindow            (       TrayIconWindow&& other ) = default;
    TrayIconWindow& operator= ( const TrayIconWindow&  other ) = delete;
    TrayIconWindow& operator= (       TrayIconWindow&& other ) = default;
    ~TrayIconWindow           ( )                              = default;
    
private:
    Win33::TrayIcon mTrayIcon;
    Win33::Button   mQuit;
};

class TrayIconApplication : public Win33::Application {
public:
    TrayIconApplication( )
    :
    Win33::Application ( ),
    mTrayIconWindow    ( )
    {
        mTrayIconWindow.show( );
    }
    TrayIconApplication            ( const TrayIconApplication&  other ) = delete;
    TrayIconApplication            (       TrayIconApplication&& other ) = default;
    TrayIconApplication& operator= ( const TrayIconApplication&  other ) = delete;
    TrayIconApplication& operator= (       TrayIconApplication&& other ) = default;
    ~TrayIconApplication           ( )                                   = default;
    
private:
    TrayIconWindow  mTrayIconWindow;
};