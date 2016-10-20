#pragma once

#include "Win33Control.h"
#include "Win33RadioButtonEvents.h"

namespace Win33 {
    
    class Application;
    
    class RadioButton : public Control {
    friend class Application;
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
        RadioButton            ( RadioButton&  other ) = default;
        RadioButton            ( RadioButton&& other );
        RadioButton& operator= ( RadioButton&  other ) = default;
        RadioButton& operator= ( RadioButton&& other );
        ~RadioButton           ( )                     = default;
        
        std::wstring getText( )     const;
        bool         getSelected( ) const;
        
        void setText     ( const std::wstring& text );
        void setSelected ( bool selected );
        
        void addSelectHandler( const RadioButtonEvents::SelectHandler& handler );
        
        void removeSelectHandler( const RadioButtonEvents::SelectHandler& handler );
        
    private:
        RadioButtonEvents::Select mSelect;
    };
    
};