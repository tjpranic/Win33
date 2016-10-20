#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class MultilineTextBox : public Control {
    public:
        MultilineTextBox( ) = delete;
        MultilineTextBox(
                  Win33::Window*  parent,
            const Point&          position,
            const Size&           size,
                  ScrollBar::Type scrollBar = ScrollBar::None,
            const std::wstring&   text      = L""
        );
        MultilineTextBox            ( MultilineTextBox&  other ) = default;
        MultilineTextBox            ( MultilineTextBox&& other );
        MultilineTextBox& operator= ( MultilineTextBox&  other ) = default;
        MultilineTextBox& operator= ( MultilineTextBox&& other );
        ~MultilineTextBox           ( )                          = default;
        
        std::wstring getText( ) const;
        
        void setText( const std::wstring& text );
    };
};