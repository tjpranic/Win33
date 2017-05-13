#pragma once

#include "Control.h"
#include "ButtonEvents.h"

namespace Win33 {
    
    class Button : public Control {
    public:
        Button(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
            const std::wstring& text,
                  ButtonStyle   style = ButtonStyle::None
        );
        Button            ( )                      = delete;
        Button            ( const Button&  other ) = delete;
        Button            (       Button&& other ) = delete;
        Button& operator= ( const Button&  other ) = delete;
        Button& operator= (       Button&& other ) = delete;
        ~Button           ( )                      = default;
        
        ButtonEvents::Click onClick;
    };
    
};