#include "Win33Icon.h"

Win33::Icon::Icon( )
:
mHandle   ( LoadIcon( nullptr, MAKEINTRESOURCE( IDI_APPLICATION ) ) ),
mFilepath ( L"" )
{ }
Win33::Icon::Icon( const std::wstring& filepath )
:
mHandle   ( nullptr ),
mFilepath ( filepath )
{
    mHandle = static_cast<HICON>( LoadImage( nullptr, filepath.c_str( ), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED ) );
}