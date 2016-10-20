#pragma once

namespace Win33 {
    
    class Point {
    public:
        Point  ( );
        Point  ( int x, int y );
        ~Point ( ) = default;
        
        int getX( ) const;
        int getY( ) const;
        
    private:
        int mX;
        int mY;
    };
    
};