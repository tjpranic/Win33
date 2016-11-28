#include "Win33Size.h"

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
Win33::Size::Size( Size&& other )
:
mWidth  ( other.mWidth  ),
mHeight ( other.mHeight )
{ }
Win33::Size& Win33::Size::operator=( Size&& other ) {
    mWidth  = other.mWidth;
    mHeight = other.mHeight;
    return *this;
}

int Win33::Size::getWidth( ) const {
    return mWidth;
}
int Win33::Size::getHeight( ) const {
    return mHeight;
}