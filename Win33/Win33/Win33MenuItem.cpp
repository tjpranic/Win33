#include "Win33MenuItem.h"

#include "Win33Application.h"

int Win33::MenuItem::nextID( ) {
    static int id = 0;
    return ++id;
}

Win33::MenuItem::MenuItem( HMENU parent, const std::wstring& text, bool checkable )
:
mParent    ( parent ),
mID        ( nextID( ) ),
mText      ( text ),
mCheckable ( checkable ),
mEnabled   ( true ),
mChecked   ( false )
{ }

void Win33::MenuItem::check( ) {
    if( !getChecked( ) ) {
        setChecked( true );
        mClick.handle( MenuEvents::ClickData( true ) );
    }
}
void Win33::MenuItem::uncheck( ) {
    if( getChecked( ) ) {
        setChecked( false );
        mClick.handle( MenuEvents::ClickData( false ) );
    }
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
    SetMenuItemInfo( mParent, false, false, &mii );
    mEnabled = enabled;
}
void Win33::MenuItem::setCheckable( bool checkable ) {
    CheckMenuItem( mParent, mID, MF_BYCOMMAND | ( !checkable ? MF_UNCHECKED : 0 ) );
    mCheckable = checkable;
}
void Win33::MenuItem::setChecked( bool checked ) {
    if( mCheckable ) {
        CheckMenuItem( mParent, mID, MF_BYCOMMAND | ( checked ? MF_CHECKED : MF_UNCHECKED ) );
        mChecked = checked;
    }
}

void Win33::MenuItem::addClickHandler( const MenuEvents::ClickHandler& handler ) {
    mClick.addHandler( handler );
}

void Win33::MenuItem::removeClickHandler( const MenuEvents::ClickHandler& handler ) {
    mClick.removeHandler( handler );
}