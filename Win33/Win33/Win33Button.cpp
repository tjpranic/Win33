#include "Win33Button.h"

Win33::Button::Button(
          Win33::Window* parent,
    const Point&         position,
    const Size&          size,
    const std::wstring&  text
):
Control(
    Type::Button,
    parent,
    position,
    size,
    static_cast<WindowStyle::Type>( WindowStyle::Tabstop | WindowStyle::Child | ButtonStyle::PushButton )
) {
    setText( text );
}
Win33::Button::Button( Button&& other )
:
Control ( std::move( other ) ),
click   ( std::move( other.click ) )
{ }
Win33::Button& Win33::Button::operator=( Button&& other ) {
    Control::operator=( std::move( other ) );
    click = std::move( other.click );
    return *this;
}

std::wstring Win33::Button::getText( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}

void Win33::Button::setText( const std::wstring& text ) {
    SetWindowText( mHandle, text.c_str( ) );
}