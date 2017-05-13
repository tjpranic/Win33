#include "ContextMenu.h"

Win33::ContextMenu::ContextMenu( Window* window )
:
mHandle ( CreatePopupMenu( ) ),
mWindow ( window )
{
    assert( window != nullptr );
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create context menu." );
    }
}

void Win33::ContextMenu::show( const Point& position ) {
    TrackPopupMenuEx( mHandle, TPM_TOPALIGN | TPM_LEFTALIGN, position.getX( ), position.getY( ), Interop::toHandle( mWindow ), nullptr );
}