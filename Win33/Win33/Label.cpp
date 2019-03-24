#include "Label.h"

#include "BitfieldOperators.h"

namespace Win33 {

    Label::Label(
              Window*       parent,
        const Point&        position,
        const Size&         size,
        const std::wstring& text,
              StaticStyle   style
    ):
    Control(
        L"STATIC",
        parent,
        position,
        size,
        WindowStyle::Child | StaticStyle::Notify | StaticStyle::Left | style,
        ExWindowStyle::None
    ) {
        setText( text );
    }

    LRESULT CALLBACK Label::windowProcessor( HWND handle, UINT message, WPARAM wordParameter, LPARAM longParameter ) {
        switch( message ) {
            case STN_DBLCLK: //double clicks have to be counted amongst single clicks due to notify style (?)
            case STN_CLICKED: {
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