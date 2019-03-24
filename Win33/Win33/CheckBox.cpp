#include "Checkbox.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

namespace Win33 {

    CheckBox::CheckBox(
              Window*       parent,
        const Point&        position,
        const Size&         size,
        const std::wstring& text,
              bool          checked,
              ButtonStyle   style
    ):
    Control(
        L"BUTTON",
        parent,
        position,
        size,
        WindowStyle::Tabstop | WindowStyle::Child | ButtonStyle::AutoCheckBox | style
    ) {
        setText    ( text );
        setChecked ( checked );
    }

    void CheckBox::toggleChecked( ) {
        setChecked( !getChecked( ) );
    }

    bool CheckBox::getChecked( ) const {
        return Button_GetCheck( mHandle ) != 0;
    }

    void CheckBox::setChecked( bool checked ) {
        Button_SetCheck( mHandle, checked );
    }

    LRESULT CALLBACK CheckBox::windowProcessor( HWND handle, UINT message, WPARAM wordParameter, LPARAM longParameter ) {
        switch( message ) {
            case BN_CLICKED: {
                onCheck.trigger( getChecked( ) );
                break;
            }
            default: {
                break;
            }
        }
        return DefWindowProc( handle, message, wordParameter, longParameter );
    }

}