#pragma once

#include "Win33Control.h"
#include "Win33LabelEvents.h"

namespace Win33 {
    
    class Label : public Control {
    public:
        Label( ) = delete;
        Label(
                  Win33::Window* parent,
            const Win33::Point&  position,
            const Win33::Size&   size,
            const std::wstring&  text = L""
        );
        Label            ( const Label&  other ) = delete;
        Label            (       Label&& other );
        Label& operator= ( const Label&  other ) = delete;
        Label& operator= (       Label&& other );
        ~Label           ( )                     = default;
        
        std::wstring getText( ) const;
        
        void setText( const std::wstring& text );
        
        Win33::LabelEvents::Click onClick;
    };
    
};