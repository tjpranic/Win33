#include "Win33Window.h"

#include <cassert>

#include "Win33Application.h"
#include "Win33Utility.h"
#include "Win33BitfieldOperators.h"

const Win33::Point Win33::Window::DefaultPosition = { CW_USEDEFAULT, CW_USEDEFAULT };
const Win33::Size  Win33::Window::DefaultSize     = { CW_USEDEFAULT, CW_USEDEFAULT };

Win33::Window::Window(
    const Win33::Point&        position,
    const Win33::Size&         size,
          Win33::WindowStyle   style,
          Win33::ExWindowStyle exStyle
):
Common       ( Win33::Common::Type::Window, nullptr, position, size, style, exStyle ),
mResizable   ( ( style & Win33::WindowStyle::Thickframe   ) == Win33::WindowStyle::Thickframe   ),
mMaximizable ( ( style & Win33::WindowStyle::MaximizedBox ) == Win33::WindowStyle::MaximizedBox ),
mMinimizable ( ( style & Win33::WindowStyle::MinimizedBox ) == Win33::WindowStyle::MinimizedBox ),
mMinimized   ( false ),
mMaximized   ( false ),
mTitle       ( L"" )
{ }
Win33::Window::Window(
          Win33::Window*       parent,
    const Win33::Point&        position,
    const Win33::Size&         size,
          Win33::WindowStyle   style,
          Win33::ExWindowStyle exStyle
):
Common       ( Win33::Common::Type::Window, parent, position, size, style, exStyle ),
mResizable   ( ( style & Win33::WindowStyle::Thickframe   ) == Win33::WindowStyle::Thickframe   ),
mMaximizable ( ( style & Win33::WindowStyle::MaximizedBox ) == Win33::WindowStyle::MaximizedBox ),
mMinimizable ( ( style & Win33::WindowStyle::MinimizedBox ) == Win33::WindowStyle::MinimizedBox ),
mMinimized   ( false ),
mMaximized   ( false ),
mTitle       ( L"" )
{
    assert( mParent != nullptr );
}

void Win33::Window::close( ) {
    SendMessage( mHandle, WM_CLOSE, 0, 0 );
}
void Win33::Window::minimize( ) {
    CloseWindow( mHandle );
    mMinimized = true;
    mMaximized = false;
}
void Win33::Window::maximize( ) {
    ShowWindow( mHandle, SW_MAXIMIZE );
    mMaximized = true;
    mMinimized = false;
}
void Win33::Window::restore( ) {
    ShowWindow( mHandle, SW_RESTORE );
    mMaximized = false;
    mMinimized = false;
}
void Win33::Window::toggleVisibility( ) {
    if( getVisible( ) ) {
        hide( );
    }
    else {
        show( );
    }
}

const std::wstring& Win33::Window::getTitle( ) const {
    static wchar_t text[256];
    GetWindowText( mHandle, text, 256 );
    Win33::Utility::mutate( const_cast<std::wstring*>( &mTitle ), text );
    return mTitle;
}
bool Win33::Window::getResizable( ) const {
    return mResizable;
}
bool Win33::Window::getMaximizable( ) const {
    return mMaximizable;
}
bool Win33::Window::getMinimizable( ) const {
    return mMinimizable;
}
bool Win33::Window::getMinimized( ) const {
    return mMinimized;
}
bool Win33::Window::getMaximized( ) const {
    return mMaximized;
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
    auto handle = static_cast<HICON>(
        LoadImage( nullptr, icon.c_str( ), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED )
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
void Win33::Window::setMinimzed( bool minimized ) {
    if( !mMinimized ) {
        minimize( );
    }
}
void Win33::Window::setMaximized( bool maximized ) {
    if( !mMaximized ) {
        maximize( );
    }
}