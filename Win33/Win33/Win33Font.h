#pragma once

#include <string>

#include "Win33Interop.h"

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
        Font            ( const std::wstring& font, int size, Win33::FontDecoration decorations = Win33::FontDecoration::None );
        Font            ( )                    = delete;
        Font            ( const Font&  other ) = default;
        Font            (       Font&& other ) = default;
        Font& operator= ( const Font&  other ) = default;
        Font& operator= (       Font&& other ) = default;
        ~Font           ( );
        
        friend HFONT Win33::Interop::toHandle( const Win33::Font* font );
        
    private:
        HFONT mHandle;
    };
    
};