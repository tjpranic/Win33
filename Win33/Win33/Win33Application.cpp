#include "Win33Application.h"

#include "Win33System.h"
#include "Win33Window.h"
#include "Win33Button.h"
#include "Win33CheckBox.h"
#include "Win33RadioButton.h"
#include "Win33TextBox.h"
#include "Win33PasswordBox.h"
#include "Win33MultilineTextBox.h"
#include "Win33Label.h"
#include "Win33GroupBox.h"

Win33::Application*                        Win33::Application::mInstance = nullptr;
std::unordered_map<HWND, Win33::Platform*> Win33::Application::mPlatforms;
std::unordered_map<int,  Win33::MenuItem*> Win33::Application::mMenuItems;
std::unordered_map<int,  Win33::TrayIcon*> Win33::Application::mTrayIcons;

Win33::Application::Application( ) {
    if( mInstance ) {
        throw std::runtime_error( "Application already initialized." );
    }
    mInstance = this;
    
    WNDCLASSEX wcex    = { };
    wcex.cbSize        = sizeof( WNDCLASSEX );
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
    MSG m = { };
    while( !mPlatforms.empty( ) ) {
        if( PeekMessage( &m, 0, 0, 0, PM_REMOVE ) > 0 ) {
            TranslateMessage( &m );
            DispatchMessage( &m );
        }
        else {
            SendMessage( m.hwnd, WM_IDLE, 0, 0 );
        }
    }
    return static_cast<int>( m.wParam );
}

void Win33::Application::registerPlatform( Win33::Platform* platform ) {
    mPlatforms[platform->getHandle( )] = platform;
}
void Win33::Application::registerMenuItem( Win33::MenuItem* menuItem ) {
    mMenuItems[menuItem->getID( )] = menuItem;
}
void Win33::Application::registerTrayIcon( Win33::TrayIcon* trayIcon ) {
    mTrayIcons[trayIcon->getID( )] = trayIcon;
}

void Win33::Application::unregisterPlatform( Win33::Platform* platform ) {
    mPlatforms.erase( platform->getHandle( ) );
}
void Win33::Application::unregisterMenuItem( Win33::MenuItem* menuItem ) {
    mMenuItems.erase( menuItem->getID( ) );
}
void Win33::Application::unregisterTrayIcon( Win33::TrayIcon* trayIcon ) {
    mTrayIcons.erase( trayIcon->getID( ) );
}

LRESULT CALLBACK Win33::Application::windowProcessor( HWND window, UINT message, WPARAM wordParameter, LPARAM longParameter ) {
    if( mPlatforms.find( window ) != mPlatforms.end( ) ) {
        Win33::Platform* p  = nullptr;
        switch( message ) {
            case WM_COMMAND: {
                if( longParameter ) {
                    message = HIWORD( wordParameter );
                    p = mPlatforms.at( reinterpret_cast<HWND>( longParameter ) );
                }
                else {
                    auto menuID   = static_cast<int>( wordParameter );
                    auto menuItem = mMenuItems[menuID];
                    if( menuItem->getCheckable( ) ) {
                        menuItem->setChecked( !menuItem->getChecked( ) );
                        menuItem->click.handle( MenuItemEvents::ClickData( menuItem->getChecked( ) ) );
                    }
                    else {
                        menuItem->click.handle( MenuItemEvents::ClickData( false ) );
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
                        ti->click.handle( );
                        break;
                    }
                    case WM_RBUTTONUP: {
                        if( ti->getContextMenu( ) ) {
                            ti->getContextMenu( )->show( ti->getParent( ) );
                        }
                        break;
                        break;
                    }
                    default: {
                        break;
                    }
                }
                return true;
            }
            default: {
                p = mPlatforms.at( window );
                break;
            }
        }
        switch( p->getType( ) ) {
            case Win33::Platform::Type::Window: {
                Win33::Window* w = reinterpret_cast<Win33::Window*>( p );
                switch( message ) {
                    case WM_IDLE: {
                        w->idle.handle( );
                        break;
                    }
                    case WM_SIZE: {
                        w->resize.handle( WindowEvents::ResizeData( { w->getWidth( ), w->getHeight( ) } ) );
                        break;
                    }
                    case WM_MOVE: {
                        w->move.handle( WindowEvents::MoveData( { w->getX( ), w->getY( ) } ) );
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
                    case WM_RBUTTONUP: {
                        if( w->getContextMenu( ) ) {
                            w->getContextMenu( )->show( w );
                        }
                        break;
                    }
                    case WM_CLOSE: {
                        w->close.handle( );
                        break;
                    }
                    case WM_DESTROY: {
                        EnumChildWindows( w->getHandle( ), childWindowDestroyer, 0 );
                        mPlatforms.erase( w->getHandle( ) );
                        break;
                    }
                }
                break;
            }
            case Win33::Platform::Type::Button: {
                Win33::Button* b = reinterpret_cast<Win33::Button*>( p );
                switch( message ) {
                    case BN_CLICKED: {
                        b->click.handle( );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case Win33::Platform::Type::CheckBox: {
                Win33::CheckBox* cb = reinterpret_cast<Win33::CheckBox*>( p );
                switch( message ) {
                    case BN_CLICKED: {
                        cb->check.handle( CheckBoxEvents::CheckData( cb->getChecked( ) ) );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case Win33::Platform::Type::RadioButton: {
                Win33::RadioButton* rb = reinterpret_cast<Win33::RadioButton*>( p );
                //...
                break;
            }
            case Win33::Platform::Type::TextBox: {
                Win33::TextBox* tb = reinterpret_cast<Win33::TextBox*>( p );
                //...
                break;
            }
            case Win33::Platform::Type::PasswordBox: {
                Win33::PasswordBox* pb = reinterpret_cast<Win33::PasswordBox*>( p );
                //...
                break;
            }
            case Win33::Platform::Type::MultilineTextBox: {
                Win33::MultilineTextBox* mtb = reinterpret_cast<Win33::MultilineTextBox*>( p );
                //...
                break;
            }
            case Win33::Platform::Type::GroupBox: {
                Win33::GroupBox* gb = reinterpret_cast<Win33::GroupBox*>( p );
                //...
                break;
            }
            case Win33::Platform::Type::Label: {
                Win33::Label* l = reinterpret_cast<Win33::Label*>( p );
                switch( message ) {
                    case STN_DBLCLK: //double clicks have to be counted amongst single clicks due to notify style (?)
                    case STN_CLICKED: {
                        l->click.handle( );
                        break;
                    }
                    default: {
                        break;
                    }
                }
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
            break;
        }
    }
    return DefWindowProc( window, message, wordParameter, longParameter );
}
BOOL CALLBACK Win33::Application::childWindowDestroyer( HWND hwnd, LPARAM lParam ) {
    mPlatforms.erase( hwnd );
    return true;
}