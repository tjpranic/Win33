#include "Win33Icon.h"

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
Win33::Icon::Icon( Icon&& other )
:
mHandle( other.mHandle )
{
    other.mHandle = nullptr;
}
Win33::Icon& Win33::Icon::operator=( Icon&& other ) {
    mHandle       = other.mHandle;
    other.mHandle = nullptr;
    return *this;
}