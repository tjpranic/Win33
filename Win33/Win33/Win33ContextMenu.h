#pragma once

#include <list>

#include "Win33Point.h"
#include "Win33Window.h"

namespace Win33 {
    
    class ContextMenu {
    public:
        ContextMenu            ( );
        ContextMenu            ( const ContextMenu&  other ) = delete;
        ContextMenu            (       ContextMenu&& other );
        ContextMenu& operator= ( const ContextMenu&  other ) = delete;
        ContextMenu& operator= (       ContextMenu&& other );
        ~ContextMenu           ( )                           = default;
        
        void show( Win33::Window* window, const Point& position );
        
        void      appendSeperator ( );
        Menu&     appendMenu      ( const std::wstring& text );
        MenuItem& appendMenuItem  ( const std::wstring& text, bool checkable = false );
        
    private:
        HMENU               mHandle;
        int                 mLastPosition;
        std::list<Menu>     mMenus;
        std::list<MenuItem> mMenuItems;
    };
    
};