#pragma once

#include "Control.h"

namespace Win33 {

    class TextBox : public Control {
    public:
        TextBox(
                  Window*       parent,
            const Point&        position,
            const Size&         size,
            const std::wstring& text  = L"",
                  EditStyle     style = EditStyle::Left
        );
        TextBox            ( )                       = delete;
        TextBox            ( const TextBox&  other ) = delete;
        TextBox            (       TextBox&& other ) = delete;
        TextBox& operator= ( const TextBox&  other ) = delete;
        TextBox& operator= (       TextBox&& other ) = delete;
        virtual ~TextBox   ( )                       = default;

        bool getReadOnly( ) const;

        void setReadOnly (       bool          readOnly );
        void setText     ( const std::wstring& text     );
    };

}