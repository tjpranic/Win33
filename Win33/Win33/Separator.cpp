#include "Separator.h"

Win33::Separator::Separator( ContextMenu* contextMenu ) {
    AppendMenu( Win33::Interop::toHandle( contextMenu ), MF_SEPARATOR, 0, nullptr );
}
Win33::Separator::Separator( Menu* menu ) {
    AppendMenu( Win33::Interop::toHandle( menu ), MF_SEPARATOR, 0, nullptr );
}