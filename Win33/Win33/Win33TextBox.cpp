#include "Win33TextBox.h"

#include <windowsx.h>

#include "Win33BitfieldOperators.h"

Win33::TextBox::TextBox(
          Win33::Window*   parent,
    const Win33::Point&    position,
    const Win33::Size&     size,
    const std::wstring&    text,
          Win33::EditStyle style
):
Control(
    Win33::Platform::Type::TextBox,
    parent,
    position,
    size,
    Win33::WindowStyle::Tabstop | Win33::WindowStyle::Child | Win33::EditStyle::AutoHorizontalScroll | style,
    Win33::ExWindowStyle::ClientEdge
),
mReadOnly( false )
{
    setText( text );
}
Win33::TextBox::TextBox( TextBox&& other )
:
Control   ( std::move( other ) ),
mReadOnly ( other.mReadOnly )
{ }
Win33::TextBox& Win33::TextBox::operator=( TextBox&& other ) {
    Control::operator=( std::move( other ) );
    mReadOnly = other.mReadOnly;
    return *this;
}

bool Win33::TextBox::getReadOnly( ) const {
    return mReadOnly;
}

void Win33::TextBox::setReadOnly( bool readOnly ) {
    mReadOnly = readOnly;
    
    Edit_SetReadOnly( mHandle, readOnly );
}
void Win33::TextBox::setText( const std::wstring& text ) {
    Win33::Control::setText( text );
    //automatically scroll if text was set programatically
    SendMessage( mHandle, EM_SETSEL, text.size( ), text.size( ) );
}