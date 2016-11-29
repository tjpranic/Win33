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
            mResult = std::move( other._result );
        }
        Dialog& operator=( const Dialog&  other ) = delete;
        Dialog& operator=(       Dialog&& other ) {
            Window::operator=( std::move( other ) );
            mResult = std::move( other._result );
            return *this;
        }
        virtual ~Dialog( ) = default;
        
        T show( ) {
            getParent( )->setEnabled( false );
            Win33::Window::show( );
            MSG m = { };
            while( m.message != WM_QUIT ) {
                if( PeekMessage( &m, 0, 0, 0, PM_REMOVE ) > 0 ) {
                    TranslateMessage( &m );
                    DispatchMessage( &m );
                }
                else {
                    SendMessage( m.hwnd, WM_IDLE, 0, 0 );
                }
            }
            return mResult;
        }
        
        const T& getResult( ) const {
            return mResult;
        }
        
        void setResult( const T& result ) {
            mResult = result;
        }
        
    protected:
        Dialog(
                  Win33::Window*              parent,
            const Win33::Point&               position,
            const Win33::Size&                size,
                  Win33::WindowStyle::Type    style   = Win33::WindowStyle::OverlappedWindow,
                  Win33::ExWindowStyle::Type  exStyle = Win33::ExWindowStyle::NoExWindowStyle
        ):
        Window  ( parent, position, size, style, exStyle ),
        mResult ( )
        {
            close.addHandler( [&]( ) {
                getParent( )->setEnabled( true );
            } );
        }
        
    private:
        T mResult;
    };
    
};