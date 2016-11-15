#pragma once

#include <list>

#include "Win33Point.h"
#include "Win33Window.h"

namespace Win33 {
    
    class ContextMenu {
    public:
        ContextMenu( );
        ~ContextMenu( ) = default;
        
        void show( Window* window, const Point& position );
        
        void      addSeperator ( );
        Menu&     addMenu      ( const std::wstring& text );
        MenuItem& addMenuItem  ( const std::wstring& text, bool checkable = false );
        
    private:
        HMENU mHandle;
        int   mLastPosition;
        
        std::list<std::pair<int, Menu>>     mMenus;
        std::list<std::pair<int, MenuItem>> mMenuItems;
    };
    
};