#include "Menu.h"

#include "Error.h"

namespace Win33 {

    Menu::Menu( ContextMenu* contextMenu, const std::wstring& text )
    :
    mHandle   ( CreateMenu( ) ),
    mParent   ( nullptr ),
    mPosition ( GetMenuItemCount( mParent ) )
    {
        ASSERT_TRUE( contextMenu != nullptr, L"contextMenu cannot be null." );

        mParent = *contextMenu;

        AppendMenu( mParent, MF_POPUP, reinterpret_cast<UINT_PTR>( mHandle ), text.c_str( ) );
    }
    Menu::Menu( MenuBar* menuBar, const std::wstring& text )
    :
    mHandle   ( CreateMenu( ) ),
    mParent   ( *menuBar ),
    mPosition ( GetMenuItemCount( mParent ) )
    {
        ASSERT_TRUE( menuBar != nullptr, L"menuBar cannot be null." );

        mParent = *menuBar;

        AppendMenu( mParent, MF_POPUP, reinterpret_cast<UINT_PTR>( mHandle ), text.c_str( ) );
    }
    Menu::Menu( Menu* menu, const std::wstring& text )
    :
    mHandle   ( CreateMenu( ) ),
    mParent   ( *menu ),
    mPosition ( GetMenuItemCount( mParent ) )
    {
        ASSERT_TRUE( menu != nullptr, L"menu cannot be null." );

        mParent = *menu;

        AppendMenu( mParent, MF_POPUP, reinterpret_cast<UINT_PTR>( mHandle ), text.c_str( ) );
    }

    std::wstring Menu::getText( ) const {
        static wchar_t text[256];
        MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
        mii.dwTypeData   = text;
        mii.fMask        = MIIM_STRING;
        mii.fType        = MFT_STRING;
        mii.cch          = 256 - 1;
        GetMenuItemInfo( mParent, mPosition, true, &mii );
        return std::wstring( text );
    }
    bool Menu::getEnabled( ) const {
        MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
        mii.fMask        = MIIM_STATE;
        GetMenuItemInfo( mParent, mPosition, true, &mii );
        return mii.fState == MFS_ENABLED;
    }

    void Menu::setText( const std::wstring& text ) {
        MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
        mii.fMask        = MIIM_TYPE;
        mii.dwTypeData   = const_cast<wchar_t*>( text.c_str( ) );
        SetMenuItemInfo( mParent, mPosition, true, &mii );
    }
    void Menu::setEnabled( bool enabled ) {
        MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
        mii.fMask        = MIIM_STATE;
        mii.fState       = enabled ? MFS_ENABLED : MFS_DISABLED;
        SetMenuItemInfo( mParent, mPosition, true, &mii );
    }

    Menu::operator HMENU( ) const {
        return mHandle;
    }

}