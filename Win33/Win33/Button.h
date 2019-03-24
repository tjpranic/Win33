#pragma once

#include "Control.h"
#include "Event.h"

namespace Win33 {

    class Button : public Control {
    public:
        DECLARE_EVENT( Click, void( ), Button )

        Button(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
            const std::wstring& text,
                  ButtonStyle   style = ButtonStyle::None
        );
        Button            ( )                      = delete;
        Button            ( const Button&  other ) = delete;
        Button            (       Button&& other ) = delete;
        Button& operator= ( const Button&  other ) = delete;
        Button& operator= (       Button&& other ) = delete;
        ~Button           ( )                      = default;

        virtual LRESULT CALLBACK windowProcessor( HWND handle, UINT message, WPARAM wordParameter, LPARAM longParameter );

        Click onClick;
    };

}