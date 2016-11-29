#include "Win33Button.h"

Win33::Button::Button(
          Win33::Window* parent,
    const Win33::Point&  position,
    const Win33::Size&   size,
    const std::wstring&  text
):
Control(
    Win33::Platform::Type::Button,
    parent,
    position,
    size,
    static_cast<Win33::WindowStyle::Type>(
        Win33::WindowStyle::Tabstop    |
        Win33::WindowStyle::Child      |
        Win33::ButtonStyle::PushButton
    )
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