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
    HiddenWindow            ( const HiddenWindow&  other ) = delete;
    HiddenWindow            (       HiddenWindow&& other ) = delete;
    HiddenWindow& operator= ( const HiddenWindow&  other ) = delete;
    HiddenWindow& operator= (       HiddenWindow&& other ) = delete;
    ~HiddenWindow           ( )                            = default;
};

class HiddenWindowApplication : public Win33::Application {
public:
    HiddenWindowApplication( )
    :
    Win33::Application ( ),
    mHiddenWindow      ( )
    { }
    HiddenWindowApplication            ( const HiddenWindowApplication&  other ) = delete;
    HiddenWindowApplication            (       HiddenWindowApplication&& other ) = delete;
    HiddenWindowApplication& operator= ( const HiddenWindowApplication&  other ) = delete;
    HiddenWindowApplication& operator= (       HiddenWindowApplication&& other ) = delete;
    ~HiddenWindowApplication           ( )                                       = default;
    
private:
    HiddenWindow mHiddenWindow;
};