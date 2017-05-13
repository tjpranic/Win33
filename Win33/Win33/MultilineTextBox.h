#pragma once

#include "TextBox.h"

namespace Win33 {
    
    class MultilineTextBox : public TextBox {
    public:
        MultilineTextBox(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
            const std::wstring& text  = L"",
                  EditStyle     style = EditStyle::None
        );
        MultilineTextBox            ( )                                = delete;
        MultilineTextBox            ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox            (       MultilineTextBox&& other ) = delete;
        MultilineTextBox& operator= ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox& operator= (       MultilineTextBox&& other ) = delete;
        ~MultilineTextBox           ( )                                = default;
    };
    
};