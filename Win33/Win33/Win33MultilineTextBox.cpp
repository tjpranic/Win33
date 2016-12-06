#include "Win33MultilineTextBox.h"

Win33::MultilineTextBox::MultilineTextBox(
          Win33::Window*         parent,
    const Win33::Point&          position,
    const Win33::Size&           size,
          Win33::EditStyle::Type style,
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
        style
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