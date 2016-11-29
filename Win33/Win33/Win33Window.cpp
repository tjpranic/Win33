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
mResizable   ( ( style & WS_THICKFRAME ) != 0 ),
mMaximizable ( ( style & WS_MAXIMIZEBOX ) != 0 ),
mMinimizable ( ( style & WS_MINIMIZEBOX ) != 0 ),
mMenuBar     ( nullptr ),
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
mMenuBar     ( nullptr ),
mIcon        ( L"" )
{
    assert( mParent != nullptr );
}
Win33::Window::Window( Window&& other )
:
Platform     ( std::move( other ) ),
idle         ( std::move( other.idle ) ),
close        ( std::move( other.close ) ),
resize       ( std::move( other.resize ) ),
move         ( std::move( other.move ) ),
mResizable   ( other.mResizable ),
mMaximizable ( other.mMaximizable ),
mMinimizable ( other.mMinimizable ),
mMenuBar     ( other.mMenuBar ),
mIcon        ( std::move( other.mIcon ) )
{ }
Win33::Window& Win33::Window::operator=( Window&& other ) {
    Platform::operator=( std::move( other ) );
    idle         = std::move( other.idle );
    close        = std::move( other.close );
    resize       = std::move( other.resize );
    move         = std::move( other.move );
    mResizable   = other.mResizable;
    mMaximizable = other.mMaximizable;
    mMinimizable = other.mMinimizable;
    mMenuBar     = other.mMenuBar;
    mIcon        = std::move( other.mIcon );
    return *this;
}

void Win33::Window::quit( ) {
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

std::wstring Win33::Window::getTitle( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}
bool Win33::Window::getResizable( ) const {
    return mResizable;
}
Win33::MenuBar* Win33::Window::getMenuBar( ) const {
    return mMenuBar;
}
Win33::ContextMenu* Win33::Window::getContextMenu( ) const {
    return mContextMenu;
}
const std::wstring& Win33::Window::getIcon( ) const {
    return mIcon;
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
void Win33::Window::setMenuBar( MenuBar* menuBar ) {
    mMenuBar = menuBar;
    SetMenu( mHandle, mMenuBar->getHandle( ) );
}
void Win33::Window::setContextMenu( ContextMenu* contextMenu ) {
    mContextMenu = contextMenu;
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