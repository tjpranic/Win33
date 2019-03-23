#include "Window.h"

#include "Application.h"
#include "Error.h"

const Win33::Point Win33::Window::DefaultPosition = { CW_USEDEFAULT, CW_USEDEFAULT };
const Win33::Size  Win33::Window::DefaultSize     = { CW_USEDEFAULT, CW_USEDEFAULT };

Win33::Window::Window(
    const Point&        position,
    const Size&         size,
          WindowStyle   style,
          ExWindowStyle exStyle
):
Common( Common::Type::Window, nullptr, position, size, style, exStyle )
{ }
Win33::Window::Window(
          Window*       parent,
    const Point&        position,
    const Size&         size,
          WindowStyle   style,
          ExWindowStyle exStyle
):
Common( Common::Type::Window, parent, position, size, style, exStyle )
{
    ASSERT_TRUE( mParent != nullptr, L"mParent cannot be null." );
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
void Win33::Window::restore( ) {
    ShowWindow( mHandle, SW_RESTORE );
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
    static wchar_t text[256];
    GetWindowText( mHandle, text, 256 );
    return std::wstring( text );
}
bool Win33::Window::getResizable( ) const {
    return ( GetWindowLong( mHandle, GWL_STYLE ) & WS_THICKFRAME ) == WS_THICKFRAME;
}
bool Win33::Window::getMaximizable( ) const {
    return ( GetWindowLong( mHandle, GWL_STYLE ) & WS_MAXIMIZEBOX ) == WS_MAXIMIZEBOX;
}
bool Win33::Window::getMinimizable( ) const {
    return ( GetWindowLong( mHandle, GWL_STYLE ) & WS_MINIMIZEBOX ) == WS_MINIMIZEBOX;
}
bool Win33::Window::getMinimized( ) const {
    auto wp = WINDOWPLACEMENT { };
    GetWindowPlacement( mHandle, &wp );
    return wp.showCmd == SW_SHOWMINIMIZED;
}
bool Win33::Window::getMaximized( ) const {
    auto wp = WINDOWPLACEMENT { };
    GetWindowPlacement( mHandle, &wp );
    return wp.showCmd == SW_SHOWMAXIMIZED;
}

void Win33::Window::setTitle( const std::wstring& title ) {
    SetWindowText( mHandle, title.c_str( ) );
}
void Win33::Window::setResizable( bool resizable ) {
    if( !resizable ) {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) & ~WS_THICKFRAME );
    }
    else {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) | WS_THICKFRAME );
    }
}
void Win33::Window::setIcon( const std::wstring& icon ) {
    ASSERT_TRUE( icon != L"", L"icon cannot be null" );
    const auto handle = static_cast<HICON>(
        LoadImage( nullptr, icon.c_str( ), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED )
    );
    SendMessage( mHandle, WM_SETICON, ICON_SMALL, reinterpret_cast<LONG_PTR>( handle ) );
}
void Win33::Window::setMaximizable( bool maximizable ) {
    if( !maximizable ) {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) & ~WS_MAXIMIZEBOX );
    }
    else {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) | WS_MAXIMIZEBOX );
    }
}
void Win33::Window::setMinimizable( bool minimizable ) {
    if( !minimizable ) {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) & ~WS_MINIMIZEBOX );
    }
    else {
        SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) | WS_MINIMIZEBOX );
    }
}
void Win33::Window::setMinimzed( bool minimized ) {
    if( !getMinimized( ) ) {
        minimize( );
    }
}
void Win33::Window::setMaximized( bool maximized ) {
    if( !getMaximized( ) ) {
        maximize( );
    }
}