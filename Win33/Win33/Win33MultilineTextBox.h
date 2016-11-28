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
        MultilineTextBox            ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox            (       MultilineTextBox&& other );
        MultilineTextBox& operator= ( const MultilineTextBox&  other ) = delete;
        MultilineTextBox& operator= (       MultilineTextBox&& other );
        ~MultilineTextBox           ( )                                = default;
        
        std::wstring getText( ) const;
        
        void setText( const std::wstring& text );
    };
};