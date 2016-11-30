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
    const std::wstring&  icon,
    const std::wstring&  tooltip
):
mContextMenu( nullptr )
{
    assert( window != nullptr );
    assert( icon   != L""     );
    assert( tooltip.length( ) <= 128 );
    
    mNID                  = { sizeof( NOTIFYICONDATA ) };
    mNID.hWnd             = Win33::Interop::windowToHandle( window );
    mNID.uID              = generateID( );
    mNID.uFlags           = NIF_MESSAGE | NIF_ICON | NIF_TIP;
    mNID.uCallbackMessage = WM_TRAYICON;
    mNID.hIcon            = static_cast<HICON>( LoadImage( nullptr, icon.c_str( ), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED ) );
    
    for( auto i = 0; i != tooltip.size( ); ++i ) {
        mNID.szTip[i] = tooltip[i];
    }
    
    mNID.uVersion = NOTIFYICON_VERSION;
    
    Shell_NotifyIcon( NIM_ADD, &mNID );
    
    Win33::Application::mTrayIcons[mNID.uID] = this;
}
Win33::TrayIcon::TrayIcon( TrayIcon&& other )
:
onClick      ( std::move( other.onClick ) ),
mNID         ( std::move( other.mNID ) ),
mContextMenu ( other.mContextMenu )
{
    Win33::Application::mTrayIcons[mNID.uID] = this;
}
Win33::TrayIcon& Win33::TrayIcon::operator=( TrayIcon&& other ) {
    onClick      = std::move( other.onClick );
    mNID         = std::move( other.mNID );
    mContextMenu = other.mContextMenu;

    Win33::Application::mTrayIcons[mNID.uID] = this;
    return *this;
}
Win33::TrayIcon::~TrayIcon( ) {
    Shell_NotifyIcon( NIM_DELETE, &mNID );
    
    Win33::Application::mTrayIcons.erase( mNID.uID );
}

Win33::ContextMenu* Win33::TrayIcon::getContextMenu( ) const {
    return mContextMenu;
}

void Win33::TrayIcon::setIcon( const std::wstring& icon ) {
    assert( icon != L"" );
    mNID.hIcon = static_cast<HICON>( LoadImage( nullptr, icon.c_str( ), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED ) );
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
void Win33::TrayIcon::setContextMenu( Win33::ContextMenu* contextMenu ) {
    assert( contextMenu != nullptr );
    mContextMenu = contextMenu;
}