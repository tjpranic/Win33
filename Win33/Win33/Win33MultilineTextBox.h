#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class MultilineTextBox : public Control {
    public:
        MultilineTextBox( ) = delete;
        MultilineTextBox(
                  Win33::Window*   parent,
            const Win33::Point&    position,
            const Win33::Size&     size,
                  Win33::EditStyle style = static_cast<Win33::EditStyle>( 0 ),
            const std::wstring&    text  = L""
        );
        MultilineTextBox            ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox            (       MultilineTextBox&& other );
        MultilineTextBox& operator= ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox& operator= (       MultilineTextBox&& other );
        ~MultilineTextBox           ( )                                = default;
    };
    
};