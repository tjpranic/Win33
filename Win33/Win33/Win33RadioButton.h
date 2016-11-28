#pragma once

#include "Win33Control.h"
#include "Win33RadioButtonEvents.h"

namespace Win33 {
    
    class RadioButton : public Control {
    public:
        RadioButton( ) = delete;
        RadioButton(
                  Win33::Window* parent,
            const Point&         position,
            const Size&          size,
            const std::wstring&  text,
                  bool           selected = false,
                  bool           group    = false
        );
        RadioButton            ( const RadioButton&  other ) = delete;
        RadioButton            (       RadioButton&& other );
        RadioButton& operator= ( const RadioButton&  other ) = delete;
        RadioButton& operator= (       RadioButton&& other );
        ~RadioButton           ( )                           = default;
        
        std::wstring getText( )     const;
        bool         getSelected( ) const;
        
        void setText     ( const std::wstring& text );
        void setSelected ( bool selected );
        
        RadioButtonEvents::Select select;
    };
    
};