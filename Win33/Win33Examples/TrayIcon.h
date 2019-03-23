#pragma once

#include <Win33/Application.h>
#include <Win33/Window.h>
#include <Win33/TrayIcon.h>
#include <Win33/Button.h>

#include "Resources.h"

class TrayIconWindow : public Win33::Window {
public:
    TrayIconWindow( )
    :
    Win33::Window ( Win33::Window::DefaultPosition, { 640, 480 } ),
    mAllowExit    ( false ),
    mTrayIcon     ( this, Icons::getTestIcon1( ), L"TrayIcon" ),
    mQuit         ( this, { 515, 407 }, { 100, 25 }, L"Quit" )
    {
        setTitle( L"TrayIconWindow" );

        mTrayIcon.onLeftClick += [&]( const Win33::Point& position ) {
            toggleVisibility( );
        };

        mQuit.setAnchor( Win33::Anchor::RightBottom );
        mQuit.onClick += [&]( ) {
            mAllowExit = true;
            close( );
        };

        onClose += [&]( bool& cancelled ) {
            cancelled = !mAllowExit;
            toggleVisibility( );
        };

        mTrayIcon.setTooltip( L"I'm a tray icon" );
    }
    TrayIconWindow            ( const TrayIconWindow&  other ) = delete;
    TrayIconWindow            (       TrayIconWindow&& other ) = delete;
    TrayIconWindow& operator= ( const TrayIconWindow&  other ) = delete;
    TrayIconWindow& operator= (       TrayIconWindow&& other ) = delete;
    ~TrayIconWindow           ( )                              = default;

private:
    bool mAllowExit;

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
    TrayIconApplication            (       TrayIconApplication&& other ) = delete;
    TrayIconApplication& operator= ( const TrayIconApplication&  other ) = delete;
    TrayIconApplication& operator= (       TrayIconApplication&& other ) = delete;
    ~TrayIconApplication           ( )                                   = default;

private:
    TrayIconWindow  mTrayIconWindow;
};