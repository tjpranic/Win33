#pragma once

#include "Win33Control.h"
#include "Win33CheckBoxEvents.h"

namespace Win33 {
    
    class Application;
    
    class CheckBox : public Control {
    friend class Application;
    public:
        CheckBox( ) = delete;
        CheckBox(
                  Win33::Window* parent,
            const Point&         position,
            const Size&          size,
            const std::wstring&  text,
                  bool           checked = false
        );
        CheckBox            ( const CheckBox&  other ) = default;
        CheckBox            (       CheckBox&& other );
        CheckBox& operator= ( const CheckBox&  other ) = default;
        CheckBox& operator= (       CheckBox&& other );
        ~CheckBox           ( )                        = default;
        
        void toggle( );
        
        std::wstring getText( )    const;
        bool         getChecked( ) const;
        
        void setText    ( const std::wstring& text );
        void setChecked ( bool checked );
        
        void addCheckHandler( const CheckBoxEvents::CheckHandler& handler );
        
        void removeCheckHandler( const CheckBoxEvents::CheckHandler& handler );
        
    private:
        CheckBoxEvents::Check mCheck;
    };
    
};