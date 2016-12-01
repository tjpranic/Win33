#include "Win33MenuItem.h"

#include "Win33Application.h"
#include "Win33Interop.h"

int Win33::MenuItem::generateID( ) {
    static int id = 0;
    return ++id;
}

Win33::MenuItem::MenuItem( Win33::ContextMenu* contextMenu, const std::wstring& text, bool checkable )
:
mParent    ( Win33::Interop::toHandle( contextMenu ) ),
mID        ( generateID( ) ),
mText      ( text ),
mCheckable ( checkable ),
mEnabled   ( true ),
mChecked   ( false )
{
    Win33::Application::mMenuItems[mID] = this;
}
Win33::MenuItem::MenuItem( Win33::Menu* menu, const std::wstring& text, bool checkable )
:
mParent    ( Win33::Interop::toHandle( menu ) ),
mID        ( generateID( ) ),
mText      ( text ),
mCheckable ( checkable ),
mEnabled   ( true ),
mChecked   ( false )
{
    Win33::Application::mMenuItems[mID] = this;
}
Win33::MenuItem::MenuItem( MenuItem&& other )
:
onClick    ( std::move( other.onClick ) ),
mParent    ( other.mParent ),
mID        ( other.mID ),
mText      ( std::move( other.mText ) ),
mCheckable ( other.mCheckable ),
mEnabled   ( other.mEnabled ),
mChecked   ( other.mChecked )
{
    other.mID  = -1;
    Win33::Application::mMenuItems[mID] = this;
}
Win33::MenuItem& Win33::MenuItem::operator=( MenuItem&& other ) {
    onClick    = std::move( other.onClick );
    mParent    = other.mParent;
    mID        = other.mID;
    mText      = std::move( other.mText );
    mCheckable = other.mCheckable;
    mEnabled   = other.mEnabled;
    mChecked   = other.mChecked;
    other.mID  = -1;
    
    Win33::Application::mMenuItems[mID] = this;
    return *this;
}
Win33::MenuItem::~MenuItem( ) {
    Win33::Application::mMenuItems.erase( mID );
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
    mText = text;
    
    MENUITEMINFO mii = { sizeof( MENUITEMINFO ) };
    mii.fMask        = MIIM_TYPE;
    mii.dwTypeData   = const_cast<wchar_t*>( text.c_str( ) );
    SetMenuItemInfo( mParent, mID, false, &mii );
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