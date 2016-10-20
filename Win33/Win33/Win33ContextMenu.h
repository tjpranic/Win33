#pragma once

#include "Win33Menu.h"
#include "Win33Point.h"
#include "Win33Window.h"

namespace Win33 {
    
    class ContextMenu {
    public:
        ContextMenu( );
        ~ContextMenu( ) = default;
        
        void show( Window* window, const Point& position );
        
        void addMenu( Menu* menu );
        
    private:
        static int generatePosition( );
        
        HMENU mHandle;
    };
    
};