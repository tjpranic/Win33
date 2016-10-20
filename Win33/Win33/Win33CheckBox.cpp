#include "Win33Checkbox.h"

#include <windowsx.h>

Win33::CheckBox::CheckBox(
          Win33::Window* parent,
    const Point&         position,
    const Size&          size,
    const std::wstring&  text,
          bool           checked
):
Control(
    Type::CheckBox,
    parent,
    position,
    size,
    static_cast<WindowStyle::Type>( WindowStyle::Tabstop | WindowStyle::Child | ButtonStyle::AutoCheckBox )
) {
    setText    ( text );
    setChecked ( checked );
}
Win33::CheckBox::CheckBox( CheckBox&& other )
:
Control ( std::move( other ) ),
mCheck  ( std::move( other.mCheck ) )
{ }
Win33::CheckBox& Win33::CheckBox::operator=( CheckBox&& other ) {
    Control::operator=( std::move( other ) );
    mCheck = std::move( other.mCheck );
    return *this;
}

void Win33::CheckBox::toggle( ) {
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
    //event handlers are called manually here as it seems impossible to intercept the BM_SETCHECK message
    mCheck.handle( CheckBoxEvents::CheckData( checked ) );
}

void Win33::CheckBox::addCheckHandler( const CheckBoxEvents::CheckHandler& handler ) {
    mCheck.addHandler( handler );
}

void Win33::CheckBox::removeCheckHandler( const CheckBoxEvents::CheckHandler& handler ) {
    mCheck.removeHandler( handler );
}