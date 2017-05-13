#include "Control.h"

#include <cassert>

Win33::Control::Control(
          Common::Type  type,
          Window*       parent,
    const Point&        position,
    const Size&         size,
          WindowStyle   style,
          ExWindowStyle exStyle
):
Common  ( type, parent, position, size, style, exStyle ),
mAnchor ( Anchor::TopLeft )
{
    assert( parent != nullptr );
    parent->onResize += [&]( WindowEvents::ResizeData& data ) {
        auto dx = data.getSize( ).getWidth( )  - mParent->getInitialSize( ).getWidth( );
        auto dy = data.getSize( ).getHeight( ) - mParent->getInitialSize( ).getHeight( );
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
    
    Common::show( );
    
    //Win32 defaults to a different UI font, so actually set the proper UI default
    SendMessage( mHandle, WM_SETFONT, reinterpret_cast<WPARAM>( GetStockObject( DEFAULT_GUI_FONT ) ), MAKELPARAM( TRUE, 0 ) );
}

Win33::Anchor Win33::Control::getAnchor( ) const {
    return mAnchor;
}
std::wstring Win33::Control::getText( ) const {
    static wchar_t text[256];
    GetWindowText( mHandle, text, 256 );
    return std::wstring( text );
}
int Win33::Control::getX( ) const {
    RECT cr;
    GetClientRect( mHandle, &cr );
    MapWindowPoints( mHandle, GetParent( mHandle ), reinterpret_cast<LPPOINT>( &cr ), 2 );
    RECT wr;
    GetWindowRect( mHandle, &wr );
    POINT p = { wr.left, wr.top };
    ScreenToClient( mHandle, &p );
    return cr.left + p.x;
}
int Win33::Control::getY( ) const {
    RECT cr;
    GetClientRect( mHandle, &cr );
    MapWindowPoints( mHandle, GetParent( mHandle ), reinterpret_cast<LPPOINT>( &cr ), 2 );
    RECT wr;
    GetWindowRect( mHandle, &wr );
    POINT p = { wr.left, wr.top };
    ScreenToClient( mHandle, &p );
    return cr.top + p.y;
}

void Win33::Control::setAnchor( Win33::Anchor anchor ) {
    mAnchor = anchor;
}
void Win33::Control::setText( const std::wstring& text ) {
    SetWindowText( mHandle, text.c_str( ) );
}
void Win33::Control::setX( int x ) {
    Common::setX( x );
}
void Win33::Control::setY( int y ) {
    Common::setY( y );
}
void Win33::Control::setFont( Font* font ) {
    SendMessage( mHandle, WM_SETFONT, reinterpret_cast<WPARAM>( Win33::Interop::toHandle( font ) ), MAKELPARAM( TRUE, 0 ) );
}