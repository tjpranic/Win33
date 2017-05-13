#include "Checkbox.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

Win33::CheckBox::CheckBox(
          Window*       parent,
    const Point&        position,
    const Size&         size,
    const std::wstring& text,
          bool          checked,
          ButtonStyle   style
):
Control(
    Win33::Common::Type::CheckBox,
    parent,
    position,
    size,
    WindowStyle::Tabstop | WindowStyle::Child | ButtonStyle::AutoCheckBox | style
) {
    setText    ( text );
    setChecked ( checked );
}

void Win33::CheckBox::toggleChecked( ) {
    setChecked( !getChecked( ) );
}

bool Win33::CheckBox::getChecked( ) const {
    return Button_GetCheck( mHandle ) != 0;
}

void Win33::CheckBox::setChecked( bool checked ) {
    Button_SetCheck( mHandle, checked );
}