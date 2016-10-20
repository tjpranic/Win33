#include "Win33MenuBar.h"

#include <cassert>

int Win33::MenuBar::generatePosition( ) {
    static int position = -1;
    return ++position;
}

Win33::MenuBar::MenuBar( )
:
mHandle( CreateMenu( ) )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu bar." );
    }
}

void Win33::MenuBar::addMenu( Menu* menu ) {
    assert( menu->mParent == nullptr );
    if( !AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( menu->mHandle ), menu->mText.c_str( ) ) ) {
        throw std::runtime_error( "Unable to add menu." );
    }
    menu->mParent   = mHandle;
    menu->mPosition = generatePosition( );
}