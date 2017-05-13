#include "PasswordBox.h"

#include "BitfieldOperators.h"

Win33::PasswordBox::PasswordBox(
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

wchar_t Win33::PasswordBox::getPasswordCharacter( ) const {
    return static_cast<wchar_t>( SendMessage( mHandle, EM_GETPASSWORDCHAR, 0, 0 ) );
}

void Win33::PasswordBox::setPasswordCharacter( wchar_t character ) {
    if( character != L'\0' || character != L' ' ) {
        SendMessage( mHandle, EM_SETPASSWORDCHAR, character, 0 );
    }
}