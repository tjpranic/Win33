#pragma once

#include "Win33Menu.h"
#include "Win33System.h"
#include "Win33Interop.h"

namespace Win33 {
    
    class ContextMenu {
    public:
        ContextMenu            ( );
        ContextMenu            ( const ContextMenu&  other ) = delete;
        ContextMenu            (       ContextMenu&& other );
        ContextMenu& operator= ( const ContextMenu&  other ) = delete;
        ContextMenu& operator= (       ContextMenu&& other );
        ~ContextMenu           ( )                           = default;
        
        void show( const Win33::Point& position = Win33::System::getCursorPosition( ) );
        
        void      appendSeperator ( );
        Menu&     appendMenu      ( const std::wstring& text );
        MenuItem& appendMenuItem  ( const std::wstring& text, bool checkable = false );
        
        friend HMENU Win33::Interop::contextMenuToHandle( Win33::ContextMenu* contextMenu );
        
    private:
        int mLastPosition;
        
        HMENU                      mHandle;
        std::list<Win33::Menu>     mMenus;
        std::list<Win33::MenuItem> mMenuItems;
    };
    
};