#include "Font.h"

#include "BitfieldOperators.h"
#include "Error.h"

namespace Win33 {

    Font::Font( const std::path& path, int size, FontDecoration decorations )
    :
    mHandle( nullptr )
    {
        ASSERT_TRUE( path.empty( ), L"path cannot be empty."       );
        ASSERT_TRUE( size > 1,      L"size must be greater than 1" );
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
            path.c_str( )
        );
        if( !mHandle ) {
            throw EXCEPTION( L"Unable to create font." );
        }
    }
    Font::~Font( ) {
        if( mHandle ) {
            DeleteObject( mHandle );
        }
    }

    Font::operator HFONT( ) const {
        return mHandle;
    }

}