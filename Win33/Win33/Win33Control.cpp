#include "Win33Control.h"

#include <cassert>

#include "Win33Window.h"

Win33::Control::Control(
          Type                type,
          Win33::Window*      parent,
    const Point&              position,
    const Size&               size,
          WindowStyle::Type   style,
          ExWindowStyle::Type exStyle
):
Platform ( type, parent, position, size, style, exStyle ),
mAnchor  ( Anchor::All )
{
    assert( parent != nullptr );
    parent->resize.addHandler(
        [&]( WindowEvents::ResizeData& data ) {
            auto dx = data.getSize( ).getWidth( ) - mParent->mInitialSize.getWidth( );
            auto dy = data.getSize( ).getHeight( ) - mParent->mInitialSize.getHeight( );
            switch( mAnchor ) {
                case Anchor::All: {
                    SetWindowPos( mHandle, HWND_TOP, 0, 0, mInitialSize.getWidth( ) + dx, mInitialSize.getHeight( ) + dy, SWP_NOMOVE );
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
        }
    );
    
    Platform::show( );
    
    SendMessage( mHandle, WM_SETFONT, reinterpret_cast<WPARAM>( GetStockObject( DEFAULT_GUI_FONT ) ), MAKELPARAM( TRUE, 0 ) );
}
Win33::Control::Control( Control&& other )
:
Platform ( std::move( other ) ),
mAnchor  ( other.mAnchor )
{ }
Win33::Control& Win33::Control::operator=( Control&& other ) {
    Platform::operator=( std::move( other ) );
    mAnchor = other.mAnchor;
    return *this;
}

Win33::Anchor::Type Win33::Control::getAnchor( ) const {
    return mAnchor;
}
int Win33::Control::getX( ) const {
    RECT cr;
    GetClientRect( mHandle, &cr );
    MapWindowPoints( mHandle, mParent->mHandle, reinterpret_cast<LPPOINT>( &cr ), 2 );
    RECT wr;
    GetWindowRect( mHandle, &wr );
    POINT p = { wr.left, wr.top };
    ScreenToClient( mHandle, &p );
    return cr.left + p.x;
}
int Win33::Control::getY( ) const {
    RECT cr;
    GetClientRect( mHandle, &cr );
    MapWindowPoints( mHandle, mParent->mHandle, reinterpret_cast<LPPOINT>( &cr ), 2 );
    RECT wr;
    GetWindowRect( mHandle, &wr );
    POINT p = { wr.left, wr.top };
    ScreenToClient( mHandle, &p );
    return cr.top + p.y;
}

void Win33::Control::setAnchor( Anchor::Type anchor ) {
    mAnchor = anchor;
}
void Win33::Control::setX( int x ) {
    Platform::setX( x );
}
void Win33::Control::setY( int y ) {
    Platform::setY( y );
}