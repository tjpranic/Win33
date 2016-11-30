#include "Win33MenuBar.h"

Win33::MenuBar::MenuBar( )
:
mLastPosition ( 0 ),
mHandle       ( CreateMenu( ) ),
mMenus        ( )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu bar." );
    }
}
Win33::MenuBar::MenuBar( MenuBar&& other )
:
mLastPosition ( other.mLastPosition ),
mHandle       ( other.mHandle ),
mMenus        ( std::move( other.mMenus ) )
{ }
Win33::MenuBar& Win33::MenuBar::operator=( MenuBar&& other ) {
    mLastPosition = other.mLastPosition;
    mHandle       = other.mHandle;
    mMenus        = std::move( other.mMenus );
    return *this;
}

Win33::Menu& Win33::MenuBar::appendMenu( const std::wstring& text ) {
    mMenus.emplace_back( Win33::Menu( mHandle, mLastPosition, text ) );
    auto& menu = mMenus.back( );
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( Win33::Interop::menuToHandle( &menu ) ), text.c_str( ) );
    
    mLastPosition++;
    return menu;
}