#include "Win33MultilineTextBox.h"

Win33::MultilineTextBox::MultilineTextBox(
          Win33::Window*  parent,
    const Point&          position,
    const Size&           size,
          ScrollBar::Type scrollBar,
    const std::wstring&   text
):
Control(
    Type::MultilineTextBox,
    parent,
    position,
    size,
    static_cast<WindowStyle::Type>(
        WindowStyle::Tabstop |
        WindowStyle::Child   |
        EditStyle::Left      |
        EditStyle::Multiline |
        ( scrollBar == Win33::ScrollBar::Vertical   || scrollBar == Win33::ScrollBar::Both ? ( EditStyle::AutoVerticalScroll   | WindowStyle::VerticalScroll   ) : 0 ) |
        ( scrollBar == Win33::ScrollBar::Horizontal || scrollBar == Win33::ScrollBar::Both ? ( EditStyle::AutoHorizontalScroll | WindowStyle::HorizontalScroll ) : 0 )
    ),
    ExWindowStyle::ClientEdge
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