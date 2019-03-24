#include "Point.h"

namespace Win33 {

    Point::Point( )
    :
    mX( 0 ),
    mY( 0 )
    { }
    Point::Point( int x, int y )
    :
    mX( x ),
    mY( y )
    { }

    int Point::getX( ) const {
        return mX;
    }
    int Point::getY( ) const {
        return mY;
    }

}