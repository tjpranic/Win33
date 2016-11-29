#include "Win33RadioButton.h"

#include <windowsx.h>

Win33::RadioButton::RadioButton(
          Win33::Window* parent,
    const Win33::Point&  position,
    const Win33::Size&   size,
    const std::wstring&  text,
          bool           selected,
          bool           group
):
Control(
    Win33::Platform::Type::RadioButton,
    parent,
    position,
    size,
    static_cast<Win33::WindowStyle::Type>(
        Win33::WindowStyle::Tabstop         |
        Win33::WindowStyle::Child           |
        Win33::ButtonStyle::AutoRadioButton |
        ( group ? Win33::WindowStyle::Group : 0 )
    )
) {
    setText     ( text );
    setSelected ( selected );
}
Win33::RadioButton::RadioButton( RadioButton&& other )
:
Control ( std::move( other ) ),
select  ( std::move( other.select ) )
{ }
Win33::RadioButton& Win33::RadioButton::operator=( RadioButton&& other ) {
    Control::operator=( std::move( other ) );
    select = std::move( other.select );
    return *this;
}

std::wstring Win33::RadioButton::getText( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}
bool Win33::RadioButton::getSelected( ) const {
    return Button_GetCheck( mHandle ) != 0;
}

void Win33::RadioButton::setText( const std::wstring& text ) {
    SetWindowText( mHandle, text.c_str( ) );
}
void Win33::RadioButton::setSelected( bool checked ) {
    Button_SetCheck( mHandle, checked );
}