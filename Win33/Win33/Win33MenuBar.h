#pragma once

#include <list>

#include "Win33Menu.h"

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
        
        HMENU getHandle( ) const;
        
    private:
        int mLastPosition;
        
        HMENU                  mHandle;
        std::list<Win33::Menu> mMenus;
    };
    
};