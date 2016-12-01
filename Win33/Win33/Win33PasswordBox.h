#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class PasswordBox : public Control {
    public:
        PasswordBox( ) = delete;
        PasswordBox(
                  Win33::Window* parent,
            const Win33::Point&  position,
            const Win33::Size&   size,
                  wchar_t        passwordCharacter = L'*'
        );
        PasswordBox            ( const PasswordBox&  other ) = delete;
        PasswordBox            (       PasswordBox&& other );
        PasswordBox& operator= ( const PasswordBox&  other ) = delete;
        PasswordBox& operator= (       PasswordBox&& other );
        ~PasswordBox           ( )                           = default;
        
        wchar_t getPasswordCharacter( ) const;
        
        void setPasswordCharacter( wchar_t character );
    };
    
};