#include "TextBox.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

Win33::TextBox::TextBox(
          Window*       parent,
    const Point&        position,
    const Size&         size,
    const std::wstring& text,
          EditStyle     style
):
Control(
    Common::getTypeFromStyle( style ),
    parent,
    position,
    size,
    WindowStyle::Tabstop | WindowStyle::Child | EditStyle::AutoHorizontalScroll | style,
    ExWindowStyle::ClientEdge
) {
    setText( text );
}

bool Win33::TextBox::getReadOnly( ) const {
    return ( GetWindowLongPtr( mHandle, GWL_STYLE ) & ES_READONLY ) == ES_READONLY;
}

void Win33::TextBox::setReadOnly( bool readOnly ) {
    Edit_SetReadOnly( mHandle, readOnly );
}
void Win33::TextBox::setText( const std::wstring& text ) {
    Control::setText( text );
    //automatically scroll if text was set programatically
    SendMessage( mHandle, EM_SETSEL, text.size( ), text.size( ) );
}