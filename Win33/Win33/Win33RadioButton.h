#pragma once

#include "Win33Control.h"
#include "Win33RadioButtonEvents.h"

namespace Win33 {
    
    //grouping works just like Win32, set to true to start a new group,
    //subsequently created RadioButtons will be added to the last created group
    class RadioButton : public Control {
    public:
        RadioButton( ) = delete;
        RadioButton(
                  Win33::Window*           parent,
            const Win33::Point&            position,
            const Win33::Size&             size,
            const std::wstring&            text,
                  bool                     selected = false,
                  bool                     group    = false,
                  Win33::ButtonStyle::Type style    = static_cast<Win33::ButtonStyle::Type>( 0 )
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