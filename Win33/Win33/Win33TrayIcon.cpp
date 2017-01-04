#include "Win33TrayIcon.h"

#include <cassert>

#include "Win33Application.h"
#include "Win33Interop.h"

int Win33::TrayIcon::generateID( ) {
    static int id = -1;
    return ++id;
}

Win33::TrayIcon::TrayIcon(
          Win33::Window* window,
    const Win33::Icon*   icon,
    const std::wstring&  tooltip
) {
    assert( window != nullptr );
    assert( icon   != nullptr );
    assert( tooltip.length( ) <= 128 );
    
    mNID                  = { sizeof( NOTIFYICONDATA ) };
    mNID.hWnd             = Win33::Interop::toHandle( window );
    mNID.uID              = generateID( );
    mNID.uFlags           = NIF_MESSAGE | NIF_ICON | NIF_TIP;
    mNID.uCallbackMessage = WM_TRAYICON;
    mNID.hIcon            = Win33::Interop::toHandle( icon );
    
    for( auto i = 0; i != tooltip.size( ); ++i ) {
        mNID.szTip[i] = tooltip[i];
    }
    
    mNID.uVersion = NOTIFYICON_VERSION;
    
    Shell_NotifyIcon( NIM_ADD, &mNID );
    
    Win33::Application::mTrayIcons[mNID.uID] = this;
    
    window->onDestroy += [&]( Win33::WindowEvents::DestroyData& data ) {
        Shell_NotifyIcon( NIM_DELETE, &mNID );
        Win33::Application::mTrayIcons.erase( mNID.uID );
    };
}

void Win33::TrayIcon::setIcon( const Win33::Icon* icon ) {
    assert( icon != nullptr );
    mNID.hIcon = Win33::Interop::toHandle( icon );
    Shell_NotifyIcon( NIM_MODIFY, &mNID );
}
void Win33::TrayIcon::setTooltip( const std::wstring& tooltip ) {
    assert( tooltip.length( ) <= 128 );
    ZeroMemory( mNID.szTip, 128 );
    for( auto i = 0; i != tooltip.size( ); ++i ) {
        mNID.szTip[i] = tooltip[i];
    }
    Shell_NotifyIcon( NIM_MODIFY, &mNID );
}