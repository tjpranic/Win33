#include "GroupBox.h"

#include "BitfieldOperators.h"

Win33::GroupBox::GroupBox(
          Window*       parent,
    const Point&        position,
    const Size&         size,
    const std::wstring& text,
          ButtonStyle   style
):
Control(
    Common::Type::GroupBox,
    parent,
    position,
    size,
    WindowStyle::Child | ButtonStyle::GroupBox | style
) {
    setText( text );
}