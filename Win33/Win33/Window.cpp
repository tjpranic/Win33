#include "Window.h"

#include "Application.h"
#include "Error.h"
#include "Misc.h"

namespace Win33 {

    const Point Window::DefaultPosition = { CW_USEDEFAULT, CW_USEDEFAULT };
    const Size  Window::DefaultSize     = { CW_USEDEFAULT, CW_USEDEFAULT };

    Window::Window(
        const Point&        position,
        const Size&         size,
              WindowStyle   style,
              ExWindowStyle exStyle,
        const std::wstring& className
    ):
    Window( nullptr, position, size, style, exStyle, className )
    { }
    Window::Window(
              Window*       parent,
        const Point&        position,
        const Size&         size,
              WindowStyle   style,
              ExWindowStyle exStyle,
        const std::wstring& className
    ):
    mHandle          ( nullptr ),
    mParent          ( parent ),
    mInitialPosition ( position ),
    mInitialSize     ( size ),
    mMinimumSize     ( { 0, 0 } ),
    mMaximumSize     ( Monitor::getSize( ) ),
    mPosition        ( position ),
    mSize            ( size )
    {
        mHandle = CreateWindowEx(
            static_cast<DWORD>( exStyle ),
            className.c_str( ),
            L"",
            static_cast<DWORD>( style ),
            position.getX( ),
            position.getY( ),
            size.getWidth( ),
            size.getHeight( ),
            parent ? parent->mHandle : nullptr,
            nullptr,
            GetModuleHandle( nullptr ),
            nullptr
        );

        if( !mHandle ) {
            throw EXCEPTION( L"Unable to create window." );
        }

        Application::get( ).mWindows[mHandle] = this;
    }

    void Window::show( ) {
        ShowWindow( mHandle, SW_SHOW );
    }
    void Window::hide( ) {
        ShowWindow( mHandle, SW_HIDE );
    }
    void Window::close( ) {
        SendMessage( mHandle, WM_CLOSE, 0, 0 );
    }
    void Window::minimize( ) {
        CloseWindow( mHandle );
    }
    void Window::maximize( ) {
        ShowWindow( mHandle, SW_MAXIMIZE );
    }
    void Window::restore( ) {
        ShowWindow( mHandle, SW_RESTORE );
    }
    void Window::toggleVisibility( ) {
        if( getVisible( ) ) {
            hide( );
        }
        else {
            show( );
        }
    }

    Point Window::getInitialPosition( ) const {
        return mInitialPosition;
    }
    Size Window::getInitialSize( ) const {
        return mInitialSize;
    }
    Size Window::getMinimumSize( ) const {
        return mMinimumSize;
    }
    Size Window::getMaximumSize( ) const {
        return mMaximumSize;
    }
    bool Window::getEnabled( ) const {
        return IsWindowEnabled( mHandle ) != 0;
    }
    int Window::getX( ) const {
        RECT cr = { };
        GetClientRect( mHandle, &cr );
        MapWindowPoints( mHandle, HWND_DESKTOP, reinterpret_cast<LPPOINT>( &cr ), 2 );
        RECT wr = { };
        GetWindowRect( mHandle, &wr );
        POINT p = { wr.left, wr.top };
        ScreenToClient( mHandle, &p );
        return cr.left + p.x;
    }
    int Window::getY( ) const {
        RECT cr = { };
        GetClientRect( mHandle, &cr );
        MapWindowPoints( mHandle, HWND_DESKTOP, reinterpret_cast<LPPOINT>( &cr ), 2 );
        RECT wr = { };
        GetWindowRect( mHandle, &wr );
        POINT p = { wr.left, wr.top };
        ScreenToClient( mHandle, &p );
        return cr.top + p.y;
    }
    Point Window::getPosition( ) const {
        return { getX( ), getY( ) };
    }
    int Window::getWidth( ) const {
        RECT wr = { };
        GetWindowRect( mHandle, &wr );
        return wr.right - wr.left;
    }
    int Window::getHeight( ) const {
        RECT wr = { };
        GetWindowRect( mHandle, &wr );
        return wr.bottom - wr.top;
    }
    Size Window::getSize( ) const {
        return { getWidth( ), getHeight( ) };
    }
    bool Window::getVisible( ) const {
        return IsWindowVisible( mHandle ) != 0;
    }
    std::wstring Window::getTitle( ) const {
        static wchar_t text[256];
        GetWindowText( mHandle, text, 256 );
        return std::wstring( text );
    }
    bool Window::getResizable( ) const {
        return ( GetWindowLong( mHandle, GWL_STYLE ) & WS_THICKFRAME ) == WS_THICKFRAME;
    }
    bool Window::getMaximizable( ) const {
        return ( GetWindowLong( mHandle, GWL_STYLE ) & WS_MAXIMIZEBOX ) == WS_MAXIMIZEBOX;
    }
    bool Window::getMinimizable( ) const {
        return ( GetWindowLong( mHandle, GWL_STYLE ) & WS_MINIMIZEBOX ) == WS_MINIMIZEBOX;
    }
    bool Window::getMinimized( ) const {
        auto wp = WINDOWPLACEMENT { };
        GetWindowPlacement( mHandle, &wp );
        return wp.showCmd == SW_SHOWMINIMIZED;
    }
    bool Window::getMaximized( ) const {
        auto wp = WINDOWPLACEMENT { };
        GetWindowPlacement( mHandle, &wp );
        return wp.showCmd == SW_SHOWMAXIMIZED;
    }

    void Window::setMinimumSize( const Size& size ) {
        mMinimumSize = size;
    }
    void Window::setMaximumSize( const Size& size ) {
        mMaximumSize = size;
    }
    void Window::setEnabled( bool enabled ) {
        EnableWindow( mHandle, enabled );
    }
    void Window::setX( int x ) {
        SetWindowPos( mHandle, HWND_TOP, x, getY( ), 0, 0, SWP_NOSIZE );
    }
    void Window::setY( int y ) {
        SetWindowPos( mHandle, HWND_TOP, getX( ), y, 0, 0, SWP_NOSIZE );
    }
    void Window::setPosition( const Point& position ) {
        SetWindowPos( mHandle, HWND_TOP, position.getX( ), position.getY( ), 0, 0, SWP_NOSIZE );
    }
    void Window::setWidth( int width ) {
        SetWindowPos( mHandle, HWND_TOP, 0, 0, width, getHeight( ), SWP_NOMOVE );
    }
    void Window::setHeight( int height ) {
        SetWindowPos( mHandle, HWND_TOP, 0, 0, getWidth( ), height, SWP_NOMOVE );
    }
    void Window::setSize( const Size& size ) {
        SetWindowPos( mHandle, HWND_TOP, 0, 0, size.getWidth( ), size.getHeight( ), SWP_NOMOVE );
    }
    void Window::setVisible( bool visible ) {
        ShowWindow( mHandle, visible ? SW_SHOW : SW_HIDE );
    }
    void Window::setTitle( const std::wstring& title ) {
        SetWindowText( mHandle, title.c_str( ) );
    }
    void Window::setResizable( bool resizable ) {
        if( !resizable ) {
            SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) & ~WS_THICKFRAME );
        }
        else {
            SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) | WS_THICKFRAME );
        }
    }
    void Window::setIcon( Icon* icon ) {
        ASSERT_TRUE( icon != nullptr, L"icon cannot be null" );
        SendMessage( mHandle, WM_SETICON, ICON_SMALL, reinterpret_cast<LONG_PTR>( icon ) );
    }
    void Window::setMaximizable( bool maximizable ) {
        if( !maximizable ) {
            SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) & ~WS_MAXIMIZEBOX );
        }
        else {
            SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) | WS_MAXIMIZEBOX );
        }
    }
    void Window::setMinimizable( bool minimizable ) {
        if( !minimizable ) {
            SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) & ~WS_MINIMIZEBOX );
        }
        else {
            SetWindowLong( mHandle, GWL_STYLE, GetWindowLong( mHandle, GWL_STYLE ) | WS_MINIMIZEBOX );
        }
    }
    void Window::setMinimzed( bool minimized ) {
        if( !getMinimized( ) ) {
            minimize( );
        }
    }
    void Window::setMaximized( bool maximized ) {
        if( !getMaximized( ) ) {
            maximize( );
        }
    }

    LRESULT CALLBACK Window::windowProcessor( HWND handle, UINT message, WPARAM wordParameter, LPARAM longParameter ) {
        switch( message ) {
            case WM_PAINT: {
                DrawMenuBar( handle );
                break;
            }
            case WM_SIZE: {
                onResize.trigger( getSize( ) );
                break;
            }
            case WM_MOVE: {
                onMove.trigger( getPosition( ) );
                break;
            }
            case WM_GETMINMAXINFO: {
                auto* mmi = reinterpret_cast<MINMAXINFO*>( longParameter );
                mmi->ptMinTrackSize.x = getMinimumSize( ).getWidth( );
                mmi->ptMinTrackSize.y = getMinimumSize( ).getHeight( );
                mmi->ptMaxTrackSize.x = getMaximumSize( ).getWidth( );
                mmi->ptMaxTrackSize.y = getMaximumSize( ).getHeight( );
                break;
            }
            case WM_LBUTTONUP: {
                onLeftClick.trigger( Cursor::getPosition( ) );
                break;
            }
            case WM_RBUTTONUP: {
                onRightClick.trigger( Cursor::getPosition( ) );
                break;
            }
            case WM_SYSKEYDOWN:
            case WM_KEYDOWN: {
                onKeyDown.trigger( Keys::virtualKeyCodeToKey( static_cast<VirtualKeyCode>( wordParameter ) ) );
                break;
            }
            case WM_SYSKEYUP:
            case WM_KEYUP: {
                onKeyUp.trigger( Keys::virtualKeyCodeToKey( static_cast<VirtualKeyCode>( wordParameter ) ) );
                break;
            }
            case WM_CLOSE: {
                const auto cancelled = false;
                onClose.trigger( cancelled );
                if( cancelled ) {
                    return true;
                }
                break;
            }
            case WM_DESTROY: {
                onDestroy.trigger( );
                break;
            }
            default: {
                break;
            }
        }
        return DefWindowProc( handle, message, wordParameter, longParameter );
    }

    Window::operator HWND( ) const {
        return mHandle;
    }

}