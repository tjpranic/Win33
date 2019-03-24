#include "Control.h"

#include "Error.h"

namespace Win33 {

    Control::Control(
        const std::wstring& className,
              Window*       parent,
        const Point&        position,
        const Size&         size,
              WindowStyle   style,
              ExWindowStyle exStyle
    ):
    Window  ( parent, position, size, style, exStyle, className ),
    mAnchor ( Anchor::TopLeft )
    {
        ASSERT_TRUE( parent != nullptr, L"parent cannot be null." );
        parent->onResize += [&]( const Size& size ) {
            const auto dx = size.getWidth( )  - mParent->getInitialSize( ).getWidth( );
            const auto dy = size.getHeight( ) - mParent->getInitialSize( ).getHeight( );
            switch( mAnchor ) {
                case Anchor::All: {
                    SetWindowPos( mHandle, HWND_TOP, 0, 0, mInitialSize.getWidth( ) + dx, mInitialSize.getHeight( ) + dy, SWP_NOMOVE );
                    break;
                }
                case Anchor::TopLeft: {
                    break;
                }
                case Anchor::TopLeftRight: {
                    SetWindowPos( mHandle, HWND_TOP, 0, 0, mInitialSize.getWidth( ) + dx, mInitialSize.getHeight( ), SWP_NOMOVE );
                    break;
                }
                case Anchor::TopLeftBottom: {
                    SetWindowPos( mHandle, HWND_TOP, 0, 0, mInitialSize.getWidth( ), mInitialSize.getHeight( ) + dy, SWP_NOMOVE );
                    break;
                }
                case Anchor::LeftRightBottom: {
                    SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ), mInitialPosition.getY( ) + dy, mInitialSize.getWidth( ) + dx, mInitialSize.getHeight( ), 0 );
                    break;
                }
                case Anchor::TopRightBottom: {
                    SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ) + dx, mInitialPosition.getY( ), mInitialSize.getWidth( ), mInitialSize.getHeight( ) + dy, 0 );
                    break;
                }
                case Anchor::TopRight: {
                    SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ) + dx, mInitialPosition.getY( ), 0, 0, SWP_NOSIZE );
                    break;
                }
                case Anchor::LeftBottom: {
                    SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ), mInitialPosition.getY( ) + dy, 0, 0, SWP_NOSIZE );
                    break;
                }
                case Anchor::RightBottom: {
                    SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ) + dx, mInitialPosition.getY( ) + dy, 0, 0, SWP_NOSIZE );
                    break;
                }
                default: {
                    break;
                }
            }
        };

        show( );

        //Win32 defaults to a different UI font, so actually set the proper UI default
        SendMessage( mHandle, WM_SETFONT, reinterpret_cast<WPARAM>( GetStockObject( DEFAULT_GUI_FONT ) ), MAKELPARAM( TRUE, 0 ) );
    }

    Anchor Control::getAnchor( ) const {
        return mAnchor;
    }
    std::wstring Control::getText( ) const {
        static wchar_t text[256];
        GetWindowText( mHandle, text, 256 );
        return std::wstring( text );
    }
    int Control::getX( ) const {
        RECT cr;
        GetClientRect( mHandle, &cr );
        MapWindowPoints( mHandle, GetParent( mHandle ), reinterpret_cast<LPPOINT>( &cr ), 2 );
        RECT wr;
        GetWindowRect( mHandle, &wr );
        POINT p = { wr.left, wr.top };
        ScreenToClient( mHandle, &p );
        return cr.left + p.x;
    }
    int Control::getY( ) const {
        RECT cr;
        GetClientRect( mHandle, &cr );
        MapWindowPoints( mHandle, GetParent( mHandle ), reinterpret_cast<LPPOINT>( &cr ), 2 );
        RECT wr;
        GetWindowRect( mHandle, &wr );
        POINT p = { wr.left, wr.top };
        ScreenToClient( mHandle, &p );
        return cr.top + p.y;
    }

    void Control::setAnchor( Win33::Anchor anchor ) {
        mAnchor = anchor;
    }
    void Control::setText( const std::wstring& text ) {
        SetWindowText( mHandle, text.c_str( ) );
    }
    void Control::setX( int x ) {
        Window::setX( x );
    }
    void Control::setY( int y ) {
        Window::setY( y );
    }
    void Control::setFont( Font* font ) {
        ASSERT_TRUE( font != nullptr, L"font cannot be null." );
        SendMessage(
            mHandle,
            WM_SETFONT,
            reinterpret_cast<WPARAM>( static_cast<HFONT>( *font ) ),
            MAKELPARAM( TRUE, 0 )
        );
    }

}