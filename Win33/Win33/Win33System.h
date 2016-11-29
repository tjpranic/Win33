#pragma once

#include "Win33Size.h"
#include "Win33Point.h"

namespace Win33 {
    
    namespace System {
        
        int         getMonitorWidth( );
        int         getMonitorHeight( );
        Win33::Size getMonitorSize( );
        
        Win33::Point getCursorPosition( );
    };
    
};