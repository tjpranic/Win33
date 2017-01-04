#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class TextBox : public Control {
    public:
        TextBox(
                  Win33::Window*   parent,
            const Win33::Point&    position,
            const Win33::Size&     size,
            const std::wstring&    text  = L"",
                  Win33::EditStyle style = Win33::EditStyle::Left
        );
        TextBox            ( )                       = delete;
        TextBox            ( const TextBox&  other ) = delete;
        TextBox            (       TextBox&& other ) = delete;
        TextBox& operator= ( const TextBox&  other ) = delete;
        TextBox& operator= (       TextBox&& other ) = delete;
        virtual ~TextBox   ( )                       = default;
        
        bool getReadOnly( ) const;
        
        void setReadOnly (       bool          readOnly );
        void setText     ( const std::wstring& text     );
    };
    
};