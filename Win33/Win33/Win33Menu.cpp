#include "Win33Menu.h"

#include "Win33Application.h"

Win33::Menu::Menu( HMENU parent, int position,  const std::wstring& text )
:
mHandle       ( CreateMenu( ) ),
mParent       ( parent ),
mPosition     ( position ),
mText         ( text ),
mLastPosition ( 0 ),
mSubMenus     ( ),
mMenuItems    ( )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu." );
    }
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

void Win33::Menu::addSeparator( ) {
    AppendMenu( mHandle, MF_SEPARATOR, 0, nullptr );
    mLastPosition++;
}
Win33::Menu& Win33::Menu::addSubMenu( const std::wstring& text ) {
    mSubMenus.emplace_back( std::make_pair( mLastPosition, Menu( mHandle, mLastPosition, text ) ) );
    auto& menu = mSubMenus.back( ).second;
    
    mLastPosition++;
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( menu.mHandle ), text.c_str( ) );
    
    return menu;
}
Win33::MenuItem& Win33::Menu::addMenuItem( const std::wstring& text, bool checkable ) {
    AppendMenu( mHandle, MF_STRING, mLastPosition, text.c_str( ) );
    
    mMenuItems.emplace_back( std::make_pair( mLastPosition, MenuItem( mHandle, mLastPosition, text, checkable ) ) );
    auto& menuItem = mMenuItems.back( ).second;
    
    Application::mMenuItems[mLastPosition] = &menuItem;
    
    mLastPosition++;
    return menuItem;
}