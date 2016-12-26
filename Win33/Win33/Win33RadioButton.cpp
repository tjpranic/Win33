#include "Win33RadioButton.h"

#include <windowsx.h>

#include "Win33BitfieldOperators.h"

Win33::RadioButton::RadioButton(
          Win33::Window*     parent,
    const Win33::Point&      position,
    const Win33::Size&       size,
    const std::wstring&      text,
          bool               selected,
          bool               group,
          Win33::ButtonStyle style
):
Control(
    Win33::Common::Type::RadioButton,
    parent,
    position,
    size,
    Win33::WindowStyle::Tabstop | Win33::WindowStyle::Child | Win33::ButtonStyle::AutoRadioButton | style | ( group ? Win33::WindowStyle::Group : static_cast<Win33::WindowStyle>( 0 ) )
) {
    setText     ( text );
    setSelected ( selected );
}

bool Win33::RadioButton::getSelected( ) const {
    return Button_GetCheck( mHandle ) != 0;
}

void Win33::RadioButton::setSelected( bool checked ) {
    Button_SetCheck( mHandle, checked );
}