#include "Icon.h"

#include "Error.h"

namespace Win33 {

    Icon::Icon( const std::path& path )
    :
    mHandle( nullptr )
    {
        ASSERT_TRUE( !path.empty( ), L"path cannot be empty" );
        mHandle = static_cast<HICON>(
            LoadImage(
                nullptr,
                path.c_str( ),
                IMAGE_ICON,
                0,
                0,
                LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED
            )
        );
        if( !mHandle ) {
            throw EXCEPTION( L"Unable to create icon." );
        }
    }

    Icon::operator HICON( ) const {
        return mHandle;
    }

}