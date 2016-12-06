#include "Win33Button.h"

Win33::Button::Button(
          Win33::Window*           parent,
    const Win33::Point&            position,
    const Win33::Size&             size,
    const std::wstring&            text,
          Win33::ButtonStyle::Type style
):
Control(
    Win33::Platform::Type::Button,
    parent,
    position,
    size,
    static_cast<Win33::WindowStyle::Type>(
        Win33::WindowStyle::Tabstop    |
        Win33::WindowStyle::Child      |
        Win33::ButtonStyle::PushButton |
        style
    )
) {
    setText( text );
}
Win33::Button::Button( Button&& other )
:
Control( std::move( other ) ),
onClick( std::move( other.onClick ) )
{ }
Win33::Button& Win33::Button::operator=( Button&& other ) {
    Control::operator=( std::move( other ) );
    onClick = std::move( other.onClick );
    return *this;
}