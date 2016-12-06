#pragma once

#include "Win33Control.h"
#include "Win33ButtonEvents.h"

namespace Win33 {
    
    class Button : public Control {
    public:
        Button( ) = delete;
        Button(
                  Win33::Window*           parent,
            const Win33::Point&            position,
            const Win33::Size&             size,
            const std::wstring&            text,
                  Win33::ButtonStyle::Type style = static_cast<Win33::ButtonStyle::Type>( 0 )
        );
        Button            ( const Button&  other ) = delete;
        Button            (       Button&& other );
        Button& operator= ( const Button&  other ) = delete;
        Button& operator= (       Button&& other );
        ~Button           ( )                      = default;
        
        Win33::ButtonEvents::Click onClick;
    };
    
};