#pragma once

#include "Win33Control.h"
#include "Win33ButtonEvents.h"

namespace Win33 {
    
    class Button : public Control {
    public:
        Button( ) = delete;
        Button(
                  Win33::Window* parent,
            const Win33::Point&  position,
            const Win33::Size&   size,
            const std::wstring&  text
        );
        Button            ( const Button&  other ) = delete;
        Button            (       Button&& other );
        Button& operator= ( const Button&  other ) = delete;
        Button& operator= (       Button&& other );
        ~Button           ( )                      = default;
        
        std::wstring getText( ) const;
        
        void setText( const std::wstring& text );
        
        Win33::ButtonEvents::Click click;
    };
    
};