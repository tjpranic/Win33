#include "Win33MultilineTextBox.h"

#include "Win33BitfieldOperators.h"

Win33::MultilineTextBox::MultilineTextBox(
          Win33::Window*   parent,
    const Win33::Point&    position,
    const Win33::Size&     size,
    const std::wstring&    text,
          Win33::EditStyle style
):
TextBox(
    parent,
    position,
    size,
    text,
    Win33::EditStyle::Multiline | style
)
{ }