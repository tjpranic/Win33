#include "Application.h"

//typecast warning when using MAKEINTRESOURCE
#pragma warning( disable : 4302 )

#include "Button.h"
#include "CheckBox.h"
#include "ComboBox.h"
#include "Common.h"
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

    Application*                        Application::mInstance      = nullptr;
    HWND                                Application::mCurrentWindow = nullptr;
    std::unordered_map<HWND, Common*>   Application::mCommons;
    std::unordered_map<int,  MenuItem*> Application::mMenuItems;
    std::unordered_map<int,  TrayIcon*> Application::mTrayIcons;

    Application::Application( ) {
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

        if( !RegisterClassEx( &wcex ) ) {
            throw EXCEPTION( L"Unable to register window template." );
        }
    }

    int Application::run( ) {
        auto m = MSG { };
        while( !mCommons.empty( ) ) {
            if( PeekMessage( &m, 0, 0, 0, PM_REMOVE ) > 0 ) {
                switch( m.message ) {
                    //allow tab presses to be sent through to default dialog processing to allow tabstop cycling
                    case WM_KEYDOWN: {
                        const auto keyCode = static_cast<VirtualKeyCode>( m.wParam );
                        switch( keyCode ) {
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
                        break;
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

    LRESULT CALLBACK Application::windowProcessor( HWND windowHandle, UINT message, WPARAM wordParameter, LPARAM longParameter ) {
        if( mCommons.find( windowHandle ) != mCommons.end( ) ) {
            Common* common = nullptr;
            switch( message ) {
                case WM_COMMAND: {
                    if( longParameter ) {
                        message = HIWORD( wordParameter );
                        common = mCommons.at( reinterpret_cast<HWND>( longParameter ) );
                    }
                    else {
                        const auto menuID = static_cast<int>( wordParameter );
                        if( mMenuItems.find( menuID ) != mMenuItems.end( ) ) {
                            const auto* menuItem = mMenuItems[menuID];
                            menuItem->onClick.trigger( );
                        }
                        return true;
                    }
                    break;
                }
                case WM_TRAYICON: {
                    const auto  trayIconID = static_cast<int>( wordParameter );
                    const auto* trayIcon   = mTrayIcons[trayIconID];
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
                    return true;
                }
                default: {
                    common = mCommons.at( windowHandle );
                    break;
                }
            }
            ASSERT_TRUE( common != nullptr, L"Common cannot be null." );
            switch( common->mType ) {
                case Common::Type::Window: {
                    const auto* window = reinterpret_cast<Window*>( common );
                    switch( message ) {
                        case WM_ACTIVATE: {
                            mCurrentWindow = windowHandle;
                            break;
                        }
                        case WM_PAINT: {
                            DrawMenuBar( *window );
                            break;
                        }
                        case WM_SIZE: {
                            window->onResize.trigger( window->getSize( ) );
                            break;
                        }
                        case WM_MOVE: {
                            window->onMove.trigger( window->getPosition( ) );
                            break;
                        }
                        case WM_GETMINMAXINFO: {
                            auto* mmi = reinterpret_cast<MINMAXINFO*>( longParameter );
                            mmi->ptMinTrackSize.x = window->getMinimumSize( ).getWidth( );
                            mmi->ptMinTrackSize.y = window->getMinimumSize( ).getHeight( );
                            mmi->ptMaxTrackSize.x = window->getMaximumSize( ).getWidth( );
                            mmi->ptMaxTrackSize.y = window->getMaximumSize( ).getHeight( );
                            break;
                        }
                        case WM_LBUTTONUP: {
                            window->onLeftClick.trigger( Cursor::getPosition( ) );
                            break;
                        }
                        case WM_RBUTTONUP: {
                            window->onRightClick.trigger( Cursor::getPosition( ) );
                            break;
                        }
                        case WM_SYSKEYDOWN:
                        case WM_KEYDOWN: {
                            window->onKeyDown.trigger( Keys::virtualKeyCodeToKey( static_cast<VirtualKeyCode>( wordParameter ) ) );
                            break;
                        }
                        case WM_SYSKEYUP:
                        case WM_KEYUP: {
                            window->onKeyUp.trigger( Keys::virtualKeyCodeToKey( static_cast<VirtualKeyCode>( wordParameter ) ) );
                            break;
                        }
                        case WM_CLOSE: {
                            const auto cancelled = false;
                            window->onClose.trigger( cancelled );
                            if( cancelled ) {
                                return true;
                            }
                            break;
                        }
                        case WM_DESTROY: {
                            window->onDestroy.trigger( );
                            if( windowHandle == mCurrentWindow ) {
                                mCurrentWindow = nullptr;
                            }
                            EnumChildWindows ( *window, []( HWND window, LPARAM longParameter ) -> BOOL { mCommons.erase( window ); return true; }, 0 );
                            mCommons.erase   ( *window );
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case Common::Type::Button: {
                    const auto* button = reinterpret_cast<Button*>( common );
                    switch( message ) {
                        case BN_CLICKED: {
                            button->onClick.trigger( );
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case Common::Type::CheckBox: {
                    const auto* checkBox = reinterpret_cast<CheckBox*>( common );
                    switch( message ) {
                        case BN_CLICKED: {
                            checkBox->onCheck.trigger( checkBox->getChecked( ) );
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case Common::Type::RadioButton: {
                    const auto* radioButton = reinterpret_cast<RadioButton*>( common );
                    //...
                    break;
                }
                case Common::Type::TextBox: {
                    const auto* textBox = reinterpret_cast<TextBox*>( common );
                    //...
                    break;
                }
                case Common::Type::PasswordBox: {
                    const auto* passwordBox = reinterpret_cast<PasswordBox*>( common );
                    //...
                    break;
                }
                case Common::Type::MultilineTextBox: {
                    const auto* multilineTextBox = reinterpret_cast<MultilineTextBox*>( common );
                    //...
                    break;
                }
                case Common::Type::GroupBox: {
                    const auto* groupBox = reinterpret_cast<GroupBox*>( common );
                    //...
                    break;
                }
                case Common::Type::Label: {
                    const auto* label = reinterpret_cast<Label*>( common );
                    switch( message ) {
                        case STN_DBLCLK: //double clicks have to be counted amongst single clicks due to notify style (?)
                        case STN_CLICKED: {
                            label->onClick.trigger( );
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case Common::Type::ComboBox: {
                    const auto* comboBox = reinterpret_cast<ComboBox*>( common );
                    //...
                    break;
                }
                case Common::Type::DropDown: {
                    const auto* dropDown = reinterpret_cast<DropDown*>( common );
                    //...
                    break;
                }
                case Common::Type::ListBox: {
                    const auto* listBox = reinterpret_cast<ListBox*>( common );
                    //...
                    break;
                }
                case Common::Type::MultiSelectListBox: {
                    const auto* multiSelectListBox = reinterpret_cast<MultiSelectListBox*>( common );
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
                DestroyWindow( windowHandle );
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
        return DefWindowProc( windowHandle, message, wordParameter, longParameter );
    }

}