#include "Win33ContextMenu.h"

Win33::ContextMenu::ContextMenu( Win33::Window* window )
:
mLastPosition ( 0 ),
mHandle       ( CreatePopupMenu( ) ),
mWindow       ( window ),
mMenus        ( ),
mMenuItems    ( )
{
    assert( window != nullptr );
    
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create context menu." );
    }
    
    window->onClose += [&]( Win33::WindowEvents::CloseData& data ) {
        mMenus.clear( );
        mMenuItems.clear( );
    };
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