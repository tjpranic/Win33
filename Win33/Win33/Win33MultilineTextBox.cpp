#include "Win33MultilineTextBox.h"

Win33::MultilineTextBox::MultilineTextBox(
          Win33::Window*         parent,
    const Win33::Point&          position,
    const Win33::Size&           size,
          Win33::ScrollBar::Type scrollBar,
    const std::wstring&          text
):
Control(
    Type::MultilineTextBox,
    parent,
    position,
    size,
    static_cast<Win33::WindowStyle::Type>(
        Win33::WindowStyle::Tabstop |
        Win33::WindowStyle::Child   |
        Win33::EditStyle::Left      |
        Win33::EditStyle::Multiline |
        ( scrollBar == Win33::ScrollBar::Vertical   || scrollBar == Win33::ScrollBar::Both ? ( Win33::EditStyle::AutoVerticalScroll   | Win33::WindowStyle::VerticalScroll   ) : 0 ) |
        ( scrollBar == Win33::ScrollBar::Horizontal || scrollBar == Win33::ScrollBar::Both ? ( Win33::EditStyle::AutoHorizontalScroll | Win33::WindowStyle::HorizontalScroll ) : 0 )
    ),
    Win33::ExWindowStyle::ClientEdge
) {
    setText( text );
}
Win33::MultilineTextBox::MultilineTextBox( MultilineTextBox&& other )
:
Control( std::move( other ) )
{ }
Win33::MultilineTextBox& Win33::MultilineTextBox::operator=( MultilineTextBox&& other ) {
    Control::operator=( std::move( other ) );
    return *this;
}

std::wstring Win33::MultilineTextBox::getText( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}

void Win33::MultilineTextBox::setText( const std::wstring& text ) {
    SetWindowText( mHandle, text.c_str( ) );
}