#pragma once

#include "Win33Control.h"
#include "Win33LabelEvents.h"

namespace Win33 {
    
    class Application;
    
    class Label : public Control {
    friend class Application;
    public:
        Label( ) = delete;
        Label(
                  Win33::Window* parent,
            const Point&         position,
            const Size&          size,
            const std::wstring&  text = L""
        );
        Label            ( Label&  other ) = default;
        Label            ( Label&& other );
        Label& operator= ( Label&  other ) = default;
        Label& operator= ( Label&& other );
        ~Label           ( )               = default;
        
        void click( );
        
        std::wstring getText( ) const;
        
        void setText( const std::wstring& text );
        
        void addClickHandler( const LabelEvents::Handler& handler );
        
        void removeClickHandler( const LabelEvents::Handler& handler );
        
    private:
        LabelEvents::Click mClick;
    };
    
};