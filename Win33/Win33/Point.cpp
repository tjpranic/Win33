#include "Point.h"

Win33::Point::Point( )
:
mX( 0 ),
mY( 0 )
{ }
Win33::Point::Point( int x, int y )
:
mX( x ),
mY( y )
{ }

int Win33::Point::getX( ) const {
    return mX;
}
int Win33::Point::getY( ) const {
    return mY;
}