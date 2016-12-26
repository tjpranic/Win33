#include "Win33MultilineTextBox.h"

#include "Win33BitfieldOperators.h"

Win33::MultilineTextBox::MultilineTextBox(
          Win33::Window*   parent,
    const Win33::Point&    position,
    const Win33::Size&     size,
          Win33::EditStyle style,
    const std::wstring&    text
):
Control(
    Win33::Common::Type::MultilineTextBox,
    parent,
    position,
    size,
    Win33::WindowStyle::Tabstop | Win33::WindowStyle::Child | Win33::EditStyle::Left | Win33::EditStyle::Multiline | style,
    Win33::ExWindowStyle::ClientEdge
) {
    setText( text );
}