#include "Win33ContextMenu.h"

#include "Win33Application.h"

Win33::ContextMenu::ContextMenu( )
:
mLastPosition ( 0 ),
mHandle       ( CreatePopupMenu( ) ),
mMenus        ( ),
mMenuItems    ( )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create context menu." );
    }
}
Win33::ContextMenu::ContextMenu( ContextMenu&& other )
:
mLastPosition ( other.mLastPosition ),
mHandle       ( other.mHandle ),
mMenus        ( std::move( other.mMenus ) ),
mMenuItems    ( std::move( other.mMenuItems ) )
{ }
Win33::ContextMenu& Win33::ContextMenu::operator=( ContextMenu&& other ) {
    mLastPosition = other.mLastPosition;
    mHandle       = other.mHandle;
    mMenus        = std::move( other.mMenus );
    mMenuItems    = std::move( other.mMenuItems );
    return *this;
}

void Win33::ContextMenu::show( const Win33::Point& position ) {
    TrackPopupMenuEx( mHandle, TPM_TOPALIGN | TPM_LEFTALIGN, position.getX( ), position.getY( ), GetActiveWindow( ), nullptr );
}

void Win33::ContextMenu::appendSeperator( ) {
    AppendMenu( mHandle, MF_SEPARATOR, 0, nullptr );
    mLastPosition++;
}
Win33::Menu& Win33::ContextMenu::appendMenu( const std::wstring& text ) {
    mMenus.emplace_back( Win33::Menu( mHandle, mLastPosition, text ) );
    auto& menu = mMenus.back( );
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( Win33::Interop::menuToHandle( &menu ) ), text.c_str( ) );
    
    mLastPosition++;
    return menu;
}
Win33::MenuItem& Win33::ContextMenu::appendMenuItem( const std::wstring& text, bool checkable ) {
    mMenuItems.emplace_back( Win33::MenuItem( mHandle, text, checkable ) );
    auto& menuItem = mMenuItems.back( );
    
    AppendMenu( mHandle, MF_STRING, menuItem.mID, text.c_str( ) );
    
    mLastPosition++;
    return menuItem;
}