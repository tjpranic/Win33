#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33TrayIcon.h>

class FirstWindow : public Win33::Window {
public:
    FirstWindow( )
    :
    Window         ( Win33::DefaultPosition, { 640, 480 } ),
    mFirstTrayIcon ( this, Win33::Icon( L"TestIcon1.ico" ), L"FirstTrayIcon" )
    {
        setTitle( L"FirstWindow" );
        
        mFirstTrayIcon.leftClick.addHandler(
            [&]( ) {
                toggleVisibility( );
            }
        );
    }
    ~FirstWindow( ) = default;
    
private:
    Win33::TrayIcon mFirstTrayIcon;
};

class SecondWindow : public Win33::Window {
public:
    SecondWindow( )
    :
    Window          ( Win33::DefaultPosition, { 640, 480 } ),
    mSecondTrayIcon ( this, Win33::Icon( L"TestIcon2.ico" ), L"SecondTrayIcon" )
    {
        setTitle( L"SecondWindow" );
        
        mSecondTrayIcon.leftClick.addHandler(
            [&]( ) {
                toggleVisibility( );
            }
        );
    }
    ~SecondWindow( ) = default;
    
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
    FirstWindow  mFirstWindow;
    SecondWindow mSecondWindow;
};