#pragma once

#include "Window.h"
#include "Interop.h"

namespace Win33 {
    
    class MenuBar {
    public:
        MenuBar            ( Window* window );
        MenuBar            ( )                       = delete;
        MenuBar            ( const MenuBar&  other ) = delete;
        MenuBar            (       MenuBar&& other ) = delete;
        MenuBar& operator= ( const MenuBar&  other ) = delete;
        MenuBar& operator= (       MenuBar&& other ) = delete;
        ~MenuBar           ( )                       = default;
        
        friend HMENU Interop::toHandle( MenuBar* menuBar );
        
    private:
        HMENU mHandle;
    };
    
};