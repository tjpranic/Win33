#include "MenuBar.h"

#include "Error.h"

namespace Win33 {

    MenuBar::MenuBar( Window* window )
    :
    mHandle( CreateMenu( ) )
    {
        ASSERT_TRUE( window != nullptr, L"window cannot be null." );
        if( !mHandle ) {
            throw std::runtime_error( "Unable to create menu bar." );
        }
        SetMenu( *window, mHandle );
    }

    MenuBar::operator HMENU( ) const {
        return mHandle;
    }

}