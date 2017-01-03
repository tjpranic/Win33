#include "Win33Menu.h"

Win33::Menu::Menu( Win33::ContextMenu* contextMenu, int position,  const std::wstring& text )
:
mLastPosition ( 0 ),
mHandle       ( CreateMenu( ) ),
mParent       ( Win33::Interop::toHandle( contextMenu ) ),
mPosition     ( position ),
mSubMenus     ( ),
mMenuItems    ( )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu." );
    }
}
Win33::Menu::Menu( Win33::MenuBar* menuBar, int position,  const std::wstring& text )
:
mLastPosition ( 0 ),
mHandle       ( CreateMenu( ) ),
mParent       ( Win33::Interop::toHandle( menuBar ) ),
mPosition     ( position ),
mSubMenus     ( ),
mMenuItems    ( )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu." );
    }
}
Win33::Menu::Menu( Win33::Menu* menu, int position,  const std::wstring& text )
:
mLastPosition ( 0 ),
mHandle       ( CreateMenu( ) ),
mParent       ( Win33::Interop::toHandle( menu ) ),
mPosition     ( position ),
mSubMenus     ( ),
mMenuItems    ( )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu." );
    }
}

std::wstring Win33::Menu::getText( ) const {
    static wchar_t text[256];
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.dwTypeData   = text;
    mii.fMask        = MIIM_STRING;
    mii.fType        = MFT_STRING;
    mii.cch          = 256 - 1;
    GetMenuItemInfo( mParent, mPosition, true, &mii );
    return std::wstring( text );
}
bool Win33::Menu::getEnabled( ) const {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_STATE;
    GetMenuItemInfo( mParent, mPosition, true, &mii );
    return mii.fState == MFS_ENABLED;
}

void Win33::Menu::setText( const std::wstring& text ) {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_TYPE;
    mii.dwTypeData   = const_cast<wchar_t*>( text.c_str( ) );
    SetMenuItemInfo( mParent, mPosition, true, &mii );
}
void Win33::Menu::setEnabled( bool enabled ) {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_STATE;
    mii.fState       = enabled ? MFS_ENABLED : MFS_DISABLED;
    SetMenuItemInfo( mParent, mPosition, true, &mii );
}

void Win33::Menu::appendSeparator( ) {
    AppendMenu( mHandle, MF_SEPARATOR, 0, nullptr );
}
Win33::Menu& Win33::Menu::appendSubMenu( const std::wstring& text ) {
    mSubMenus.emplace_back( std::move( Win33::Menu( this, mLastPosition, text ) ) );
    auto& menu = mSubMenus.back( );
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( menu.mHandle ), text.c_str( ) );
    
    mLastPosition++;
    return menu;
}
Win33::MenuItem& Win33::Menu::appendMenuItem( const std::wstring& text ) {
    mMenuItems.push_back( std::move( Win33::MenuItem( this, text ) ) );
    auto& menuItem = mMenuItems.back( );
    
    AppendMenu( mHandle, MF_STRING, menuItem.mID, text.c_str( ) );
    
    mLastPosition++;
    return menuItem;
}