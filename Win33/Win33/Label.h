#pragma once

#include "Control.h"
#include "LabelEvents.h"

namespace Win33 {
    
    class Label : public Control {
    public:
        Label(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
            const std::wstring& text  = L"",
                  StaticStyle   style = StaticStyle::Left
        );
        Label            ( )                     = delete;
        Label            ( const Label&  other ) = delete;
        Label            (       Label&& other ) = delete;
        Label& operator= ( const Label&  other ) = delete;
        Label& operator= (       Label&& other ) = delete;
        ~Label           ( )                     = default;
        
        LabelEvents::Click onClick;
    };
    
};