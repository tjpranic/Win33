#include "Win33Application.h"

//typecast warning when using MAKEINTRESOURCE
#pragma warning( disable : 4302 )

#include "Win33System.h"
#include "Win33Common.h"
#include "Win33MenuItem.h"
#include "Win33TrayIcon.h"
#include "Win33Window.h"
#include "Win33Button.h"
#include "Win33CheckBox.h"
#include "Win33RadioButton.h"
#include "Win33TextBox.h"
#include "Win33PasswordBox.h"
#include "Win33MultilineTextBox.h"
#include "Win33Label.h"
#include "Win33GroupBox.h"
#include "Win33ComboBox.h"

Win33::Application*                        Win33::Application::mInstance = nullptr;
std::unordered_map<HWND, Win33::Common*>   Win33::Application::mCommons;
std::unordered_map<int,  Win33::MenuItem*> Win33::Application::mMenuItems;
std::unordered_map<int,  Win33::TrayIcon*> Win33::Application::mTrayIcons;

Win33::Application::Application( ) {
    if( mInstance ) {
        throw std::runtime_error( "Application already initialized." );
    }
    mInstance = this;
    
    auto wcex          = WNDCLASSEX { sizeof( WNDCLASSEX ) };
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = &Win33::Application::windowProcessor;
    wcex.cbClsExtra    = 0;
    wcex.cbWndExtra    = 0;
    wcex.hInstance     = GetModuleHandle( nullptr );
    wcex.hIcon         = LoadIcon( nullptr, MAKEINTRESOURCE( IDI_APPLICATION ) );
    wcex.hCursor       = LoadCursor( nullptr, MAKEINTRESOURCE( IDC_ARROW ) );
    wcex.hbrBackground = reinterpret_cast<HBRUSH>( COLOR_WINDOW );
    wcex.lpszMenuName  = nullptr;
    wcex.lpszClassName = L"WINDOW";
    wcex.hIconSm       = LoadIcon( nullptr, IDI_APPLICATION );
    
    if( !RegisterClassEx( &wcex ) ) {
        throw std::runtime_error( "Unable to register window template." );
    }
}

int Win33::Application::run( ) {
    auto m = MSG { };
    while( !mCommons.empty( ) ) {
        if( PeekMessage( &m, 0, 0, 0, PM_REMOVE ) > 0 ) {
            TranslateMessage( &m );
            DispatchMessage( &m );
        }
        else {
            Sleep( 10 );
        }
    }
    return static_cast<int>( m.wParam );
}

LRESULT CALLBACK Win33::Application::windowProcessor( HWND window, UINT message, WPARAM wordParameter, LPARAM longParameter ) {
    if( mCommons.find( window ) != mCommons.end( ) ) {
        Win33::Common* c = nullptr;
        switch( message ) {
            case WM_COMMAND: {
                if( longParameter ) {
                    message = HIWORD( wordParameter );
                    c = mCommons.at( reinterpret_cast<HWND>( longParameter ) );
                }
                else {
                    auto menuID = static_cast<int>( wordParameter );
                    if( mMenuItems.find( menuID ) != mMenuItems.end( ) ) {
                        auto menuItem = mMenuItems[menuID];
                        menuItem->onClick.handle( Win33::MenuItemEvents::ClickData( ) );
                    }
                    return true;
                }
                break;
            }
            case WM_TRAYICON: {
                auto trayiconID = static_cast<int>( wordParameter );
                Win33::TrayIcon* ti = mTrayIcons[trayiconID];
                switch( longParameter ) {
                    case WM_LBUTTONUP: {
                        ti->onLeftClick.handle( Win33::TrayIconEvents::LeftClickData( Win33::System::getCursorPosition( ) ) );
                        break;
                    }
                    case WM_RBUTTONUP: {
                        ti->onRightClick.handle( Win33::TrayIconEvents::RightClickData( Win33::System::getCursorPosition( ) ) );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                return true;
            }
            default: {
                c = mCommons.at( window );
                break;
            }
        }
        switch( c->mType ) {
            case Win33::Common::Type::Window: {
                Win33::Window* w = reinterpret_cast<Win33::Window*>( c );
                switch( message ) {
                    case WM_SIZE: {
                        w->onResize.handle( Win33::WindowEvents::ResizeData( w->getSize( ) ) );
                        break;
                    }
                    case WM_MOVE: {
                        w->onMove.handle( Win33::WindowEvents::MoveData( w->getPosition( ) ) );
                        break;
                    }
                    case WM_GETMINMAXINFO: {
                        MINMAXINFO* mmi = reinterpret_cast<MINMAXINFO*>( longParameter );
                        mmi->ptMinTrackSize.x = w->getMinimumSize( ).getWidth( );
                        mmi->ptMinTrackSize.y = w->getMinimumSize( ).getHeight( );
                        mmi->ptMaxTrackSize.x = w->getMaximumSize( ).getWidth( );
                        mmi->ptMaxTrackSize.y = w->getMaximumSize( ).getHeight( );
                        break;
                    }
                    case WM_LBUTTONUP: {
                        w->onLeftClick.handle( Win33::WindowEvents::LeftClickData( Win33::System::getCursorPosition( ) ) );
                        break;
                    }
                    case WM_RBUTTONUP: {
                        w->onRightClick.handle( Win33::WindowEvents::RightClickData( Win33::System::getCursorPosition( ) ) );
                        break;
                    }
                    case WM_CLOSE: {
                        auto data = Win33::WindowEvents::CloseData( );
                        w->onClose.handle( data );
                        if( data.getCancelled( ) ) {
                            return true;
                        }
                        break;
                    }
                    case WM_DESTROY: {
                        w->onDestroy.handle( Win33::WindowEvents::DestroyData( ) );
                        EnumChildWindows( Win33::Interop::toHandle( w ), []( HWND window, LPARAM longParameter ) -> BOOL { mCommons.erase( window ); return true; }, 0 );
                        mCommons.erase( Win33::Interop::toHandle( w ) );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case Win33::Common::Type::Button: {
                Win33::Button* b = reinterpret_cast<Win33::Button*>( c );
                switch( message ) {
                    case BN_CLICKED: {
                        b->onClick.handle( Win33::ButtonEvents::ClickData( ) );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case Win33::Common::Type::CheckBox: {
                Win33::CheckBox* cb = reinterpret_cast<Win33::CheckBox*>( c );
                switch( message ) {
                    case BN_CLICKED: {
                        cb->onCheck.handle( Win33::CheckBoxEvents::CheckData( cb->getChecked( ) ) );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case Win33::Common::Type::RadioButton: {
                Win33::RadioButton* rb = reinterpret_cast<Win33::RadioButton*>( c );
                //...
                break;
            }
            case Win33::Common::Type::TextBox: {
                Win33::TextBox* tb = reinterpret_cast<Win33::TextBox*>( c );
                //...
                break;
            }
            case Win33::Common::Type::PasswordBox: {
                Win33::PasswordBox* pb = reinterpret_cast<Win33::PasswordBox*>( c );
                //...
                break;
            }
            case Win33::Common::Type::MultilineTextBox: {
                Win33::MultilineTextBox* mtb = reinterpret_cast<Win33::MultilineTextBox*>( c );
                //...
                break;
            }
            case Win33::Common::Type::GroupBox: {
                Win33::GroupBox* gb = reinterpret_cast<Win33::GroupBox*>( c );
                //...
                break;
            }
            case Win33::Common::Type::Label: {
                Win33::Label* l = reinterpret_cast<Win33::Label*>( c );
                switch( message ) {
                    case STN_DBLCLK: //double clicks have to be counted amongst single clicks due to notify style (?)
                    case STN_CLICKED: {
                        l->onClick.handle( Win33::LabelEvents::ClickData( ) );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case Win33::Common::Type::ComboBox: {
                Win33::ComboBox* cb = reinterpret_cast<Win33::ComboBox*>( c );
                //...
                break;
            }
            default: {
                break;
            }
        }
    }
    switch( message ) {
        case WM_CLOSE: {
            DestroyWindow( window );
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage( 0 );
        }
        default: {
            break;
        }
    }
    return DefWindowProc( window, message, wordParameter, longParameter );
}