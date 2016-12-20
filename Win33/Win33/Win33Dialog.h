#pragma once

#include "Win33Window.h"

namespace Win33 {
    
    template<class T>
    class Dialog : public Window {
    public:
        Dialog( )                      = delete;
        Dialog( const Dialog&  other ) = delete;
        Dialog(       Dialog&& other )
        :
        Window( std::move( other ) )
        {
            mResult = std::move( other.mResult );
        }
        Dialog& operator=( const Dialog&  other ) = delete;
        Dialog& operator=(       Dialog&& other ) {
            Window::operator=( std::move( other ) );
            mResult = std::move( other.mResult );
            return *this;
        }
        virtual ~Dialog( ) = default;
        
        T show( ) {
            mParent->setEnabled( false );
            Win33::Window::show( );
            auto m = MSG { };
            while( m.message != WM_QUIT ) {
                if( PeekMessage( &m, 0, 0, 0, PM_REMOVE ) > 0 ) {
                    TranslateMessage( &m );
                    DispatchMessage( &m );
                }
                else {
                    Sleep( 10 );
                }
            }
            return mResult;
        }
        
    protected:
        Dialog(
                  Win33::Window*       parent,
            const Win33::Point&        position,
            const Win33::Size&         size,
                  Win33::WindowStyle   style   = Win33::WindowStyle::OverlappedWindow,
                  Win33::ExWindowStyle exStyle = Win33::ExWindowStyle::NoExWindowStyle
        ):
        Window  ( parent, position, size, style, exStyle ),
        mResult ( )
        {
            onClose += [&]( ) {
                mParent->setEnabled( true );
            };
        }
        
        T mResult;
    };
    
};