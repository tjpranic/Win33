#include "Win33ContextMenu.h"

#include <cassert>

int Win33::ContextMenu::generatePosition( ) {
    static int position = -1;
    return ++position;
}

Win33::ContextMenu::ContextMenu( )
:
mHandle( CreatePopupMenu( ) )
{
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create context menu." );
    }
}

void Win33::ContextMenu::show( Window* window, const Point& position ) {
    TrackPopupMenuEx( mHandle, TPM_TOPALIGN | TPM_LEFTALIGN, position.getX( ), position.getY( ), window->mHandle, nullptr );
}

void Win33::ContextMenu::addMenu( Menu* menu ) {
    assert( !menu->mParent );
    if( !AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( menu->mHandle ), menu->mText.c_str( ) ) ) {
        throw std::runtime_error( "Unable to add menu." );
    }
    menu->mParent   = mHandle;
    menu->mPosition = generatePosition( );
}