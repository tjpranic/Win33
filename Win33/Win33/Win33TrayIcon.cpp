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
    mNID.hIcon            = Win33::Interop::toHandle( icon ); //static_cast<HICON>( LoadImage( nullptr, icon.c_str( ), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED ) );
    
    for( auto i = 0; i != tooltip.size( ); ++i ) {
        mNID.szTip[i] = tooltip[i];
    }
    
    mNID.uVersion = NOTIFYICON_VERSION;
    
    Shell_NotifyIcon( NIM_ADD, &mNID );
    
    Win33::Application::mTrayIcons[mNID.uID] = this;
    
    window->onClose += [&]( ) {
        Shell_NotifyIcon( NIM_DELETE, &mNID );
        Win33::Application::mTrayIcons.erase( mNID.uID );
    };
}
Win33::TrayIcon::TrayIcon( TrayIcon&& other )
:
onLeftClick  ( std::move( other.onLeftClick ) ),
onRightClick ( std::move( other.onRightClick ) ),
mNID         ( std::move( other.mNID ) )
{
    Win33::Application::mTrayIcons[mNID.uID] = this;
}
Win33::TrayIcon& Win33::TrayIcon::operator=( TrayIcon&& other ) {
    onLeftClick  = std::move( other.onLeftClick );
    onRightClick = std::move( other.onRightClick );
    mNID         = std::move( other.mNID );
    
    Win33::Application::mTrayIcons[mNID.uID] = this;
    return *this;
}

void Win33::TrayIcon::setIcon( const Win33::Icon* icon ) {
    //assert( icon != L"" );
    //mNID.hIcon = static_cast<HICON>( LoadImage( nullptr, icon.c_str( ), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED ) );
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