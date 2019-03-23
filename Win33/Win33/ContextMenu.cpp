#include "ContextMenu.h"

#include "Error.h"

namespace Win33 {

    ContextMenu::ContextMenu( Window* window )
    :
    mHandle ( CreatePopupMenu( ) ),
    mWindow ( window )
    {
        ASSERT_TRUE( window != nullptr, L"window cannot be null." );
        if( !mHandle ) {
            throw EXCEPTION( L"Unable to create context menu." );
        }
    }

    void ContextMenu::show( const Point& position ) {
        ASSERT_TRUE( mWindow != nullptr, L"mWindow cannot be null."  );
        TrackPopupMenuEx( mHandle, TPM_TOPALIGN | TPM_LEFTALIGN, position.getX( ), position.getY( ), *mWindow, nullptr );
    }

    ContextMenu::operator HMENU( ) const {
        return mHandle;
    }

}