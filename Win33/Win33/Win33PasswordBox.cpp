#include "Win33PasswordBox.h"

Win33::PasswordBox::PasswordBox(
          Win33::Window* parent,
    const Win33::Point&  position,
    const Win33::Size&   size,
          wchar_t        passwordCharacter
):
Control(
    Win33::Platform::Type::PasswordBox,
    parent,
    position,
    size,
    static_cast<Win33::WindowStyle::Type>(
        Win33::WindowStyle::Tabstop            |
        Win33::WindowStyle::Child              |
        Win33::EditStyle::Left                 |
        Win33::EditStyle::Password             |
        Win33::EditStyle::AutoHorizontalScroll
    ),
    Win33::ExWindowStyle::ClientEdge
) {
    setPasswordCharacter( passwordCharacter );
}
Win33::PasswordBox::PasswordBox( PasswordBox&& other )
:
Control( std::move( other ) )
{ }
Win33::PasswordBox& Win33::PasswordBox::operator=( PasswordBox&& other ) {
    Control::operator=( std::move( other ) );
    return *this;
}

wchar_t Win33::PasswordBox::getPasswordCharacter( ) const {
    return static_cast<wchar_t>( SendMessage( mHandle, EM_GETPASSWORDCHAR, 0, 0 ) );
}

void Win33::PasswordBox::setPasswordCharacter( wchar_t character ) {
    if( character != L'' || character != L' ' ) {
        SendMessage( mHandle, EM_SETPASSWORDCHAR, character, 0 );
    }
}