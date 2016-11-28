#include "Win33Label.h"

Win33::Label::Label(
          Win33::Window* parent,
    const Point&         position,
    const Size&          size,
    const std::wstring&  text
):
Control(
    Type::Label,
    parent,
    position,
    size,
    static_cast<WindowStyle::Type>( WindowStyle::Child | StaticStyle::Notify | StaticStyle::Left ),
    ExWindowStyle::NoExWindowStyle
) {
    setText( text );
}
Win33::Label::Label( Label&& other )
:
Control ( std::move( other ) ),
click   ( std::move( other.click ) )
{ }
Win33::Label& Win33::Label::operator=( Label&& other ) {
    Control::operator=( std::move( other ) );
    click = std::move( other.click );
    return *this;
}

std::wstring Win33::Label::getText( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}

void Win33::Label::setText( const std::wstring& text ) {
    SetWindowText( mHandle, text.c_str( ) );
}