#include "Win33GroupBox.h"

#include "Win33BitfieldOperators.h"

Win33::GroupBox::GroupBox(
          Win33::Window* parent,
    const Win33::Point&  position,
    const Win33::Size&   size,
    const std::wstring&  title,
    Win33::ButtonStyle   style
):
Control(
    Win33::Platform::Type::GroupBox,
    parent,
    position,
    size,
    Win33::WindowStyle::Child | Win33::ButtonStyle::GroupBox | style
),
mTitle( title )
{
    setTitle( title );
}
Win33::GroupBox::GroupBox( GroupBox&& other )
:
Control ( std::move( other ) ),
mTitle  ( std::move( other.mTitle ) )
{ }
Win33::GroupBox& Win33::GroupBox::operator=( GroupBox&& other ) {
    Control::operator=( std::move( other ) );
    mTitle = std::move( other.mTitle );
    return *this;
}

const std::wstring& Win33::GroupBox::getTitle( ) const {
    return mTitle;
}

void Win33::GroupBox::setTitle( const std::wstring& title ) {
    mTitle = title;
    
    SetWindowText( mHandle, title.c_str( ) );
}