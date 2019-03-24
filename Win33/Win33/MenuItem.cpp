#include "MenuItem.h"

#include "Application.h"
#include "Error.h"

namespace Win33 {

    namespace {
        int generateID( ) {
            static auto id = 0U;
            return id++;
        }
    }

    MenuItem::MenuItem( ContextMenu* contextMenu, const std::wstring& text )
    :
    mParent ( nullptr ),
    mID     ( generateID( ) )
    {
        ASSERT_TRUE( contextMenu != nullptr, L"contextMenu cannot be null." );

        mParent = *contextMenu;

        AppendMenu( mParent, MF_STRING, mID, text.c_str( ) );
    
        Application::get( ).mMenuItems[mID] = this;
    }
    MenuItem::MenuItem( Menu* menu, const std::wstring& text )
    :
    mParent ( nullptr ),
    mID     ( generateID( ) )
    {
        ASSERT_TRUE( menu != nullptr, L"menu cannot be null." );

        mParent = *menu;

        AppendMenu( mParent, MF_STRING, mID, text.c_str( ) );
    
        Application::get( ).mMenuItems[mID] = this;
    }
    MenuItem::~MenuItem( ) {
        Application::get( ).mMenuItems.erase( mID );
    }

    void MenuItem::toggleChecked( ) {
        setChecked( !getChecked( ) );
    }

    std::wstring MenuItem::getText( ) const {
        static wchar_t text[256];
        MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
        mii.dwTypeData   = text;
        mii.fMask        = MIIM_STRING;
        mii.fType        = MFT_STRING;
        mii.cch          = 256 - 1;
        GetMenuItemInfo( mParent, mID, false, &mii );
        return std::wstring( text );
    }
    bool MenuItem::getEnabled( ) const {
        MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
        mii.fMask        = MIIM_STATE;
        GetMenuItemInfo( mParent, mID, false, &mii );
        return mii.fState == MFS_ENABLED;
    }
    bool MenuItem::getChecked( ) const {
        MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
        mii.fMask        = MIIM_STATE;
        GetMenuItemInfo( mParent, mID, false, &mii );
        return mii.fState == MFS_CHECKED;
    }

    void MenuItem::setText( const std::wstring& text ) {
        MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
        mii.fMask        = MIIM_TYPE;
        mii.dwTypeData   = const_cast<wchar_t*>( text.c_str( ) );
        SetMenuItemInfo( mParent, mID, false, &mii );
    }
    void MenuItem::setEnabled( bool enabled ) {
        MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
        mii.fMask        = MIIM_STATE;
        mii.fState       = enabled ? MFS_ENABLED : MFS_DISABLED;
        SetMenuItemInfo( mParent, mID, false, &mii );
    }
    void MenuItem::setChecked( bool checked ) {
        CheckMenuItem( mParent, mID, MF_BYCOMMAND | ( checked ? MF_CHECKED : MF_UNCHECKED ) );
    }

}