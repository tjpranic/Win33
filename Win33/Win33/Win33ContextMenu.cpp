#include "Win33ContextMenu.h"

#include "Win33Application.h"
#include "Win33Window.h"
#include "Win33Utility.h"

Win33::ContextMenu::ContextMenu( Win33::Window* window )
:
mLastPosition ( 0 ),
mHandle       ( CreatePopupMenu( ) ),
mWindow       ( window ),
mMenus        ( ),
mMenuItems    ( )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create context menu." );
    }
    
    window->onClose += [&]( ) {
        mMenus.clear( );
        mMenuItems.clear( );
    };
}
Win33::ContextMenu::ContextMenu( ContextMenu&& other )
:
mLastPosition ( other.mLastPosition ),
mHandle       ( other.mHandle ),
mWindow       ( other.mWindow ),
mMenus        ( std::move( other.mMenus ) ),
mMenuItems    ( std::move( other.mMenuItems ) )
{ }
Win33::ContextMenu& Win33::ContextMenu::operator=( ContextMenu&& other ) {
    mLastPosition = other.mLastPosition;
    mHandle       = other.mHandle;
    mWindow       = other.mWindow;
    mMenus        = std::move( other.mMenus );
    mMenuItems    = std::move( other.mMenuItems );
    return *this;
}

void Win33::ContextMenu::show( const Win33::Point& position ) {
    TrackPopupMenuEx( mHandle, TPM_TOPALIGN | TPM_LEFTALIGN, position.getX( ), position.getY( ), Win33::Interop::toHandle( mWindow ), nullptr );
}

void Win33::ContextMenu::appendSeperator( ) {
    AppendMenu( mHandle, MF_SEPARATOR, 0, nullptr );
    mLastPosition++;
}
Win33::Menu& Win33::ContextMenu::appendMenu( const std::wstring& text ) {
    mMenus.push_back( std::move( Win33::Menu( this, mLastPosition, text ) ) );
    auto& menu = mMenus.back( );
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( Win33::Interop::toHandle( &menu ) ), text.c_str( ) );
    
    mLastPosition++;
    return menu;
}
Win33::MenuItem& Win33::ContextMenu::appendMenuItem( const std::wstring& text ) {
    mMenuItems.push_back( std::move( Win33::MenuItem( this, text ) ) );
    auto& menuItem = mMenuItems.back( );
    
    AppendMenu( mHandle, MF_STRING, menuItem.mID, text.c_str( ) );
    
    mLastPosition++;
    return menuItem;
}