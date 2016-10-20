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
mClick  ( std::move( other.mClick ) )
{ }
Win33::Label& Win33::Label::operator=( Label&& other ) {
    Control::operator=( std::move( other ) );
    mClick = std::move( other.mClick );
    return *this;
}

void Win33::Label::click( ) {
    SendMessage( mHandle, WM_LBUTTONDOWN, 0, 0 );
    SendMessage( mHandle, WM_LBUTTONUP, 0, 0 );
}

std::wstring Win33::Label::getText( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}

void Win33::Label::setText( const std::wstring& text ) {
    SetWindowText( mHandle, text.c_str( ) );
}

void Win33::Label::addClickHandler( const LabelEvents::Handler& handler ) {
    mClick.addHandler( handler );
}

void Win33::Label::removeClickHandler( const LabelEvents::Handler& handler ) {
    mClick.removeHandler( handler );
}