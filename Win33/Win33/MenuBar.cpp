#include "MenuBar.h"

Win33::MenuBar::MenuBar( Window* window )
:
mHandle( CreateMenu( ) )
{
    assert( window != nullptr );
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu bar." );
    }
    SetMenu( Interop::toHandle( window ), mHandle );
}