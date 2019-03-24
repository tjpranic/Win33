#pragma once

#include "Window.h"

namespace Win33 {

    template<class T>
    class Dialog : public Window {
    public:
        Dialog            ( )                      = delete;
        Dialog            ( const Dialog&  other ) = delete;
        Dialog            (       Dialog&& other ) = delete;
        Dialog& operator= ( const Dialog&  other ) = delete;
        Dialog& operator= (       Dialog&& other ) = delete;
        virtual ~Dialog   ( )                      = default;

        T show( ) {
            mParent->setEnabled( false );
            Window::show( );
            auto message = MSG { };
            while( message.message != WM_QUIT ) {
                if( PeekMessage( &message, 0, 0, 0, PM_REMOVE ) > 0 ) {
                    TranslateMessage( &message );
                    DispatchMessage( &message );
                }
                else {
                    Sleep( 10 );
                }
            }
            return mResult;
        }

    protected:
        Dialog(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
                  WindowStyle   style     = WindowStyle::OverlappedWindow,
                  ExWindowStyle exStyle   = ExWindowStyle::None,
            const std::wstring& className = L"WINDOW"
        ):
        Window  ( parent, position, size, style, exStyle, className ),
        mResult ( )
        {
            onClose += [&]( bool& cancelled ) {
                mParent->setEnabled( true );
            };
        }

        T mResult;
    };

}