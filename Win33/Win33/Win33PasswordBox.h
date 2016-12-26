#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class PasswordBox : public Control {
    public:
        PasswordBox(
                  Win33::Window*   parent,
            const Win33::Point&    position,
            const Win33::Size&     size,
                  Win33::EditStyle style = Win33::EditStyle::Left
        );
        PasswordBox            ( )                           = delete;
        PasswordBox            ( const PasswordBox&  other ) = delete;
        PasswordBox            (       PasswordBox&& other ) = default;
        PasswordBox& operator= ( const PasswordBox&  other ) = delete;
        PasswordBox& operator= (       PasswordBox&& other ) = default;
        ~PasswordBox           ( )                           = default;
        
        wchar_t getPasswordCharacter( ) const;
        
        void setPasswordCharacter( wchar_t character );
    };
    
};