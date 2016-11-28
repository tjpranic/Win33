#pragma once

namespace Win33 {
    
    class Point {
    public:
        Point            ( );
        Point            ( int x, int y );
        Point            ( const Point&  other ) = default;
        Point            (       Point&& other );
        Point& operator= ( const Point&  other ) = default;
        Point& operator= (       Point&& other );
        ~Point           ( )                     = default;
        
        int getX( ) const;
        int getY( ) const;
        
    private:
        int mX;
        int mY;
    };
    
};