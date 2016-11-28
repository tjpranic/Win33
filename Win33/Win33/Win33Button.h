#pragma once

#include "Win33Control.h"
#include "Win33ButtonEvents.h"

namespace Win33 {
    
    class Application;
    
    class Button : public Control {
    friend class Application;
    public:
        Button( ) = delete;
        Button(
                  Win33::Window* parent,
            const Point&         position,
            const Size&          size,
            const std::wstring&  text
        );
        Button            ( const Button&  other ) = default;
        Button            (       Button&& other );
        Button& operator= ( const Button&  other ) = default;
        Button& operator= (       Button&& other );
        ~Button           ( )                      = default;
        
        void click( );
        
        std::wstring getText( ) const;
        
        void setText( const std::wstring& text );
        
        void addClickHandler( const ButtonEvents::Handler& handler );
        
        void removeClickHandler( const ButtonEvents::Handler& handler );
        
    private:
        ButtonEvents::Click mClick;
    };
    
};