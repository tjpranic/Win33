#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33TrayIcon.h>

class FirstTrayIconWindow : public Win33::Window {
public:
    FirstTrayIconWindow( )
    :
    Window         ( Win33::DefaultPosition, { 640, 480 } ),
    mFirstTrayIcon ( this, L"TestIcon1.ico", L"FirstTrayIcon" )
    {
        setTitle( L"FirstWindow" );
        
        mFirstTrayIcon.onLeftClick += [&]( ) {
            toggleVisibility( );
        };
        
        mFirstTrayIcon.setTooltip( L"Hello" );
    }
    ~FirstTrayIconWindow( ) = default;
    
private:
    Win33::TrayIcon mFirstTrayIcon;
};

class SecondTrayIconWindow : public Win33::Window {
public:
    SecondTrayIconWindow( )
    :
    Window          ( Win33::DefaultPosition, { 640, 480 } ),
    mSecondTrayIcon ( this, L"TestIcon2.ico", L"SecondTrayIcon" )
    {
        setTitle( L"SecondWindow" );
        
        mSecondTrayIcon.onLeftClick += [&]( ) {
            toggleVisibility( );
        };
    }
    ~SecondTrayIconWindow( ) = default;
    
private:
    Win33::TrayIcon mSecondTrayIcon;
};

class MultipleTrayIconApplication : public Win33::Application {
public:
    MultipleTrayIconApplication( )
    :
    Application   ( ),
    mFirstWindow  ( ),
    mSecondWindow ( )
    {
        mFirstWindow.show( );
        mSecondWindow.show( );
    }
    ~MultipleTrayIconApplication( ) = default;
    
private:
    FirstTrayIconWindow  mFirstWindow;
    SecondTrayIconWindow mSecondWindow;
};