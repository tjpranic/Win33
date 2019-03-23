#pragma once

#include "Misc.h"
#include "Window.h"

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

        void show( const Point& position = Cursor::getPosition( ) );

        operator HMENU( ) const;

    private:
        HMENU   mHandle;
        Window* mWindow;
    };

}