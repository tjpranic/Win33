#include "Font.h"

#include <cassert>

#include "BitfieldOperators.h"

Win33::Font::Font( const std::wstring& font, int size, FontDecoration decorations )
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
        ( ( decorations & FontDecoration::Bold        ) == FontDecoration::Bold ) ? FW_BOLD : FW_DONTCARE,
        ( decorations & FontDecoration::Italic        ) == FontDecoration::Italic,
        ( decorations & FontDecoration::Underline     ) == FontDecoration::Underline,
        ( decorations & FontDecoration::Strikethrough ) == FontDecoration::Strikethrough,
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
Win33::Font::~Font( ) {
    if( mHandle ) {
        DeleteObject( mHandle );
    }
}