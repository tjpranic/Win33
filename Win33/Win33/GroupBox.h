#pragma once

#include "Control.h"

namespace Win33 {

    class GroupBox : public Control {
    public:
        GroupBox(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
            const std::wstring& text,
                  ButtonStyle   style = ButtonStyle::None
        );
        GroupBox            ( )                        = delete;
        GroupBox            ( const GroupBox&  other ) = delete;
        GroupBox            (       GroupBox&& other ) = delete;
        GroupBox& operator= ( const GroupBox&  other ) = delete;
        GroupBox& operator= (       GroupBox&& other ) = delete;
        ~GroupBox           ( )                        = default;
    };

}