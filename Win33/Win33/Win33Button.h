#pragma once

#include "Win33Control.h"
#include "Win33ButtonEvents.h"

namespace Win33 {
    
    class Button : public Control {
    public:
        Button(
                  Win33::Window*     parent,
            const Win33::Point&      position,
            const Win33::Size&       size,
            const std::wstring&      text,
                  Win33::ButtonStyle style = Win33::ButtonStyle::None
        );
        Button            ( )                      = delete;
        Button            ( const Button&  other ) = delete;
        Button            (       Button&& other ) = default;
        Button& operator= ( const Button&  other ) = delete;
        Button& operator= (       Button&& other ) = default;
        ~Button           ( )                      = default;
        
        Win33::ButtonEvents::Click onClick;
    };
    
};