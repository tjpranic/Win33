#include "Win33MenuBar.h"

Win33::MenuBar::MenuBar( )
:
mHandle       ( CreateMenu( ) ),
mLastPosition ( 0 ),
mMenus        ( )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu bar." );
    }
}

Win33::Menu& Win33::MenuBar::addMenu( const std::wstring& text ) {
    mMenus.emplace_back( Menu( mHandle, mLastPosition, text ) );
    auto& menu = mMenus.back( );
    
    mLastPosition++;
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( menu.mHandle ), text.c_str( ) );
    
    return menu;
}