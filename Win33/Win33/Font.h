#pragma once

#include <Windows.h>

#include "Filesystem.h"

namespace Win33 {

    enum class FontDecoration : int {
        None          = 0,
        Bold          = 1,
        Italic        = 2,
        Underline     = 4,
        Strikethrough = 8
    };

    class Font {
    public:
        Font(
            const std::path&     path,
                  int            size,
                  FontDecoration decorations = FontDecoration::None
        );
        Font            ( )                    = delete;
        Font            ( const Font&  other ) = default;
        Font            (       Font&& other ) = default;
        Font& operator= ( const Font&  other ) = default;
        Font& operator= (       Font&& other ) = default;
        ~Font           ( );

        operator HFONT( ) const;

    private:
        HFONT mHandle;
    };

}