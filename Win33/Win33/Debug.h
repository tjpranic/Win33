#pragma once

#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <stdlib.h>

#include "Filesystem.h"

#if defined( _DEBUG )
    #define RELEASE_ONLY( x )
    #define DEBUG_ONLY( x ) x
#else
    #define RELEASE_ONLY( x ) x
    #define DEBUG_ONLY( x )
#endif

#define THIS_FILE ( std::path( __FILE__ ).filename( ).c_str( ) )
#define THIS_LINE ( __LINE__ )

namespace Win33::Debug {

    int dumpMemoryLeaksOnExit( );
    int dumpMemoryLeaks( );

}