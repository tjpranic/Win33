#include "Win33MenuItem.h"

#include "Win33Application.h"

int Win33::MenuItem::generateID( ) {
    static int id = -1;
    return ++id;
}

Win33::MenuItem::MenuItem( const std::wstring& text, bool checkable )
:
mParent    ( nullptr ),
mID        ( generateID( ) ),
mText      ( text ),
mEnabled   ( true ),
mCheckable ( checkable ),
mChecked   ( false )
{
    Application::mMenuItems[mID] = this;
}
Win33::MenuItem::~MenuItem( ) {
    Application::mMenuItems.erase( mID );
}

void Win33::MenuItem::toggleChecked( ) {
    setChecked( !getChecked( ) );
}

const std::wstring& Win33::MenuItem::getText( ) const {
    return mText;
}
bool Win33::MenuItem::getEnabled( ) const {
    return mEnabled;
}
bool Win33::MenuItem::getCheckable( ) const {
    return mCheckable;
}
bool Win33::MenuItem::getChecked( ) const {
    return mChecked;
}

void Win33::MenuItem::setText( const std::wstring& text ) {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_TYPE;
    mii.dwTypeData   = const_cast<wchar_t*>( text.c_str( ) );
    SetMenuItemInfo( mParent, mID, false, &mii );
    mText = text;
}
void Win33::MenuItem::setEnabled( bool enabled ) {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_STATE;
    mii.fState       = enabled ? MFS_ENABLED : MFS_DISABLED;
    SetMenuItemInfo( mParent, mID, false, &mii );
    mEnabled = enabled;
}
void Win33::MenuItem::setCheckable( bool checkable ) {
    CheckMenuItem( mParent, mID, MF_BYPOSITION | ( !checkable ? MF_UNCHECKED : 0 ) );
    mCheckable = checkable;
}
void Win33::MenuItem::setChecked( bool checked ) {
    if( mCheckable ) {
        CheckMenuItem( mParent, mID, MF_BYPOSITION | ( checked ? MF_CHECKED : MF_UNCHECKED ) );
        mChecked = checked;
        mClick.handle( MenuEvents::ClickData( checked ) );
    }
}

void Win33::MenuItem::addClickHandler( const MenuEvents::ClickHandler& handler ) {
    mClick.addHandler( handler );
}

void Win33::MenuItem::removeClickHandler( const MenuEvents::ClickHandler& handler ) {
    mClick.removeHandler( handler );
}