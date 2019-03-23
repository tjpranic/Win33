#pragma once

#include "Size.h"
#include "Point.h"

namespace Win33 {

    namespace Monitor {

        int  getWidth( );
        int  getHeight( );
        Size getSize( );

    };

    namespace Cursor {

        Point getPosition( );

    }

}