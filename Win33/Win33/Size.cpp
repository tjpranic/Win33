#include "Size.h"

namespace Win33 {

    Size::Size( )
    :
    mWidth  ( 0 ),
    mHeight ( 0 )
    { }
    Win33::Size::Size( int width, int height )
    :
    mWidth  ( width ),
    mHeight ( height )
    { }

    int Size::getWidth( ) const {
        return mWidth;
    }
    int Size::getHeight( ) const {
        return mHeight;
    }

}