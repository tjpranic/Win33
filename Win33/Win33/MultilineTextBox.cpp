#include "MultilineTextBox.h"

#include "BitfieldOperators.h"

Win33::MultilineTextBox::MultilineTextBox(
          Window*       parent,
    const Point&        position,
    const Size&         size,
    const std::wstring& text,
          EditStyle     style
):
TextBox(
    parent,
    position,
    size,
    text,
    EditStyle::Multiline | style
)
{ }