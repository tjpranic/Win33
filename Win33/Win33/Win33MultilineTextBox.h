#pragma once

#include "Win33TextBox.h"

namespace Win33 {
    
    class MultilineTextBox : public TextBox {
    public:
        MultilineTextBox(
                  Win33::Window*   parent,
            const Win33::Point&    position,
            const Win33::Size&     size,
            const std::wstring&    text  = L"",
                  Win33::EditStyle style = Win33::EditStyle::None
        );
        MultilineTextBox            ( )                                = delete;
        MultilineTextBox            ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox            (       MultilineTextBox&& other ) = delete;
        MultilineTextBox& operator= ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox& operator= (       MultilineTextBox&& other ) = delete;
        ~MultilineTextBox           ( )                                = default;
    };
    
};