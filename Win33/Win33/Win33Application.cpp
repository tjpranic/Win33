#include "Win33Application.h"

#include "Win33Window.h"
#include "Win33Button.h"
#include "Win33CheckBox.h"
#include "Win33RadioButton.h"
#include "Win33TextBox.h"
#include "Win33PasswordBox.h"
#include "Win33MultilineTextBox.h"
#include "Win33Label.h"
#include "Win33GroupBox.h"
#include "Win33TrayIcon.h"

Win33::Application*                        Win33::Application::mInstance = nullptr;
std::unordered_map<HWND, Win33::Platform*> Win33::Application::mWindows;
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
    wcex.lpfnWndProc   = &Application::windowProcessor;
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
    while( !mWindows.empty( ) ) {
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

LRESULT CALLBACK Win33::Application::windowProcessor( HWND window, UINT message, WPARAM wordParameter, LPARAM longParameter ) {
    if( mWindows.find( window ) != mWindows.end( ) ) {
        Win33::Platform* p  = nullptr;
        switch( message ) {
            case WM_COMMAND: {
                if( longParameter ) {
                    message = HIWORD( wordParameter );
                    p = mWindows.at( reinterpret_cast<HWND>( longParameter ) );
                }
                else {
                    
                    auto menuID   = static_cast<int>( wordParameter );
                    auto menuItem = mMenuItems[menuID];
                    if( menuItem->mCheckable ) {
                        menuItem->setChecked( !menuItem->getChecked( ) );
                        menuItem->mClick.handle( MenuEvents::ClickData( false ) );
                    }
                    else {
                        menuItem->mClick.handle( MenuEvents::ClickData( false ) );
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
                        ti->mLeftClick.handle( );
                        break;
                    }
                    case WM_RBUTTONUP: {
                        POINT p;
                        GetCursorPos( &p );
                        if( ti->mContextMenu ) {
                            ti->mContextMenu->show( ti->mParent, { p.x, p.y } );
                        }
                        ti->mRightClick.handle( );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                return true;
            }
            default: {
                p = mWindows.at( window );
                break;
            }
        }
        switch( p->mType ) {
            case Platform::Type::Window: {
                Win33::Window* w = reinterpret_cast<Win33::Window*>( p );
                switch( message ) {
                    case WM_IDLE: {
                        w->mIdle.handle( );
                        break;
                    }
                    case WM_SIZE: {
                        w->mResize.handle( WindowEvents::ResizeData( { w->getWidth( ), w->getHeight( ) } ) );
                        break;
                    }
                    case WM_MOVE: {
                        w->mMove.handle( WindowEvents::MoveData( { w->getX( ), w->getY( ) } ) );
                        break;
                    }
                    case WM_GETMINMAXINFO: {
                        MINMAXINFO* mmi = reinterpret_cast<MINMAXINFO*>( longParameter );
                        mmi->ptMinTrackSize.x = w->mMinimumSize.getWidth( );
                        mmi->ptMinTrackSize.y = w->mMinimumSize.getHeight( );
                        mmi->ptMaxTrackSize.x = w->mMaximumSize.getWidth( );
                        mmi->ptMaxTrackSize.y = w->mMaximumSize.getHeight( );
                        break;
                    }
                    case WM_RBUTTONUP: {
                        POINT p;
                        GetCursorPos( &p );
                        if( w->mContextMenu ) {
                            w->mContextMenu->show( w, { p.x, p.y } );
                        }
                        break;
                    }
                    case WM_CLOSE: {
                        if( w->mParent ) {
                            w->mParent->mChildren.erase( std::remove( w->mParent->mChildren.begin( ), w->mParent->mChildren.end( ), w ) );
                        }
                        w->mClose.handle( );
                        for( auto& c = w->mChildren.begin( ); c != w->mChildren.end( ); ++c ) {
                            DestroyWindow  ( ( *c )->mHandle );
                            mWindows.erase ( ( *c )->mHandle );
                        }
                        mWindows.erase( w->mHandle );
                        break;
                    }
                }
                break;
            }
            case Platform::Type::Button: {
                Win33::Button* b = reinterpret_cast<Win33::Button*>( p );
                switch( message ) {
                    case BN_CLICKED: {
                        b->mClick.handle( );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case Platform::Type::CheckBox: {
                Win33::CheckBox* cb = reinterpret_cast<Win33::CheckBox*>( p );
                switch( message ) {
                    case BN_CLICKED: {
                        cb->mCheck.handle( CheckBoxEvents::CheckData( cb->getChecked( ) ) );
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case Platform::Type::RadioButton: {
                Win33::RadioButton* rb = reinterpret_cast<Win33::RadioButton*>( p );
                //...
                break;
            }
            case Platform::Type::TextBox: {
                Win33::TextBox* tb = reinterpret_cast<Win33::TextBox*>( p );
                //...
                break;
            }
            case Platform::Type::PasswordBox: {
                Win33::PasswordBox* pb = reinterpret_cast<Win33::PasswordBox*>( p );
                //...
                break;
            }
            case Platform::Type::MultilineTextBox: {
                Win33::MultilineTextBox* mtb = reinterpret_cast<Win33::MultilineTextBox*>( p );
                //...
                break;
            }
            case Platform::Type::GroupBox: {
                Win33::GroupBox* gb = reinterpret_cast<Win33::GroupBox*>( p );
                //...
                break;
            }
            case Platform::Type::Label: {
                Win33::Label* l = reinterpret_cast<Win33::Label*>( p );
                switch( message ) {
                    case STN_DBLCLK: //double clicks have to be counted amongst single clicks due to notify style (?)
                    case STN_CLICKED: {
                        l->mClick.handle( );
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