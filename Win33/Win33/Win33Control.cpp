#include "Win33Control.h"

#include <cassert>

#include "Win33Utility.h"

Win33::Control::Control(
          Win33::Platform::Type type,
          Win33::Window*        parent,
    const Win33::Point&         position,
    const Win33::Size&          size,
          Win33::WindowStyle    style,
          Win33::ExWindowStyle  exStyle
):
Platform ( type, parent, position, size, style, exStyle ),
mAnchor  ( Win33::Anchor::TopLeft ),
mText    ( L"" )
{
    assert( parent != nullptr );
    parent->onResize += [&]( Win33::WindowEvents::ResizeData& data ) {
        auto dx = data.getSize( ).getWidth( )  - mParent->getInitialSize( ).getWidth( );
        auto dy = data.getSize( ).getHeight( ) - mParent->getInitialSize( ).getHeight( );
        switch( mAnchor ) {
            case Win33::Anchor::All: {
                SetWindowPos( mHandle, HWND_TOP, 0, 0, mInitialSize.getWidth( ) + dx, mInitialSize.getHeight( ) + dy, SWP_NOMOVE );
                break;
            }
            case Win33::Anchor::TopLeft: {
                break;
            }
            case Win33::Anchor::TopLeftRight: {
                SetWindowPos( mHandle, HWND_TOP, 0, 0, mInitialSize.getWidth( ) + dx, mInitialSize.getHeight( ), SWP_NOMOVE );
                break;
            }
            case Win33::Anchor::TopLeftBottom: {
                SetWindowPos( mHandle, HWND_TOP, 0, 0, mInitialSize.getWidth( ), mInitialSize.getHeight( ) + dy, SWP_NOMOVE );
                break;
            }
            case Win33::Anchor::LeftRightBottom: {
                SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ), mInitialPosition.getY( ) + dy, mInitialSize.getWidth( ) + dx, mInitialSize.getHeight( ), 0 );
                break;
            }
            case Win33::Anchor::TopRightBottom: {
                SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ) + dx, mInitialPosition.getY( ), mInitialSize.getWidth( ), mInitialSize.getHeight( ) + dy, 0 );
                break;
            }
            case Win33::Anchor::TopRight: {
                SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ) + dx, mInitialPosition.getY( ), 0, 0, SWP_NOSIZE );
                break;
            }
            case Win33::Anchor::LeftBottom: {
                SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ), mInitialPosition.getY( ) + dy, 0, 0, SWP_NOSIZE );
                break;
            }
            case Win33::Anchor::RightBottom: {
                SetWindowPos( mHandle, HWND_TOP, mInitialPosition.getX( ) + dx, mInitialPosition.getY( ) + dy, 0, 0, SWP_NOSIZE );
                break;
            }
            default: {
                break;
            }
        }
    };
    
    Platform::show( );
    
    //Win32 defaults to a different UI font, so actually set the proper UI default
    SendMessage( mHandle, WM_SETFONT, reinterpret_cast<WPARAM>( GetStockObject( DEFAULT_GUI_FONT ) ), MAKELPARAM( TRUE, 0 ) );
}
Win33::Control::Control( Control&& other )
:
Platform ( std::move( other ) ),
mAnchor  ( other.mAnchor ),
mText    ( std::move( other.mText ) )
{ }
Win33::Control& Win33::Control::operator=( Control&& other ) {
    Platform::operator=( std::move( other ) );
    mAnchor = other.mAnchor;
    mText   = std::move( other.mText );
    return *this;
}

Win33::Window* Win33::Control::getParent( ) const {
    return static_cast<Win33::Window*>( mParent );
}
Win33::Anchor Win33::Control::getAnchor( ) const {
    return mAnchor;
}
const std::wstring& Win33::Control::getText( ) const {
    static wchar_t text[256];
    GetWindowText( mHandle, text, 256 );
    Win33::Utility::mutate( const_cast<std::wstring*>( &mText ), text );
    return mText;
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
    mText = text;
    
    SetWindowText( mHandle, text.c_str( ) );
}
void Win33::Control::setX( int x ) {
    Platform::setX( x );
}
void Win33::Control::setY( int y ) {
    Platform::setY( y );
}
void Win33::Control::setFont( const Win33::Font* font ) {
    SendMessage( mHandle, WM_SETFONT, reinterpret_cast<WPARAM>( Win33::Interop::toHandle( font ) ), MAKELPARAM( TRUE, 0 ) );
}