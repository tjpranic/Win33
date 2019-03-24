#include "Button.h"

#include "BitfieldOperators.h"

namespace Win33 {

    Button::Button(
              Window*       parent,
        const Point&        position,
        const Size&         size,
        const std::wstring& text,
              ButtonStyle   style
    ):
    Control(
        Type::Button,
        parent,
        position,
        size,
        WindowStyle::Tabstop | WindowStyle::Child | ButtonStyle::PushButton | style
    ) {
        setText( text );
    }

    LRESULT CALLBACK Button::windowProcessor( HWND handle, UINT message, WPARAM wordParameter, LPARAM longParameter ) {
        switch( message ) {
            case BN_CLICKED: {
                onClick.trigger( );
                break;
            }
            default: {
                break;
            }
        }
        return DefWindowProc( handle, message, wordParameter, longParameter );
    }

}