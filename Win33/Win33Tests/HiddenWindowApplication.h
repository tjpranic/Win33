#pragma once

#include <Win33Application.h>
#include <Win33Window.h>

class HiddenWindow : public Win33::Window {
public:
    HiddenWindow( )
    :
    Window( Win33::DefaultPosition, { 640, 480 }, Win33::WindowStyle::Popup, Win33::ExWindowStyle::ToolWindow )
    {
        setTitle( L"HiddenWindow" );
    }
    ~HiddenWindow( ) = default;
};

class HiddenWindowApplication : public Win33::Application {
public:
    HiddenWindowApplication( )
    :
    Application   ( ),
    mHiddenWindow ( )
    { }
    ~HiddenWindowApplication( ) = default;
    
private:
    HiddenWindow mHiddenWindow;
};