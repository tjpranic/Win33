#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class MultilineTextBox : public Control {
    public:
        MultilineTextBox(
                  Win33::Window*   parent,
            const Win33::Point&    position,
            const Win33::Size&     size,
                  Win33::EditStyle style = Win33::EditStyle::None,
            const std::wstring&    text  = L""
        );
        MultilineTextBox            ( )                                = delete;
        MultilineTextBox            ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox            (       MultilineTextBox&& other ) = default;
        MultilineTextBox& operator= ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox& operator= (       MultilineTextBox&& other ) = default;
        ~MultilineTextBox           ( )                                = default;
    };
    
};