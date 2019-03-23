#include "Debug.h"

namespace Win33::Debug {

    int dumpMemoryLeaksOnExit( ) {
        return _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    }
    int dumpMemoryLeaks( ) {
        return _CrtDumpMemoryLeaks( );
    }

};