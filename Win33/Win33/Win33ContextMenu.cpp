#include "Win33ContextMenu.h"

Win33::ContextMenu::ContextMenu( Win33::Window* window )
:
mHandle ( CreatePopupMenu( ) ),
mWindow ( window )
{
    assert( window != nullptr );
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create context menu." );
    }
}

void Win33::ContextMenu::show( const Win33::Point& position ) {
    TrackPopupMenuEx( mHandle, TPM_TOPALIGN | TPM_LEFTALIGN, position.getX( ), position.getY( ), Win33::Interop::toHandle( mWindow ), nullptr );
}