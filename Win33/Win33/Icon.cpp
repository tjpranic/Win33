#include "Icon.h"

#include <cassert>

Win33::Icon::Icon( const std::wstring& icon )
:
mHandle( nullptr )
{
    assert( icon != L"" );
    
    mHandle = static_cast<HICON>(
        LoadImage(
            nullptr,
            icon.c_str( ),
            IMAGE_ICON,
            0,
            0,
            LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED
        )
    );
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create icon." );
    }
}