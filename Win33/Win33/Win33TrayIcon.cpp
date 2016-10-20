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
Win33::TrayIcon::~TrayIcon( ) {
    Shell_NotifyIcon( NIM_DELETE, &mNID );
    
    Application::mTrayIcons.erase( mNID.uID );
}

Win33::ContextMenu& Win33::TrayIcon::getContextMenu( ) const {
    return *mContextMenu;
}

void Win33::TrayIcon::setContextMenu( ContextMenu* menu ) {
    mContextMenu = menu;
}

void Win33::TrayIcon::addLeftClickHandler( const TrayIconEvents::Handler& handler ) {
    mLeftClick.addHandler( handler );
}
void Win33::TrayIcon::addRightClickHandler( const TrayIconEvents::Handler& handler ) {
    mRightClick.addHandler( handler );
}

void Win33::TrayIcon::removeLeftClickHandler( const TrayIconEvents::Handler& handler ) {
    mLeftClick.removeHandler( handler );
}
void Win33::TrayIcon::removeRightClickHandler( const TrayIconEvents::Handler& handler ) {
    mRightClick.removeHandler( handler );
}