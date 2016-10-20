#pragma once

namespace Win33 {
    
    class Size {
    public:
        Size  ( );
        Size  ( int width, int height );
        ~Size ( ) = default;
        
        int getWidth( )  const;
        int getHeight( ) const;
        
    private:
        int mWidth;
        int mHeight;
    };
    
};