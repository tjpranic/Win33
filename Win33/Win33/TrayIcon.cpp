#include "TrayIcon.h"

#include "Application.h"
#include "Error.h"

namespace Win33 {

    namespace {
        int generateID( ) {
            static auto id = 0U;
            return id++;
        }
    }

    TrayIcon::TrayIcon(
              Window*       window,
              Icon*         icon,
        const std::wstring& tooltip
    ):
    mNotifyIconData( )
    {
        ASSERT_TRUE( window            != nullptr, L"window cannot be null." );
        ASSERT_TRUE( icon              != nullptr, L"icon cannot be null."   );
        ASSERT_TRUE( tooltip.length( ) <= 128,     L"icon cannot be null."   );

        mNotifyIconData                  = { sizeof( NOTIFYICONDATA ) };
        mNotifyIconData.hWnd             = *window;
        mNotifyIconData.uID              = generateID( );
        mNotifyIconData.uFlags           = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        mNotifyIconData.uCallbackMessage = WM_TRAYICON;
        mNotifyIconData.hIcon            = *icon;

        for( auto i = 0U; i != tooltip.size( ); ++i ) {
            mNotifyIconData.szTip[i] = tooltip[i];
        }

        mNotifyIconData.uVersion = NOTIFYICON_VERSION;

        Shell_NotifyIcon( NIM_ADD, &mNotifyIconData );

        Application::get( ).mTrayIcons[mNotifyIconData.uID] = this;

        window->onDestroy += [&]( ) {
            Shell_NotifyIcon( NIM_DELETE, &mNotifyIconData );
            Application::get( ).mTrayIcons.erase( mNotifyIconData.uID );
        };
    }

    void TrayIcon::setIcon( Icon* icon ) {
        ASSERT_TRUE( icon != nullptr, L"icon cannot be null." );
        mNotifyIconData.hIcon = *icon;
        Shell_NotifyIcon( NIM_MODIFY, &mNotifyIconData );
    }
    void TrayIcon::setTooltip( const std::wstring& tooltip ) {
        ASSERT_TRUE( tooltip.length( ) <= 128, L"tooltip must be 128 characters maximum." );
        ZeroMemory( mNotifyIconData.szTip, 128 );
        for( auto i = 0U; i != tooltip.size( ); ++i ) {
            mNotifyIconData.szTip[i] = tooltip[i];
        }
        Shell_NotifyIcon( NIM_MODIFY, &mNotifyIconData );
    }

};