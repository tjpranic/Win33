#include "Size.h"

Win33::Size::Size( )
:
mWidth  ( 0 ),
mHeight ( 0 )
{ }
Win33::Size::Size( int width, int height )
:
mWidth  ( width ),
mHeight ( height )
{ }

int Win33::Size::getWidth( ) const {
    return mWidth;
}
int Win33::Size::getHeight( ) const {
    return mHeight;
}