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
          Window*              parent,
    const Point&               position,
    const Size&                size,
          WindowStyle::Type    style,
          ExWindowStyle::Type  exStyle
):
Platform     ( Type::Window, parent, position, size, style, exStyle ),
mResizable   ( ( style & WS_THICKFRAME ) != 0 ),
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
mResizable   ( other.mResizable ),
mMaximizable ( other.mMaximizable ),
mMinimizable ( other.mMinimizable ),
mMenuBar     ( other.mMenuBar ),
mIcon        ( std::move( other.mIcon ) )
{ }
Win33::Window& Win33::Window::operator=( Window&& other ) {
    Platform::operator=( std::move( other ) );
    mResizable   = other.mResizable;
    mMaximizable = other.mMaximizable;
    mMinimizable = other.mMinimizable;
    mMenuBar     = other.mMenuBar;
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

std::wstring Win33::Window::getTitle( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}
bool Win33::Window::getResizable( ) const {
    return mResizable;
}
Win33::MenuBar& Win33::Window::getMenuBar( ) const {
    return *mMenuBar;
}
Win33::ContextMenu& Win33::Window::getContextMenu( ) const {
    return *mContextMenu;
}
const Win33::Icon& Win33::Window::getIcon( ) const {
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
void Win33::Window::setMenuBar( MenuBar* menu ) {
    mMenuBar = menu;
    SetMenu( mHandle, mMenuBar->mHandle );
}
void Win33::Window::setContextMenu( ContextMenu* menu ) {
    mContextMenu = menu;
}
void Win33::Window::setIcon( const Win33::Icon& icon ) {
    SendMessage( mHandle, WM_SETICON, ICON_SMALL, reinterpret_cast<LONG_PTR>( icon.mHandle ) );
    mIcon = icon;
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

void Win33::Window::addIdleHandler( const WindowEvents::Handler& handler ) {
    mIdle.addHandler( handler );
}
void Win33::Window::addCloseHandler( const WindowEvents::Handler& handler ) {
    mClose.addHandler( handler );
}
void Win33::Window::addResizeHandler( const WindowEvents::ResizeHandler& handler ) {
    mResize.addHandler( handler );
}
void Win33::Window::addMovedHandler( const WindowEvents::MoveHandler& handler ) {
    mMove.addHandler( handler );
}

void Win33::Window::removeIdleHandler( const WindowEvents::Handler& handler ) {
    mIdle.removeHandler( handler );
}
void Win33::Window::removeCloseHandler( const WindowEvents::Handler& handler ) {
    mClose.removeHandler( handler );
}
void Win33::Window::removeResizeHandler( const WindowEvents::ResizeHandler& handler ) {
    mResize.removeHandler( handler );
}
void Win33::Window::removeMovedHandler( const WindowEvents::MoveHandler& handler ) {
    mMove.removeHandler( handler );
}

void Win33::Window::removeMenuBar( ) {
    SetMenu( mHandle, nullptr );
}
void Win33::Window::removeContextMenu( ) {
    mContextMenu = nullptr;
}