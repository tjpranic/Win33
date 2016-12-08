#include "Win33MenuItem.h"

#include "Win33Application.h"
#include "Win33Interop.h"

int Win33::MenuItem::generateID( ) {
    static int id = 0;
    return ++id;
}

Win33::MenuItem::MenuItem( Win33::ContextMenu* contextMenu, const std::wstring& text )
:
mParent ( Win33::Interop::toHandle( contextMenu ) ),
mID     ( Win33::MenuItem::generateID( ) ),
mText   ( text )
{
    Win33::Application::mMenuItems[mID] = this;
}
Win33::MenuItem::MenuItem( Win33::Menu* menu, const std::wstring& text )
:
mParent ( Win33::Interop::toHandle( menu ) ),
mID     ( Win33::MenuItem::generateID( ) ),
mText   ( text )
{
    Win33::Application::mMenuItems[mID] = this;
}
Win33::MenuItem::MenuItem( MenuItem&& other )
:
onClick( std::move( other.onClick ) ),
mParent( other.mParent ),
mID    ( other.mID ),
mText  ( std::move( other.mText ) )
{
    other.mID = -1;
    Win33::Application::mMenuItems[mID] = this;
}
Win33::MenuItem& Win33::MenuItem::operator=( MenuItem&& other ) {
    onClick   = std::move( other.onClick );
    mParent   = other.mParent;
    mID       = other.mID;
    mText     = std::move( other.mText );
    other.mID = -1;
    
    Win33::Application::mMenuItems[mID] = this;
    return *this;
}
Win33::MenuItem::~MenuItem( ) {
    Win33::Application::mMenuItems.erase( mID );
}

void Win33::MenuItem::toggleChecked( ) {
    setChecked( !getChecked( ) );
}

const std::wstring& Win33::MenuItem::getText( ) const {
    return mText;
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
    mText = text;
    
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