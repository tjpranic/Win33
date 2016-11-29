#pragma once

#include <list>

#include "Win33Point.h"
#include "Win33Window.h"
#include "Win33System.h"

namespace Win33 {
    
    class ContextMenu {
    public:
        ContextMenu            ( );
        ContextMenu            ( const ContextMenu&  other ) = delete;
        ContextMenu            (       ContextMenu&& other );
        ContextMenu& operator= ( const ContextMenu&  other ) = delete;
        ContextMenu& operator= (       ContextMenu&& other );
        ~ContextMenu           ( )                           = default;
        
        void show( Win33::Window* window, const Win33::Point& position = Win33::System::getCursorPosition( ) );
        
        void      appendSeperator ( );
        Menu&     appendMenu      ( const std::wstring& text );
        MenuItem& appendMenuItem  ( const std::wstring& text, bool checkable = false );
        
        HMENU getHandle( ) const;
        
    private:
        int mLastPosition;
        
        HMENU                      mHandle;
        std::list<Win33::Menu>     mMenus;
        std::list<Win33::MenuItem> mMenuItems;
    };
    
};