#include "Win33Menu.h"

Win33::Menu::Menu( Win33::ContextMenu* contextMenu, const std::wstring& text )
:
mHandle   ( CreateMenu( ) ),
mParent   ( Win33::Interop::toHandle( contextMenu ) ),
mPosition ( GetMenuItemCount( mParent ) )
{
    AppendMenu( mParent, MF_POPUP, reinterpret_cast<UINT_PTR>( mHandle ), text.c_str( ) );
}
Win33::Menu::Menu( Win33::MenuBar* menuBar, const std::wstring& text )
:
mHandle   ( CreateMenu( ) ),
mParent   ( Win33::Interop::toHandle( menuBar ) ),
mPosition ( GetMenuItemCount( mParent ) )
{
    AppendMenu( mParent, MF_POPUP, reinterpret_cast<UINT_PTR>( mHandle ), text.c_str( ) );
}
Win33::Menu::Menu( Win33::Menu* menu, const std::wstring& text )
:
mHandle   ( CreateMenu( ) ),
mParent   ( Win33::Interop::toHandle( menu ) ),
mPosition ( GetMenuItemCount( mParent ) )
{
    AppendMenu( mParent, MF_POPUP, reinterpret_cast<UINT_PTR>( mHandle ), text.c_str( ) );
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