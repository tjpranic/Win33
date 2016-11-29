#include "Win33TextBox.h"

#include <windowsx.h>

Win33::TextBox::TextBox(
          Win33::Window*             parent,
    const Win33::Point&              position,
    const Win33::Size&               size,
    const std::wstring&              text,
          Win33::TextAlignment::Type alignment
):
Control(
    Win33::Platform::Type::TextBox,
    parent,
    position,
    size,
    static_cast<Win33::WindowStyle::Type>(
        Win33::WindowStyle::Tabstop            |
        Win33::WindowStyle::Child              |
        Win33::EditStyle::AutoHorizontalScroll |
        alignment
    ),
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