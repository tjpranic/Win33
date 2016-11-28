#include "Win33Point.h"

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
Win33::Point::Point( Point&& other )
:
mX( other.mX ),
mY( other.mY )
{ }
Win33::Point& Win33::Point::operator=( Point&& other ) {
    mX = other.mX;
    mY = other.mY;
    return *this;
}

int Win33::Point::getX( ) const {
    return mX;
}
int Win33::Point::getY( ) const {
    return mY;
}