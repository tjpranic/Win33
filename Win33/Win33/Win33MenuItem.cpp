#include "Win33MenuItem.h"

Win33::MenuItem::MenuItem( HMENU parent, int position, const std::wstring& text, bool checkable )
:
mParent    ( parent ),
mPosition  ( position ),
mText      ( text ),
mCheckable ( checkable ),
mEnabled   ( true ),
mChecked   ( false )
{ }

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
    SetMenuItemInfo( mParent, mPosition, true, &mii );
    mText = text;
}
void Win33::MenuItem::setEnabled( bool enabled ) {
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_STATE;
    mii.fState       = enabled ? MFS_ENABLED : MFS_DISABLED;
    SetMenuItemInfo( mParent, mPosition, true, &mii );
    mEnabled = enabled;
}
void Win33::MenuItem::setCheckable( bool checkable ) {
    CheckMenuItem( mParent, mPosition, MF_BYPOSITION | ( !checkable ? MF_UNCHECKED : 0 ) );
    mCheckable = checkable;
}
void Win33::MenuItem::setChecked( bool checked ) {
    if( mCheckable ) {
        CheckMenuItem( mParent, mPosition, MF_BYPOSITION | ( checked ? MF_CHECKED : MF_UNCHECKED ) );
        mChecked = checked;
    }
}

void Win33::MenuItem::addClickHandler( const MenuEvents::ClickHandler& handler ) {
    mClick.addHandler( handler );
}

void Win33::MenuItem::removeClickHandler( const MenuEvents::ClickHandler& handler ) {
    mClick.removeHandler( handler );
}