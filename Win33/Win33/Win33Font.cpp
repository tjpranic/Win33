#include "Win33Font.h"

#include <cassert>

Win33::Font::Font( const std::wstring& font, int size, Win33::FontDecoration::Type decorations )
:
mHandle( nullptr )
{
    assert( font != L"" );
    assert( size  > 1   );
    
    mHandle = CreateFont(
        size,
        0,
        0,
        0,
        ( ( decorations & Win33::FontDecoration::Bold        ) == Win33::FontDecoration::Bold ) ? FW_BOLD : FW_DONTCARE,
        ( decorations & Win33::FontDecoration::Italic        ) == Win33::FontDecoration::Italic,
        ( decorations & Win33::FontDecoration::Underline     ) == Win33::FontDecoration::Underline,
        ( decorations & Win33::FontDecoration::Strikethrough ) == Win33::FontDecoration::Strikethrough,
        DEFAULT_CHARSET,
        OUT_OUTLINE_PRECIS,
        CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY,
        DEFAULT_PITCH,
        font.c_str( )
    );
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create font." );
    }
}
Win33::Font::Font( Font&& other )
:
mHandle( other.mHandle )
{
    other.mHandle = nullptr;
}
Win33::Font& Win33::Font::operator=( Font&& other ) {
    mHandle       = other.mHandle;
    other.mHandle = nullptr;
    return *this;
}
Win33::Font::~Font( ) {
    if( mHandle ) {
        DeleteObject( mHandle );
    }
}