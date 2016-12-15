#pragma once

#include <string>

#include "Win33Interop.h"

namespace Win33 {
    
    namespace FontDecoration {
        enum Type {
            None          = 0,
            Bold          = 1,
            Italic        = 2,
            Underline     = 4,
            Strikethrough = 8
        };
    };
    
    class Font {
    public:
        Font            ( ) = delete;
        Font            ( const std::wstring& font, int size, Win33::FontDecoration::Type decorations = Win33::FontDecoration::None );
        Font            ( const Font&  other ) = default;
        Font            (       Font&& other );
        Font& operator= ( const Font&  other ) = default;
        Font& operator= (       Font&& other );
        ~Font           ( );
        
        friend HFONT Win33::Interop::toHandle( const Win33::Font* font );
        
    private:
        HFONT mHandle;
    };
    
};