#pragma once

#include "Win33Window.h"

namespace Win33 {
    
    template<class T>
    class Dialog : public Window {
    public:
        Dialog( )                = delete;
        Dialog( Dialog&  other ) = default;
        Dialog( Dialog&& other )
        :
        Window( std::move( other ) )
        {
            mResult = std::move( other._result );
        }
        Dialog& operator=( Dialog&  other ) = default;
        Dialog& operator=( Dialog&& other ) {
            Window::operator=( std::move( other ) );
            mResult = std::move( other._result );
            return *this;
        }
        virtual ~Dialog( ) = default;
        
        T show( ) {
            getParent( ).setEnabled( false );
            Window::show( );
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
                  Window*              parent,
            const Point&               position,
            const Size&                size,
                  WindowStyle::Type    style   = WindowStyle::OverlappedWindow,
                  ExWindowStyle::Type  exStyle = ExWindowStyle::NoExWindowStyle
        ):
        Window  ( parent, position, size, style, exStyle ),
        mResult ( )
        {
            addCloseHandler(
                [&]( ) {
                    getParent( ).setEnabled( true );
                }
            );
        }
        
    private:
        T mResult;
    };
    
};