#pragma once

#include "Control.h"
#include "Event.h"

namespace Win33 {

    class Label : public Control {
    public:
        DECLARE_EVENT( Click, void( ), Label )

        Label(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
            const std::wstring& text  = L"",
                  StaticStyle   style = StaticStyle::Left
        );
        Label            ( )                     = delete;
        Label            ( const Label&  other ) = delete;
        Label            (       Label&& other ) = delete;
        Label& operator= ( const Label&  other ) = delete;
        Label& operator= (       Label&& other ) = delete;
        ~Label           ( )                     = default;

        virtual LRESULT CALLBACK windowProcessor( HWND handle, UINT message, WPARAM wordParameter, LPARAM longParameter );

        Click onClick;
    };

}