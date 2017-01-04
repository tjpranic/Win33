#pragma once

#include "Win33Window.h"
#include "Win33System.h"
#include "Win33Interop.h"

namespace Win33 {
    
    class ContextMenu {
    public:
        ContextMenu            ( Win33::Window* window );
        ContextMenu            ( )                           = delete;
        ContextMenu            ( const ContextMenu&  other ) = delete;
        ContextMenu            (       ContextMenu&& other ) = delete;
        ContextMenu& operator= ( const ContextMenu&  other ) = delete;
        ContextMenu& operator= (       ContextMenu&& other ) = delete;
        ~ContextMenu           ( )                           = default;
        
        void show( const Win33::Point& position = Win33::System::getCursorPosition( ) );
        
        friend HMENU Win33::Interop::toHandle( const Win33::ContextMenu* contextMenu );
        
    private:
        HMENU          mHandle;
        Win33::Window* mWindow;
    };
    
};