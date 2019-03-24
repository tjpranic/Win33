#include "RadioButton.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

namespace Win33 {

    RadioButton::RadioButton(
              Window*       parent,
        const Point&        position,
        const Size&         size,
        const std::wstring& text,
              bool          selected,
              bool          group,
              ButtonStyle   style
    ):
    Control(
        L"BUTTON",
        parent,
        position,
        size,
        WindowStyle::Tabstop | WindowStyle::Child | ButtonStyle::AutoRadioButton | style | ( group ? WindowStyle::Group : WindowStyle::None )
    ) {
        setText     ( text );
        setSelected ( selected );
    }

    bool RadioButton::getSelected( ) const {
        return Button_GetCheck( mHandle ) != 0;
    }

    void RadioButton::setSelected( bool checked ) {
        Button_SetCheck( mHandle, checked );
    }

}