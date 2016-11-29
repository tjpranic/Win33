#pragma once

#include "Win33Control.h"
#include "Win33CheckBoxEvents.h"

namespace Win33 {
    
    class CheckBox : public Control {
    public:
        CheckBox( ) = delete;
        CheckBox(
                  Win33::Window* parent,
            const Win33::Point&  position,
            const Win33::Size&   size,
            const std::wstring&  text,
                  bool           checked = false
        );
        CheckBox            ( const CheckBox&  other ) = delete;
        CheckBox            (       CheckBox&& other );
        CheckBox& operator= ( const CheckBox&  other ) = delete;
        CheckBox& operator= (       CheckBox&& other );
        ~CheckBox           ( )                        = default;
        
        void toggleChecked( );
        
        std::wstring getText( )    const;
        bool         getChecked( ) const;
        
        void setText    ( const std::wstring& text    );
        void setChecked (       bool          checked );
        
        Win33::CheckBoxEvents::Check check;
    };
    
};