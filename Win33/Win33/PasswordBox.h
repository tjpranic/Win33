#pragma once

#include "TextBox.h"

namespace Win33 {
    
    class PasswordBox : public TextBox {
    public:
        PasswordBox(
                  Window*   parent,
            const Point&    position,
            const Size&     size,
                  EditStyle style = EditStyle::Left
        );
        PasswordBox            ( )                           = delete;
        PasswordBox            ( const PasswordBox&  other ) = delete;
        PasswordBox            (       PasswordBox&& other ) = delete;
        PasswordBox& operator= ( const PasswordBox&  other ) = delete;
        PasswordBox& operator= (       PasswordBox&& other ) = delete;
        ~PasswordBox           ( )                           = default;
        
        wchar_t getPasswordCharacter( ) const;
        
        void setPasswordCharacter( wchar_t character );
    };
    
};