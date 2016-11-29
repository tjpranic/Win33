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
                  Win33::Window*             parent,
            const Win33::Point&              position,
            const Win33::Size&               size,
            const std::wstring&              text      = L"",
                  Win33::TextAlignment::Type alignment = Win33::TextAlignment::Left
        );
        TextBox            ( const TextBox&  other ) = delete;
        TextBox            (       TextBox&& other );
        TextBox& operator= ( const TextBox&  other ) = delete;
        TextBox& operator= (       TextBox&& other );
        ~TextBox           ( )                       = default;
        
        std::wstring getText( )     const;
        bool         getReadOnly( ) const;
        
        void setText     ( const std::wstring& text );
        void setReadOnly ( bool readOnly );
        
    private:
        bool mReadOnly;
    };
    
};