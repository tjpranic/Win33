#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class PasswordBox : public Control {
    public:
        PasswordBox( ) = delete;
        PasswordBox(
                  Win33::Window* parent,
            const Point&         position,
            const Size&          size,
                  wchar_t        passwordCharacter = L'*'
        );
        PasswordBox            ( PasswordBox&  other ) = default;
        PasswordBox            ( PasswordBox&& other );
        PasswordBox& operator= ( PasswordBox&  other ) = default;
        PasswordBox& operator= ( PasswordBox&& other );
        ~PasswordBox           ( )                     = default;
        
        std::wstring getText( )              const;
        wchar_t      getPasswordCharacter( ) const;
        
        void setText              ( const std::wstring& text      );
        void setPasswordCharacter (       wchar_t       character );
    };
    
};