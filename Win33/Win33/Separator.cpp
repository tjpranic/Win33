#include "Separator.h"

#include "Error.h"

namespace Win33 {

    Separator::Separator( ContextMenu* contextMenu ) {
        ASSERT_TRUE( contextMenu != nullptr, L"contextMenu cannot be null." )
        AppendMenu( *contextMenu, MF_SEPARATOR, 0, nullptr );
    }
    Separator::Separator( Menu* menu ) {
        ASSERT_TRUE( menu != nullptr, L"menu cannot be null." )
        AppendMenu( *menu, MF_SEPARATOR, 0, nullptr );
    }

}