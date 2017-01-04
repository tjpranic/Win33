#include "Win33MenuItem.h"

#include "Win33Application.h"

int Win33::MenuItem::generateID( ) {
    static int id = 0;
    return ++id;
}

Win33::MenuItem::MenuItem( Win33::ContextMenu* contextMenu, const std::wstring& text )
:
mParent ( Win33::Interop::toHandle( contextMenu ) ),
mID     ( generateID( ) )
{
    AppendMenu( mParent, MF_STRING, mID, text.c_str( ) );
    
    Win33::Application::mMenuItems[mID] = this;
}
Win33::MenuItem::MenuItem( Win33::Menu* menu, const std::wstring& text )
:
mParent ( Win33::Interop::toHandle( menu ) ),
mID     ( generateID( ) )
{
    AppendMenu( mParent, MF_STRING, mID, text.c_str( ) );
    
    Win33::Application::mMenuItems[mID] = this;
}
Win33::MenuItem::~MenuItem( ) {
    Win33::Application::mMenuItems.erase( mID );
}

std::wstring Win33::MenuItem::getText( ) const {
    static wchar_t text[256];
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.dwTypeData   = text;
    mii.fMask        = MIIM_STRING;
    mii.fType        = MFT_STRING;
    mii.cch          = 256 - 1;
    GetMenuItemInfo( mParent, mID, false, &mii );
    return std::wstring( text );
}
bool Win33::MenuItem::getEnabled( ) const {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_STATE;
    GetMenuItemInfo( mParent, mID, false, &mii );
    return mii.fState == MFS_ENABLED;
}
bool Win33::MenuItem::getChecked( ) const {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_STATE;
    GetMenuItemInfo( mParent, mID, false, &mii );
    return mii.fState == MFS_CHECKED;
}

void Win33::MenuItem::setText( const std::wstring& text ) {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_TYPE;
    mii.dwTypeData   = const_cast<wchar_t*>( text.c_str( ) );
    SetMenuItemInfo( mParent, mID, false, &mii );
}
void Win33::MenuItem::setEnabled( bool enabled ) {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_STATE;
    mii.fState       = enabled ? MFS_ENABLED : MFS_DISABLED;
    SetMenuItemInfo( mParent, mID, false, &mii );
}
void Win33::MenuItem::setChecked( bool checked ) {
    CheckMenuItem( mParent, mID, MF_BYCOMMAND | ( checked ? MF_CHECKED : MF_UNCHECKED ) );
}