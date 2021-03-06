#pragma once

#include <Win33/Application.h>
#include <Win33/Window.h>
#include <Win33/TrayIcon.h>

#include "Resources.h"

class FirstTrayIconWindow : public Win33::Window {
public:
    FirstTrayIconWindow( )
    :
    Win33::Window  ( Win33::Window::DefaultPosition, { 640, 480 } ),
    mFirstTrayIcon ( this, Icons::getTestIcon1( ), L"FirstTrayIcon" )
    {
        setTitle( L"FirstWindow" );

        mFirstTrayIcon.onLeftClick += [&]( const Win33::Point& point ) {
            toggleVisibility( );
        };

        mFirstTrayIcon.setTooltip( L"Hello" );
    }
    FirstTrayIconWindow            ( const FirstTrayIconWindow&  other ) = delete;
    FirstTrayIconWindow            (       FirstTrayIconWindow&& other ) = delete;
    FirstTrayIconWindow& operator= ( const FirstTrayIconWindow&  other ) = delete;
    FirstTrayIconWindow& operator= (       FirstTrayIconWindow&& other ) = delete;
    ~FirstTrayIconWindow           ( )                                   = default;

private:
    Win33::TrayIcon mFirstTrayIcon;
};

class SecondTrayIconWindow : public Win33::Window {
public:
    SecondTrayIconWindow( )
    :
    Win33::Window   ( Win33::Window::DefaultPosition, { 640, 480 } ),
    mSecondTrayIcon ( this, Icons::getTestIcon2( ), L"SecondTrayIcon" )
    {
        setTitle( L"SecondWindow" );

        mSecondTrayIcon.onLeftClick += [&]( const Win33::Point& position ) {
            toggleVisibility( );
        };
    }
    SecondTrayIconWindow            ( const SecondTrayIconWindow&  other ) = delete;
    SecondTrayIconWindow            (       SecondTrayIconWindow&& other ) = delete;
    SecondTrayIconWindow& operator= ( const SecondTrayIconWindow&  other ) = delete;
    SecondTrayIconWindow& operator= (       SecondTrayIconWindow&& other ) = delete;
    ~SecondTrayIconWindow           ( )                                    = default;
    
private:
    Win33::TrayIcon mSecondTrayIcon;
};

class MultipleTrayIconsApplication : public Win33::Application {
public:
    MultipleTrayIconsApplication( )
    :
    Win33::Application ( ),
    mFirstWindow       ( ),
    mSecondWindow      ( )
    {
        mFirstWindow.show( );
        mSecondWindow.show( );
    }
    MultipleTrayIconsApplication            ( const MultipleTrayIconsApplication&  other ) = delete;
    MultipleTrayIconsApplication            (       MultipleTrayIconsApplication&& other ) = delete;
    MultipleTrayIconsApplication& operator= ( const MultipleTrayIconsApplication&  other ) = delete;
    MultipleTrayIconsApplication& operator= (       MultipleTrayIconsApplication&& other ) = delete;
    ~MultipleTrayIconsApplication           ( )                                            = default;

private:
    FirstTrayIconWindow  mFirstWindow;
    SecondTrayIconWindow mSecondWindow;
};