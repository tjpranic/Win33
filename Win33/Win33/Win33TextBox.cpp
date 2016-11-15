#include "Win33TextBox.h"

#include <windowsx.h>

Win33::TextBox::TextBox(
          Win33::Window*      parent,
    const Point&              position,
    const Size&               size,
    const std::wstring&       text,
          TextAlignment::Type alignment
):
Control(
    Type::TextBox,
    parent,
    position,
    size,
    static_cast<WindowStyle::Type>( WindowStyle::Tabstop | WindowStyle::Child | EditStyle::AutoHorizontalScroll | alignment ),
    ExWindowStyle::ClientEdge
),
mReadOnly( false ) {
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

std::wstring Win33::TextBox::getText( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}
bool Win33::TextBox::getReadOnly( ) const {
    return mReadOnly;
}

void Win33::TextBox::setText( const std::wstring& text ) {
    SetWindowText( mHandle, text.c_str( ) );
}
void Win33::TextBox::setReadOnly( bool readOnly ) {
    mReadOnly = readOnly;
    Edit_SetReadOnly( mHandle, readOnly );
}