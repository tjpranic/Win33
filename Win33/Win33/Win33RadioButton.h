#pragma once

#include "Win33Control.h"
#include "Win33RadioButtonEvents.h"

namespace Win33 {
    
    class RadioButton : public Control {
    public:
        RadioButton( ) = delete;
        RadioButton(
                  Win33::Window* parent,
            const Win33::Point&  position,
            const Win33::Size&   size,
            const std::wstring&  text,
                  bool           selected = false,
                  bool           group    = false
        );
        RadioButton            ( const RadioButton&  other ) = delete;
        RadioButton            (       RadioButton&& other );
        RadioButton& operator= ( const RadioButton&  other ) = delete;
        RadioButton& operator= (       RadioButton&& other );
        ~RadioButton           ( )                           = default;
        
        bool getSelected( ) const;
        
        void setSelected ( bool selected );
        
        Win33::RadioButtonEvents::Select onSelect;
    };
    
};