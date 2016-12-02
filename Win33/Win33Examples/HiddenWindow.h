#pragma once

#include <Win33Application.h>
#include <Win33Window.h>

class HiddenWindow : public Win33::Window {
public:
    HiddenWindow( )
    :
    Win33::Window( Win33::Window::DefaultPosition, { 640, 480 }, Win33::WindowStyle::Popup, Win33::ExWindowStyle::ToolWindow )
    {
        setTitle( L"HiddenWindowTest" );
    }
    ~HiddenWindow( ) = default;
};

class HiddenWindowApplication : public Win33::Application {
public:
    HiddenWindowApplication( )
    :
    Win33::Application ( ),
    mHiddenWindow      ( )
    { }
    ~HiddenWindowApplication( ) = default;
    
private:
    HiddenWindow mHiddenWindow;
};