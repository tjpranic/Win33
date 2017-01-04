#pragma once

#include "Win33TextBox.h"

namespace Win33 {
    
    class PasswordBox : public TextBox {
    public:
        PasswordBox(
                  Win33::Window*   parent,
            const Win33::Point&    position,
            const Win33::Size&     size,
                  Win33::EditStyle style = Win33::EditStyle::Left
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