#include "Win33Checkbox.h"

#include <windowsx.h>

Win33::CheckBox::CheckBox(
          Win33::Window* parent,
    const Win33::Point&  position,
    const Win33::Size&   size,
    const std::wstring&  text,
          bool           checked
):
Control(
    Win33::Platform::Type::CheckBox,
    parent,
    position,
    size,
    static_cast<Win33::WindowStyle::Type>(
        Win33::WindowStyle::Tabstop      |
        Win33::WindowStyle::Child        |
        Win33::ButtonStyle::AutoCheckBox
    )
) {
    setText    ( text );
    setChecked ( checked );
}
Win33::CheckBox::CheckBox( CheckBox&& other )
:
Control ( std::move( other ) ),
check   ( std::move( other.check ) )
{ }
Win33::CheckBox& Win33::CheckBox::operator=( CheckBox&& other ) {
    Control::operator=( std::move( other ) );
    check = std::move( other.check );
    return *this;
}

void Win33::CheckBox::toggleChecked( ) {
    setChecked( !getChecked( ) );
}

std::wstring Win33::CheckBox::getText( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}
bool Win33::CheckBox::getChecked( ) const {
    return Button_GetCheck( mHandle ) != 0;
}

void Win33::CheckBox::setText( const std::wstring& text ) {
    SetWindowText( mHandle, text.c_str( ) );
}
void Win33::CheckBox::setChecked( bool checked ) {
    Button_SetCheck( mHandle, checked );
}