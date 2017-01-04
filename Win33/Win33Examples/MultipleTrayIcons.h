#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33TrayIcon.h>

const Win33::Icon TestIcon1 = Win33::Icon( L"TestIcon1.ico" );
const Win33::Icon TestIcon2 = Win33::Icon( L"TestIcon2.ico" );

class FirstTrayIconWindow : public Win33::Window {
public:
    FirstTrayIconWindow( )
    :
    Win33::Window  ( Win33::Window::DefaultPosition, { 640, 480 } ),
    mFirstTrayIcon ( this, &TestIcon1, L"FirstTrayIcon" )
    {
        setTitle( L"FirstWindow" );
        
        mFirstTrayIcon.onLeftClick += [&]( Win33::TrayIconEvents::LeftClickData& data ) {
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
    mSecondTrayIcon ( this, &TestIcon2, L"SecondTrayIcon" )
    {
        setTitle( L"SecondWindow" );
        
        mSecondTrayIcon.onLeftClick += [&]( Win33::TrayIconEvents::LeftClickData& data ) {
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