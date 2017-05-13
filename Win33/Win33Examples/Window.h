#pragma once

#include <Win33/Application.h>
#include <Win33/Window.h>

class Window : public Win33::Window {
public:
    Window( )
    :
    Win33::Window( Win33::Window::DefaultPosition, { 640, 480 } )
    {
        setTitle( L"WindowTest" );
    }
    Window            ( const Window&  other ) = delete;
    Window            (       Window&& other ) = delete;
    Window& operator= ( const Window&  other ) = delete;
    Window& operator= (       Window&& other ) = delete;
    ~Window           ( )                      = default;
};

class WindowApplication : public Win33::Application {
public:
    WindowApplication( )
    :
    Win33::Application ( ),
    mWindow            ( )
    {
        mWindow.show( );
    }
    WindowApplication            ( const WindowApplication&  other ) = delete;
    WindowApplication            (       WindowApplication&& other ) = delete;
    WindowApplication& operator= ( const WindowApplication&  other ) = delete;
    WindowApplication& operator= (       WindowApplication&& other ) = delete;
    ~WindowApplication           ( )                                 = default;
    
private:
    Window mWindow;
};