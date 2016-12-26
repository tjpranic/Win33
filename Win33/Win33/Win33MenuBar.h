#pragma once

#include "Win33Window.h"
#include "Win33Menu.h"

namespace Win33 {
    
    class MenuBar {
    public:
        MenuBar            ( Win33::Window* window );
        MenuBar            ( )                       = delete;
        MenuBar            ( const MenuBar&  other ) = delete;
        MenuBar            (       MenuBar&& other ) = default;
        MenuBar& operator= ( const MenuBar&  other ) = delete;
        MenuBar& operator= (       MenuBar&& other ) = default;
        ~MenuBar           ( )                       = default;
        
        Menu& appendMenu( const std::wstring& text );
        
        friend HMENU Win33::Interop::toHandle( const Win33::MenuBar* menuBar );
        
    private:
        int mLastPosition;
        
        HMENU                  mHandle;
        Win33::Window*         mWindow;
        std::list<Win33::Menu> mMenus;
    };
    
};