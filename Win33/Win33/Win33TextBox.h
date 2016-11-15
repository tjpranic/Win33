#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    namespace TextAlignment {
        enum Type {
            Left   = EditStyle::Left,
            Center = EditStyle::Center,
            Right  = EditStyle::Right
        };
    };
    
    class TextBox : public Control {
    public:
        TextBox( ) = delete;
        TextBox(
                  Win33::Window*      parent,
            const Point&              position,
            const Size&               size,
            const std::wstring&       text      = L"",
                  TextAlignment::Type alignment = TextAlignment::Left
        );
        TextBox            ( TextBox&  other ) = default;
        TextBox            ( TextBox&& other );
        TextBox& operator= ( TextBox&  other ) = default;
        TextBox& operator= ( TextBox&& other );
        ~TextBox           ( )                 = default;
        
        std::wstring getText( )     const;
        bool         getReadOnly( ) const;
        
        void setText     ( const std::wstring& text );
        void setReadOnly ( bool readOnly );
        
    private:
        bool mReadOnly;
    };
    
};