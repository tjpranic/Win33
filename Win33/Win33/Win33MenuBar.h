#pragma once

#include "Win33Window.h"
#include "Win33Interop.h"

namespace Win33 {
    
    class MenuBar {
    public:
        MenuBar            ( Win33::Window* window );
        MenuBar            ( )                       = delete;
        MenuBar            ( const MenuBar&  other ) = delete;
        MenuBar            (       MenuBar&& other ) = delete;
        MenuBar& operator= ( const MenuBar&  other ) = delete;
        MenuBar& operator= (       MenuBar&& other ) = delete;
        ~MenuBar           ( )                       = default;
        
        friend HMENU Win33::Interop::toHandle( const Win33::MenuBar* menuBar );
        
    private:
        HMENU mHandle;
    };
    
};