#pragma once

#include <Win33Application.h>
#include <Win33Window.h>

class FirstWindow : public Win33::Window {
public:
    FirstWindow( )
    :
    Window( Win33::DefaultPosition, { 640, 480 } )
    {
        setTitle( L"FirstWindow" );
    }
    ~FirstWindow( ) = default;
};

class SecondWindow : public Win33::Window {
public:
    SecondWindow( )
    :
    Window( Win33::DefaultPosition, { 640, 480 } )
    {
        setTitle( L"SecondWindow" );
    }
    ~SecondWindow( ) = default;
};

class MultipleWindowApplication : public Win33::Application {
public:
    MultipleWindowApplication( )
    :
    Application   ( ),
    mFirstWindow  ( ),
    mSecondWindow ( )
    {
        mFirstWindow.show( );
        mSecondWindow.show( );
    }
    ~MultipleWindowApplication( ) = default;
    
private:
    FirstWindow  mFirstWindow;
    SecondWindow mSecondWindow;
};