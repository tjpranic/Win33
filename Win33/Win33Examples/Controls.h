#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
//...

class ControlsWindow : public Win33::Window {
public:
    ControlsWindow( )
    :
    Win33::Window( Win33::Window::DefaultPosition, { 640, 480 } )
    {
        setTitle( L"ControlsWindow" );
        
        //...
    }
    ~ControlsWindow( ) = default;
    
private:
    //...
};

class ControlsApplication : public Win33::Application {
public:
    ControlsApplication( )
    :
    Win33::Application ( ),
    mControlsWindow    ( )
    {
        mControlsWindow.show( );
    }
    ~ControlsApplication( ) = default;
    
private:
    ControlsWindow mControlsWindow;
};