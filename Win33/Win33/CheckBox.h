#pragma once

#include "Control.h"
#include "Event.h"

namespace Win33 {

    class CheckBox : public Control {
    public:
        DECLARE_EVENT( Check, void( bool checked ), CheckBox )

        CheckBox(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
            const std::wstring& text,
                  bool          checked = false,
                  ButtonStyle   style   = ButtonStyle::None
        );
        CheckBox            ( )                        = delete;
        CheckBox            ( const CheckBox&  other ) = delete;
        CheckBox            (       CheckBox&& other ) = delete;
        CheckBox& operator= ( const CheckBox&  other ) = delete;
        CheckBox& operator= (       CheckBox&& other ) = delete;
        ~CheckBox           ( )                        = default;

        void toggleChecked( );

        bool getChecked( ) const;

        void setChecked( bool checked );

        virtual LRESULT CALLBACK windowProcessor( HWND handle, UINT message, WPARAM wordParameter, LPARAM longParameter );

        Check onCheck;
    };

}