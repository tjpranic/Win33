#pragma once

#include "Control.h"

namespace Win33 {

    //grouping works just like Win32, set group to true to start a new group,
    //subsequently created RadioButtons will be added to the last created group
    class RadioButton : public Control {
    public:
        RadioButton(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
            const std::wstring& text,
                  bool          selected = false,
                  bool          group    = false,
                  ButtonStyle   style    = ButtonStyle::None
        );
        RadioButton            ( )                           = delete;
        RadioButton            ( const RadioButton&  other ) = delete;
        RadioButton            (       RadioButton&& other ) = delete;
        RadioButton& operator= ( const RadioButton&  other ) = delete;
        RadioButton& operator= (       RadioButton&& other ) = delete;
        ~RadioButton           ( )                           = default;

        bool getSelected( ) const;

        void setSelected ( bool selected );
    };

}