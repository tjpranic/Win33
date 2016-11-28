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
Win33::MenuBar::MenuBar( MenuBar&& other )
:
mHandle       ( other.mHandle ),
mLastPosition ( other.mLastPosition ),
mMenus        ( std::move( other.mMenus ) )
{ }
Win33::MenuBar& Win33::MenuBar::operator=( MenuBar&& other ) {
    mHandle       = other.mHandle;
    mLastPosition = other.mLastPosition;
    mMenus        = std::move( other.mMenus );
    return *this;
}

Win33::Menu& Win33::MenuBar::appendMenu( const std::wstring& text ) {
    mMenus.emplace_back( Menu( mHandle, mLastPosition, text ) );
    auto& menu = mMenus.back( );
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( menu.mHandle ), text.c_str( ) );
    
    mLastPosition++;
    return menu;
}