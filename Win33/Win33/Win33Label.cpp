#include "Win33Label.h"

Win33::Label::Label(
          Win33::Window* parent,
    const Win33::Point&  position,
    const Win33::Size&   size,
    const std::wstring&  text
):
Control(
    Win33::Platform::Type::Label,
    parent,
    position,
    size,
    static_cast<Win33::WindowStyle::Type>(
        Win33::WindowStyle::Child  |
        Win33::StaticStyle::Notify |
        Win33::StaticStyle::Left
    ),
    Win33::ExWindowStyle::NoExWindowStyle
) {
    setText( text );
}
Win33::Label::Label( Label&& other )
:
Control( std::move( other ) ),
onClick( std::move( other.onClick ) )
{ }
Win33::Label& Win33::Label::operator=( Label&& other ) {
    Control::operator=( std::move( other ) );
    onClick = std::move( other.onClick );
    return *this;
}