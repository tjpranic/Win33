#include "Win33Window.h"

#include <cassert>

#include "Win33Application.h"

Win33::Window::Window(
    const Point&               position,
    const Size&                size,
          WindowStyle::Type    style,
          ExWindowStyle::Type  exStyle
):
Platform     ( Type::Window, nullptr, position, size, style, exStyle ),
mResizable   ( ( style & WS_THICKFRAME  ) != 0 ),
mMaximizable ( ( style & WS_MAXIMIZEBOX ) != 0 ),
mMinimizable ( ( style & WS_MINIMIZEBOX ) != 0 ),
mIcon        ( L"" )
{ }
Win33::Window::Window(
          Window*             parent,
    const Point&              position,
    const Size&               size,
          WindowStyle::Type   style,
          ExWindowStyle::Type exStyle
):
Platform     ( Type::Window, parent, position, size, style, exStyle ),
mResizable   ( ( style & WS_THICKFRAME  ) != 0 ),
mMaximizable ( ( style & WS_MAXIMIZEBOX ) != 0 ),
mMinimizable ( ( style & WS_MINIMIZEBOX ) != 0 ),
mIcon        ( L"" )
{
    assert( mParent != nullptr );
}
Win33::Window::Window( Window&& other )
:
Platform     ( std::move( other ) ),
onClose      ( std::move( other.onClose ) ),
onResize     ( std::move( other.onResize ) ),
onMove       ( std::move( other.onMove ) ),
onLeftClick  ( std::move( other.onLeftClick ) ),
onRightClick ( std::move( other.onRightClick ) ),
mResizable   ( other.mResizable ),
mMaximizable ( other.mMaximizable ),
mMinimizable ( other.mMinimizable ),
mIcon        ( std::move( other.mIcon ) )
{ }
Win33::Window& Win33::Window::operator=( Window&& other ) {
    Platform::operator=( std::move( other ) );
    onClose      = std::move( other.onClose );
    onResize     = std::move( other.onResize );
    onMove       = std::move( other.onMove );
    onLeftClick  = std::move( other.onLeftClick );
    onRightClick = std::move( other.onRightClick );
    mResizable   = other.mResizable;
    mMaximizable = other.mMaximizable;
    mMinimizable = other.mMinimizable;
    mIcon        = std::move( other.mIcon );
    return *this;
}

void Win33::Window::close( ) {
    SendMessage( mHandle, WM_CLOSE, 0, 0 );
}
void Win33::Window::minimize( ) {
    CloseWindow( mHandle );
}
void Win33::Window::maximize( ) {
    ShowWindow( mHandle, SW_MAXIMIZE );
}
void Win33::Window::toggleVisibility( ) {
    if( getVisible( ) ) {
        hide( );
    }
    else {
        show( );
    }
}

Win33::Window* Win33::Window::getParent( ) const {
    return static_cast<Win33::Window*>( mParent );
}
std::wstring Win33::Window::getTitle( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}
bool Win33::Window::getResizable( ) const {
    return mResizable;
}
const std::wstring& Win33::Window::getIcon( ) const {
    return mIcon;
}
bool Win33::Window::getMaximizable( ) const {
    return mMaximizable;
}
bool Win33::Window::getMinimizable( ) const {
    return mMinimizable;
}

void Win33::Window::setTitle( const std::wstring& title ) {
    SetWindowText( mHandle, title.c_str( ) );
}
void Win33::Window::setResizable( bool resizable ) {
    mResizable = resizable;
    if( !mResizable ) {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) & ~WS_THICKFRAME );
    }
    else {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) | WS_THICKFRAME );
    }
}
void Win33::Window::setIcon( const std::wstring& icon ) {
    assert( icon != L"" );
    mIcon = icon;
    auto handle = static_cast<HICON>(
        LoadImage( nullptr, mIcon.c_str( ), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED )
    );
    SendMessage( mHandle, WM_SETICON, ICON_SMALL, reinterpret_cast<LONG_PTR>( handle ) );
}
void Win33::Window::setMaximizable( bool maximizable ) {
    mMaximizable = maximizable;
    if( !mMaximizable ) {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) & ~WS_MAXIMIZEBOX );
    }
    else {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) | WS_MAXIMIZEBOX );
    }
}
void Win33::Window::setMinimizable( bool minimizable ) {
    mMinimizable = minimizable;
    if( !mMinimizable ) {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) & ~WS_MINIMIZEBOX );
    }
    else {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) | WS_MINIMIZEBOX );
    }
}