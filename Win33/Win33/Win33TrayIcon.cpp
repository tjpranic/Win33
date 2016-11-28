#include "Win33TrayIcon.h"

#include <cassert>

#include "Win33Application.h"

int Win33::TrayIcon::generateID( ) {
    static int id = -1;
    return ++id;
}

Win33::TrayIcon::TrayIcon(
          Window*       parent,
    const Icon&         icon,
    const std::wstring& tooltip
):
mParent      ( parent ),
mContextMenu ( nullptr )
{
    assert( parent != nullptr );
    assert( tooltip.length( ) <= 128 );
    
    mNID = { sizeof( NOTIFYICONDATA ) };
    mNID.hWnd             = parent->mHandle;
    mNID.uID              = generateID( );
    mNID.uFlags           = NIF_MESSAGE | NIF_ICON | NIF_TIP;
    mNID.uCallbackMessage = WM_TRAYICON;
    mNID.hIcon            = icon.mHandle;
    
    for( auto i = 0; i != tooltip.size( ); ++i ) {
        mNID.szTip[i] = tooltip[i];
    }
    
    mNID.uVersion = NOTIFYICON_VERSION;
    
    Shell_NotifyIcon( NIM_ADD, &mNID );
    
    Application::mTrayIcons[mNID.uID] = this;
}
Win33::TrayIcon::TrayIcon( TrayIcon&& other )
:
leftClick    ( std::move( other.leftClick ) ),
rightClick   ( std::move( other.rightClick ) ),
mParent      ( other.mParent ),
mNID         ( std::move( other.mNID ) ),
mContextMenu ( other.mContextMenu )
{
    Application::mTrayIcons[mNID.uID] = this;
}
Win33::TrayIcon& Win33::TrayIcon::operator=( TrayIcon&& other ) {
    leftClick    = std::move( other.leftClick );
    rightClick   = std::move( other.rightClick );
    mParent      = other.mParent;
    mNID         = std::move( other.mNID );
    mContextMenu = other.mContextMenu;
    Application::mTrayIcons[mNID.uID] = this;
    return *this;
}

Win33::TrayIcon::~TrayIcon( ) {
    Shell_NotifyIcon( NIM_DELETE, &mNID );
    
    Application::mTrayIcons.erase( mNID.uID );
}

void Win33::TrayIcon::setContextMenu( ContextMenu* menu ) {
    mContextMenu = menu;
}