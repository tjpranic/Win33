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
    ) {
        ASSERT_TRUE( window            != nullptr, L"window cannot be null." );
        ASSERT_TRUE( icon              != nullptr, L"icon cannot be null."   );
        ASSERT_TRUE( tooltip.length( ) <= 128,     L"icon cannot be null."   );

        mNID                  = { sizeof( NOTIFYICONDATA ) };
        mNID.hWnd             = *window;
        mNID.uID              = generateID( );
        mNID.uFlags           = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        mNID.uCallbackMessage = WM_TRAYICON;
        mNID.hIcon            = *icon;

        for( auto i = 0U; i != tooltip.size( ); ++i ) {
            mNID.szTip[i] = tooltip[i];
        }

        mNID.uVersion = NOTIFYICON_VERSION;

        Shell_NotifyIcon( NIM_ADD, &mNID );

        Application::get( ).mTrayIcons[mNID.uID] = this;

        window->onDestroy += [&]( ) {
            Shell_NotifyIcon( NIM_DELETE, &mNID );
            Application::get( ).mTrayIcons.erase( mNID.uID );
        };
    }

    void TrayIcon::setIcon( Icon* icon ) {
        ASSERT_TRUE( icon != nullptr, L"icon cannot be null." );
        mNID.hIcon = *icon;
        Shell_NotifyIcon( NIM_MODIFY, &mNID );
    }
    void TrayIcon::setTooltip( const std::wstring& tooltip ) {
        ASSERT_TRUE( tooltip.length( ) <= 128, L"tooltip must be 128 characters maximum." );
        ZeroMemory( mNID.szTip, 128 );
        for( auto i = 0U; i != tooltip.size( ); ++i ) {
            mNID.szTip[i] = tooltip[i];
        }
        Shell_NotifyIcon( NIM_MODIFY, &mNID );
    }

};