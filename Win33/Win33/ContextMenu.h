#pragma once

#include "Window.h"
#include "System.h"
#include "Interop.h"

namespace Win33 {
    
    class ContextMenu {
    public:
        ContextMenu            ( Window* window );
        ContextMenu            ( )                           = delete;
        ContextMenu            ( const ContextMenu&  other ) = delete;
        ContextMenu            (       ContextMenu&& other ) = delete;
        ContextMenu& operator= ( const ContextMenu&  other ) = delete;
        ContextMenu& operator= (       ContextMenu&& other ) = delete;
        ~ContextMenu           ( )                           = default;
        
        void show( const Point& position = System::getCursorPosition( ) );
        
        friend HMENU Interop::toHandle( const ContextMenu* contextMenu );
        
    private:
        HMENU   mHandle;
        Window* mWindow;
    };
    
};