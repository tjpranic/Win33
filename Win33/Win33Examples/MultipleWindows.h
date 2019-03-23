#pragma once

#include <Win33/Application.h>
#include <Win33/Window.h>

class FirstWindow : public Win33::Window {
public:
    FirstWindow( )
    :
    Win33::Window( Win33::Window::DefaultPosition, { 640, 480 } )
    {
        setTitle( L"FirstWindow" );
    }
    FirstWindow            ( const FirstWindow&  other ) = delete;
    FirstWindow            (       FirstWindow&& other ) = delete;
    FirstWindow& operator= ( const FirstWindow&  other ) = delete;
    FirstWindow& operator= (       FirstWindow&& other ) = delete;
    ~FirstWindow           ( )                           = default;
};

class SecondWindow : public Win33::Window {
public:
    SecondWindow( )
    :
    Win33::Window( Win33::Window::DefaultPosition, { 640, 480 } )
    {
        setTitle( L"SecondWindow" );
    }
    SecondWindow            ( const SecondWindow&  other ) = delete;
    SecondWindow            (       SecondWindow&& other ) = delete;
    SecondWindow& operator= ( const SecondWindow&  other ) = delete;
    SecondWindow& operator= (       SecondWindow&& other ) = delete;
    ~SecondWindow           ( )                            = default;
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
    MultipleWindowsApplication            ( const MultipleWindowsApplication&  other ) = delete;
    MultipleWindowsApplication            (       MultipleWindowsApplication&& other ) = delete;
    MultipleWindowsApplication& operator= ( const MultipleWindowsApplication&  other ) = delete;
    MultipleWindowsApplication& operator= (       MultipleWindowsApplication&& other ) = delete;
    ~MultipleWindowsApplication           ( )                                          = default;

private:
    FirstWindow  mFirstWindow;
    SecondWindow mSecondWindow;
};