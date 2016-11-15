#pragma once

#include <list>

#include "Win33Menu.h"

namespace Win33 {
    
    class Window;
    
    class MenuBar {
    friend class Window;
    public:
        MenuBar( );
        ~MenuBar( ) = default;
        
        Menu& addMenu( const std::wstring& text );
        
    private:
        HMENU           mHandle;
        int             mLastPosition;
        std::list<Menu> mMenus;
    };
    
};