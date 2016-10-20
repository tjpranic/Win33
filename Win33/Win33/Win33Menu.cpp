#include "Win33Menu.h"

#include <cassert>

Win33::Menu::Menu( const std::wstring& text )
:
mHandle          ( CreateMenu( ) ),
mParent          ( nullptr ),
mPosition        ( -1 ),
mSubMenuPosition ( 0 ),
mText            ( text )
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
    if( !AppendMenu( mHandle, MF_SEPARATOR, 0, nullptr ) ) {
        throw std::runtime_error( "Unable to add separator." );
    }
    ++mSubMenuPosition;
}
void Win33::Menu::addSubMenu( Menu* menu ) {
    assert( menu->mParent == nullptr );
    if( !AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( menu->mHandle ), menu->mText.c_str( ) ) ) {
        throw std::runtime_error( "Unable to add sub menu." );
    }
    menu->mParent   = mHandle;
    menu->mPosition = mSubMenuPosition;
}
void Win33::Menu::addMenuItem( MenuItem* item ) {
    assert( item->mParent == nullptr );
    if( !AppendMenu( mHandle, MF_STRING | ( item->mEnabled ? MF_ENABLED : MF_DISABLED ), item->mID, item->mText.c_str( ) ) ) {
        throw std::runtime_error( "Unable to add menu item." );
    }
    item->mParent = mHandle;
    ++mSubMenuPosition;
}