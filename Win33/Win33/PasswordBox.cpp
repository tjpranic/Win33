#include "PasswordBox.h"

#include "BitfieldOperators.h"

namespace Win33 {

    PasswordBox::PasswordBox(
              Window*   parent,
        const Point&    position,
        const Size&     size,
              EditStyle style
    ):
    TextBox(
        parent,
        position,
        size,
        L"",
        EditStyle::Password | style
    )
    { }

    wchar_t PasswordBox::getPasswordCharacter( ) const {
        return static_cast<wchar_t>( SendMessage( mHandle, EM_GETPASSWORDCHAR, 0, 0 ) );
    }

    void PasswordBox::setPasswordCharacter( wchar_t character ) {
        if( character != L'\0' || character != L' ' ) {
            SendMessage( mHandle, EM_SETPASSWORDCHAR, character, 0 );
        }
    }

}