#pragma once

#include "Win33Control.h"
#include "Win33CheckBoxEvents.h"

namespace Win33 {
    
    class CheckBox : public Control {
    public:
        CheckBox(
                  Win33::Window*     parent,
            const Win33::Point&      position,
            const Win33::Size&       size,
            const std::wstring&      text,
                  bool               checked = false,
                  Win33::ButtonStyle style   = Win33::ButtonStyle::None
        );
        CheckBox            ( )                        = delete;
        CheckBox            ( const CheckBox&  other ) = delete;
        CheckBox            (       CheckBox&& other ) = default;
        CheckBox& operator= ( const CheckBox&  other ) = delete;
        CheckBox& operator= (       CheckBox&& other ) = default;
        ~CheckBox           ( )                        = default;
        
        void toggleChecked( );
        
        bool getChecked( ) const;
        
        void setChecked( bool checked );
        
        Win33::CheckBoxEvents::Check onCheck;
    };
    
};