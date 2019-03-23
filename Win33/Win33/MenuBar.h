#pragma once

#include "Window.h"

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

        operator HMENU( ) const;

    private:
        HMENU mHandle;
    };

}