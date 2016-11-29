#include "Win33TrayIcon.h"

#include <cassert>

#include "Win33Application.h"

int Win33::TrayIcon::generateID( ) {
    static int id = -1;
    return ++id;
}

Win33::TrayIcon::TrayIcon(
          Win33::Window* parent,
    const std::wstring&  icon,
    const std::wstring&  tooltip
):
mParent      ( parent ),
mContextMenu ( nullptr ),
mIcon        ( icon )
{
    assert( parent != nullptr );
    assert( icon   != L""     );
    assert( tooltip.length( ) <= 128 );
    
    auto handle = static_cast<HICON>(
        LoadImage( nullptr, mIcon.c_str( ), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED )
    );
    
    mNID = { sizeof( NOTIFYICONDATA ) };
    mNID.hWnd             = parent->getHandle( );
    mNID.uID              = generateID( );
    mNID.uFlags           = NIF_MESSAGE | NIF_ICON | NIF_TIP;
    mNID.uCallbackMessage = WM_TRAYICON;
    mNID.hIcon            = handle;
    
    for( auto i = 0; i != tooltip.size( ); ++i ) {
        mNID.szTip[i] = tooltip[i];
    }
    
    mNID.uVersion = NOTIFYICON_VERSION;
    
    Shell_NotifyIcon( NIM_ADD, &mNID );
    
    Win33::Application::registerTrayIcon( this );
}
Win33::TrayIcon::TrayIcon( TrayIcon&& other )
:
click        ( std::move( other.click ) ),
mParent      ( other.mParent ),
mContextMenu ( other.mContextMenu ),
mIcon        ( std::move( other.mIcon ) ),
mNID         ( std::move( other.mNID ) )
{
    Win33::Application::registerTrayIcon( this );
}
Win33::TrayIcon& Win33::TrayIcon::operator=( TrayIcon&& other ) {
    click        = std::move( other.click );
    mParent      = other.mParent;
    mContextMenu = other.mContextMenu;
    mIcon        = std::move( other.mIcon );
    mNID         = std::move( other.mNID );
    
    Win33::Application::registerTrayIcon( this );
    return *this;
}
Win33::TrayIcon::~TrayIcon( ) {
    Shell_NotifyIcon( NIM_DELETE, &mNID );
    
    Win33::Application::unregisterTrayIcon( this );
}

Win33::Window* Win33::TrayIcon::getParent( ) const {
    return mParent;
}
Win33::ContextMenu* Win33::TrayIcon::getContextMenu( ) const {
    return mContextMenu;
}
const std::wstring& Win33::TrayIcon::getIcon( ) const {
    return mIcon;
}

void Win33::TrayIcon::setContextMenu( Win33::ContextMenu* contextMenu ) {
    mContextMenu = contextMenu;
}

int Win33::TrayIcon::getID( ) const {
    return mNID.uID;
}