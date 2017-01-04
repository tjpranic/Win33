#include "Win33MenuBar.h"

Win33::MenuBar::MenuBar( Win33::Window* window )
:
mHandle( CreateMenu( ) )
{
    assert( window != nullptr );
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu bar." );
    }
    SetMenu( Win33::Interop::toHandle( window ), mHandle );
}