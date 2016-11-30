#pragma once

#include "Win33Menu.h"
#include "Win33Interop.h"

namespace Win33 {
    
    class MenuBar {
    public:
        MenuBar            ( );
        MenuBar            ( const MenuBar&  other ) = delete;
        MenuBar            (       MenuBar&& other );
        MenuBar& operator= ( const MenuBar&  other ) = delete;
        MenuBar& operator= (       MenuBar&& other );
        ~MenuBar           ( )                       = default;
        
        Menu& appendMenu( const std::wstring& text );
        
        friend HMENU Win33::Interop::menuBarToHandle( Win33::MenuBar* menuBar );
        
    private:
        int mLastPosition;
        
        HMENU                  mHandle;
        std::list<Win33::Menu> mMenus;
    };
    
};