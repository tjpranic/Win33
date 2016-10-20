#include "Win33GroupBox.h"

Win33::GroupBox::GroupBox(
          Win33::Window* parent,
    const Point&         position,
    const Size&          size,
    const std::wstring&  title
):
Control(
    Type::GroupBox,
    parent,
    position,
    size,
    static_cast<WindowStyle::Type>( WindowStyle::Child | ButtonStyle::GroupBox )
) {
    setTitle( title );
}
Win33::GroupBox::GroupBox( GroupBox&& other )
:
Control( std::move( other ) )
{ }
Win33::GroupBox& Win33::GroupBox::operator=( GroupBox&& other ) {
    Control::operator=( std::move( other ) );
    return *this;
}

std::wstring Win33::GroupBox::getTitle( ) const {
    static wchar_t t[256];
    GetWindowText( mHandle, t, 256 );
    return std::wstring( t );
}

void Win33::GroupBox::setTitle( const std::wstring& title ) {
    SetWindowText( mHandle, title.c_str( ) );
}