#include "Win33ContextMenu.h"

#include "Win33Application.h"

Win33::ContextMenu::ContextMenu( )
:
mHandle       ( CreatePopupMenu( ) ),
mLastPosition ( 0 )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create context menu." );
    }
}

void Win33::ContextMenu::show( Window* window, const Point& position ) {
    TrackPopupMenuEx( mHandle, TPM_TOPALIGN | TPM_LEFTALIGN, position.getX( ), position.getY( ), window->mHandle, nullptr );
}

void Win33::ContextMenu::addSeperator( ) {
    AppendMenu( mHandle, MF_SEPARATOR, 0, nullptr );
    mLastPosition++;
}
Win33::Menu& Win33::ContextMenu::addMenu( const std::wstring& text ) {
    mMenus.emplace_back( std::make_pair( mLastPosition, Menu( mHandle, mLastPosition, text ) ) );
    auto& menu = mMenus.back( ).second;
    
    mLastPosition++;
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( menu.mHandle ), text.c_str( ) );
    
    return menu;
}
Win33::MenuItem& Win33::ContextMenu::addMenuItem( const std::wstring& text, bool checkable ) {
    AppendMenu( mHandle, MF_STRING, mLastPosition, text.c_str( ) );
    
    mMenuItems.emplace_back( std::make_pair( mLastPosition, MenuItem( mHandle, mLastPosition, text, checkable ) ) );
    auto& menuItem = mMenuItems.back( ).second;
    
    Application::mMenuItems[mLastPosition] = &menuItem;
    
    mLastPosition++;
    return menuItem;
}