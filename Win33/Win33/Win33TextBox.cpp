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
    
    //auto font = CreateFont( 48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact") );
    //SendMessage( mHandle, WM_SETFONT, reinterpret_cast<WPARAM>( font ), MAKELPARAM( TRUE, 0 ) );
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