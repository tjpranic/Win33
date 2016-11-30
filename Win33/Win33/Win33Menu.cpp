#include "Win33Menu.h"

#include "Win33Application.h"

Win33::Menu::Menu( HMENU parent, int position,  const std::wstring& text )
:
mLastPosition ( 0 ),
mHandle       ( CreateMenu( ) ),
mParent       ( parent ),
mPosition     ( position ),
mText         ( text ),
mSubMenus     ( ),
mMenuItems    ( )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu." );
    }
}
Win33::Menu::Menu( Menu&& other )
:
mLastPosition ( other.mLastPosition ),
mHandle       ( other.mHandle ),
mParent       ( other.mParent ),
mPosition     ( other.mPosition ),
mText         ( std::move( other.mText ) ),
mSubMenus     ( std::move( other.mSubMenus ) ),
mMenuItems    ( std::move( other.mMenuItems ) )
{ }
Win33::Menu& Win33::Menu::operator=( Menu&& other ) {
    mLastPosition = other.mLastPosition;
    mHandle       = other.mHandle;
    mParent       = other.mParent;
    mPosition     = other.mPosition;
    mText         = std::move( other.mText );
    mSubMenus     = std::move( other.mSubMenus );
    mMenuItems    = std::move( other.mMenuItems );
    return *this;
}

std::wstring Win33::Menu::getText( ) const {
    static wchar_t text[256];
    GetMenuString( mParent, mPosition, text, 256, MF_BYPOSITION );
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
    mSubMenus.emplace_back( Win33::Menu( mHandle, mLastPosition, text ) );
    auto& menu = mSubMenus.back( );
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( menu.mHandle ), text.c_str( ) );
    
    mLastPosition++;
    return menu;
}
Win33::MenuItem& Win33::Menu::appendMenuItem( const std::wstring& text, bool checkable ) {
    mMenuItems.emplace_back( Win33::MenuItem( mHandle, text, checkable ) );
    auto& menuItem = mMenuItems.back( );
    
    AppendMenu( mHandle, MF_STRING, menuItem.mID, text.c_str( ) );
    
    mLastPosition++;
    return menuItem;
}