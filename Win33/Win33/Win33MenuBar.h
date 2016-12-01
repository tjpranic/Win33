#pragma once

#include "Win33Menu.h"

namespace Win33 {
    
    class MenuBar {
    public:
        MenuBar            ( Win33::Window* window );
        MenuBar            ( const MenuBar&  other ) = delete;
        MenuBar            (       MenuBar&& other );
        MenuBar& operator= ( const MenuBar&  other ) = delete;
        MenuBar& operator= (       MenuBar&& other );
        ~MenuBar           ( )                       = default;
        
        Menu& appendMenu( const std::wstring& text );
        
        friend HMENU Win33::Interop::toHandle( Win33::MenuBar* menuBar );
        
    private:
        int mLastPosition;
        
        HMENU                  mHandle;
        Win33::Window*         mWindow;
        std::list<Win33::Menu> mMenus;
    };
    
};