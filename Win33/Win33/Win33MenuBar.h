#pragma once

#include <list>

#include "Win33Menu.h"

namespace Win33 {
    
    class Window;
    
    class MenuBar {
    friend class Window;
    public:
        MenuBar            ( );
        MenuBar            ( const MenuBar&  other ) = delete;
        MenuBar            (       MenuBar&& other );
        MenuBar& operator= ( const MenuBar&  other ) = delete;
        MenuBar& operator= (       MenuBar&& other );
        ~MenuBar           ( )                       = default;
        
        Menu& appendMenu( const std::wstring& text );
        
    private:
        HMENU mHandle;
        int   mLastPosition;
        
        std::list<Menu> mMenus;
    };
    
};