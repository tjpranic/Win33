#pragma once

#include "Size.h"
#include "Point.h"

namespace Win33 {
    
    namespace System {
        
        int   getMonitorWidth( );
        int   getMonitorHeight( );
        Size  getMonitorSize( );
        Point getCursorPosition( );
        
    };
    
};