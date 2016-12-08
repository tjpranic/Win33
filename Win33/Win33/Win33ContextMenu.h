#pragma once

#include "Win33Menu.h"
#include "Win33Window.h"
#include "Win33System.h"

namespace Win33 {
    
    class ContextMenu {
    public:
        ContextMenu            ( Win33::Window* window );
        ContextMenu            ( const ContextMenu&  other ) = delete;
        ContextMenu            (       ContextMenu&& other );
        ContextMenu& operator= ( const ContextMenu&  other ) = delete;
        ContextMenu& operator= (       ContextMenu&& other );
        ~ContextMenu           ( )                           = default;
        
        void show( const Win33::Point& position = Win33::System::getCursorPosition( ) );
        
        void      appendSeperator ( );
        Menu&     appendMenu      ( const std::wstring& text );
        MenuItem& appendMenuItem  ( const std::wstring& text );
        
        friend HMENU Win33::Interop::toHandle( Win33::ContextMenu* contextMenu );
        
    private:
        int mLastPosition;
        
        HMENU                      mHandle;
        Win33::Window*             mWindow;
        std::list<Win33::Menu>     mMenus;
        std::list<Win33::MenuItem> mMenuItems;
    };
    
};