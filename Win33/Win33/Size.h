#pragma once

namespace Win33 {

    class Size {
    public:
        Size            ( );
        Size            ( int width, int height );
        Size            ( const Size&  other ) = default;
        Size            (       Size&& other ) = default;
        Size& operator= ( const Size&  other ) = default;
        Size& operator= (       Size&& other ) = default;
        ~Size           ( )                    = default;

        int getWidth( )  const;
        int getHeight( ) const;

    private:
        int mWidth;
        int mHeight;
    };

}