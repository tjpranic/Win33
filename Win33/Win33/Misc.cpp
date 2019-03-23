#include "Misc.h"

#include <Windows.h>

namespace Win33 {

    namespace Monitor {

        int getWidth( ) {
            return GetSystemMetrics( SM_CXSCREEN );
        }
        int getHeight( ) {
            return GetSystemMetrics( SM_CYSCREEN );
        }
        Size getSize( ) {
            return { GetSystemMetrics( SM_CXSCREEN ), GetSystemMetrics( SM_CYSCREEN ) };
        }

    }

    namespace Cursor {

        Point getPosition( ) {
            POINT p = { };
            GetCursorPos( &p );
            return { p.x, p.y };
        }

    }

}