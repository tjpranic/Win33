#include "Win33PasswordBox.h"

#include "Win33BitfieldOperators.h"

Win33::PasswordBox::PasswordBox(
          Win33::Window*   parent,
    const Win33::Point&    position,
    const Win33::Size&     size,
          Win33::EditStyle style
):
Control(
    Win33::Common::Type::PasswordBox,
    parent,
    position,
    size,
    Win33::WindowStyle::Tabstop | Win33::WindowStyle::Child | Win33::EditStyle::Left | Win33::EditStyle::Password | Win33::EditStyle::AutoHorizontalScroll | style,
    Win33::ExWindowStyle::ClientEdge
)
{ }
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