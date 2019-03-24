#include "TextBox.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

namespace Win33 {

    TextBox::TextBox(
              Window*       parent,
        const Point&        position,
        const Size&         size,
        const std::wstring& text,
              EditStyle     style
    ):
    Control(
        Type::TextBox,
        parent,
        position,
        size,
        WindowStyle::Tabstop | WindowStyle::Child | EditStyle::AutoHorizontalScroll | style,
        ExWindowStyle::ClientEdge
    ) {
        setText( text );
    }

    bool TextBox::getReadOnly( ) const {
        return ( GetWindowLongPtr( mHandle, GWL_STYLE ) & ES_READONLY ) == ES_READONLY;
    }

    void TextBox::setReadOnly( bool readOnly ) {
        Edit_SetReadOnly( mHandle, readOnly );
    }
    void TextBox::setText( const std::wstring& text ) {
        Control::setText( text );
        //automatically scroll if text was set programatically
        SendMessage( mHandle, EM_SETSEL, text.size( ), text.size( ) );
    }

}