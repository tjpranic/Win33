#include "Win33PasswordBox.h"

Win33::PasswordBox::PasswordBox(
          Win33::Window* parent,
    const Point&         position,
    const Size&          size,
          wchar_t        passwordCharacter
):
Control(
    Type::PasswordBox,
    parent,
    position,
    size,
    static_cast<WindowStyle::Type>( WindowStyle::Tabstop | WindowStyle::Child | EditStyle::Left | EditStyle::Password | EditStyle::AutoHorizontalScroll ),
    ExWindowStyle::ClientEdge
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

std::wstring Win33::PasswordBox::getText( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}

wchar_t Win33::PasswordBox::getPasswordCharacter( ) const {
    return static_cast<wchar_t>( SendMessage( mHandle, EM_GETPASSWORDCHAR, 0, 0 ) );
}

void Win33::PasswordBox::setText( const std::wstring& text ) {
    SetWindowText( mHandle, text.c_str( ) );
}
void Win33::PasswordBox::setPasswordCharacter( wchar_t character ) {
    if( character != L'' || character != L' ' ) {
        SendMessage( mHandle, EM_SETPASSWORDCHAR, character, 0 );
    }
}