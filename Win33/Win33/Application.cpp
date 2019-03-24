#include "Application.h"

//typecast warning when using MAKEINTRESOURCE
#pragma warning( disable : 4302 )

#include "Button.h"
#include "CheckBox.h"
#include "ComboBox.h"
#include "DropDown.h"
#include "Error.h"
#include "Label.h"
#include "ListBox.h"
#include "GroupBox.h"
#include "MenuItem.h"
#include "Misc.h"
#include "MultilineTextBox.h"
#include "MultiSelectListBox.h"
#include "PasswordBox.h"
#include "RadioButton.h"
#include "TextBox.h"
#include "TrayIcon.h"
#include "Window.h"

namespace Win33 {

    Application* Application::mInstance = nullptr;

    Application::Application( )
    :
    mCurrentWindow ( nullptr ),
    mWindows       ( ),
    mMenuItems     ( ),
    mTrayIcons     ( )
    {
        if( mInstance ) {
            throw EXCEPTION( L"Application already initialized." );
        }
        mInstance = this;

        auto wcex          = WNDCLASSEX { sizeof( WNDCLASSEX ) };
        wcex.style         = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc   = &Application::windowProcessor;
        wcex.cbClsExtra    = 0;
        wcex.cbWndExtra    = 0;
        wcex.hInstance     = GetModuleHandle( nullptr );
        wcex.hIcon         = LoadIcon   ( nullptr, MAKEINTRESOURCE( IDI_APPLICATION ) );
        wcex.hCursor       = LoadCursor ( nullptr, MAKEINTRESOURCE( IDC_ARROW ) );
        wcex.hbrBackground = reinterpret_cast<HBRUSH>( COLOR_WINDOW );
        wcex.lpszMenuName  = nullptr;
        wcex.lpszClassName = L"WINDOW";
        wcex.hIconSm       = LoadIcon( nullptr, IDI_APPLICATION );

        const auto result = RegisterClassEx( &wcex );
        const auto error  = GetLastError( );
        if( !result && error != ERROR_CLASS_ALREADY_EXISTS ) {
            throw EXCEPTION( L"Unable to register window." );
        }
    }

    Application& Application::get( ) {
        if( !mInstance ) {
            throw EXCEPTION( L"Application not initialized." );
        }
        return *mInstance;
    }

    int Application::run( ) {
        auto m = MSG { };
        while( !mWindows.empty( ) ) {
            if( PeekMessage( &m, 0, 0, 0, PM_REMOVE ) > 0 ) {
                switch( m.message ) {
                    //allow tab presses to be sent through to default dialog processing to allow tabstop cycling
                    case WM_KEYDOWN: {
                        switch( static_cast<VirtualKeyCode>( m.wParam ) ) {
                            case VirtualKeyCode::Tab: {
                                if( !IsDialogMessage( mCurrentWindow, &m ) ) {
                                    TranslateMessage ( &m );
                                    DispatchMessage  ( &m );
                                }
                                break;
                            }
                            //send keypresses to parent window to allow event system to catch them
                            default: {
                                SendMessage( mCurrentWindow, m.message, m.wParam, m.lParam );
                                break;
                            }
                        }
                    }
                    //standard processing of all other messages
                    default: {
                        TranslateMessage ( &m );
                        DispatchMessage  ( &m );
                        break;
                    }
                }
            }
            else {
                Sleep( 10 );
            }
        }
        return static_cast<int>( m.wParam );
    }

    LRESULT CALLBACK Application::windowProcessor( HWND handle, UINT message, WPARAM wordParameter, LPARAM longParameter ) {
        auto& application = Application::get( );
        if( application.mWindows.find( handle ) != application.mWindows.end( ) ) {
            auto* window = application.mWindows.at( handle );
            switch( message ) {
                case WM_TRAYICON: {
                    const auto* trayIcon = application.mTrayIcons.at( static_cast<int>( wordParameter ) );
                    if( trayIcon ) {
                        switch( longParameter ) {
                            case WM_LBUTTONUP: {
                                trayIcon->onLeftClick.trigger( Cursor::getPosition( ) );
                                break;
                            }
                            case WM_RBUTTONUP: {
                                trayIcon->onRightClick.trigger( Cursor::getPosition( ) );
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                    }
                    return true;
                }
                case WM_COMMAND: {
                    if( longParameter ) {
                        message = HIWORD( wordParameter );
                        window  = application.mWindows.at( reinterpret_cast<HWND>( longParameter ) );
                    }
                    else {
                        const auto* menuItem = application.mMenuItems.at( static_cast<int>( wordParameter ) );
                        if( menuItem ) {
                            menuItem->onClick.trigger( );
                        }
                        return true;
                    }
                }
                default: {
                    if( window ) {
                        switch( message ) {
                            case WM_ACTIVATE: {
                                application.mCurrentWindow = handle;
                                break;
                            }
                            case WM_DESTROY: {
                                if( handle == application.mCurrentWindow ) {
                                    application.mCurrentWindow = nullptr;
                                }
                                EnumChildWindows(
                                    *window,
                                    []( HWND window, LPARAM longParameter ) -> BOOL {
                                        Application::get( ).mWindows.erase( window );
                                        return true;
                                    },
                                    0
                                );
                                application.mWindows.erase( *window );
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                        return window->windowProcessor( handle, message, wordParameter, longParameter );
                    }
                    break;
                }
            }
        }
        switch( message ) {
            case WM_CLOSE: {
                DestroyWindow( handle );
                break;
            }
            case WM_DESTROY: {
                PostQuitMessage( 0 );
                break;
            }
            default: {
                break;
            }
        }
        return DefWindowProc( handle, message, wordParameter, longParameter );
    }

}