#pragma once

#include <Win33Application.h>
#include <Win33Window.h>

class FirstWindow : public Win33::Window {
public:
    FirstWindow( )
    :
    Win33::Window( Win33::Window::DefaultPosition, { 640, 480 } )
    {
        setTitle( L"FirstWindow" );
    }
    ~FirstWindow( ) = default;
};

class SecondWindow : public Win33::Window {
public:
    SecondWindow( )
    :
    Win33::Window( Win33::Window::DefaultPosition, { 640, 480 } )
    {
        setTitle( L"SecondWindow" );
    }
    ~SecondWindow( ) = default;
};

class MultipleWindowsApplication : public Win33::Application {
public:
    MultipleWindowsApplication( )
    :
    Win33::Application ( ),
    mFirstWindow       ( ),
    mSecondWindow      ( )
    {
        mFirstWindow.show( );
        mSecondWindow.show( );
    }
    ~MultipleWindowsApplication( ) = default;
    
private:
    FirstWindow  mFirstWindow;
    SecondWindow mSecondWindow;
};