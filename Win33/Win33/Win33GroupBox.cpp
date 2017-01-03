#include "Win33GroupBox.h"

#include "Win33BitfieldOperators.h"

Win33::GroupBox::GroupBox(
          Win33::Window* parent,
    const Win33::Point&  position,
    const Win33::Size&   size,
    const std::wstring&  text,
    Win33::ButtonStyle   style
):
Control(
    Win33::Common::Type::GroupBox,
    parent,
    position,
    size,
    Win33::WindowStyle::Child | Win33::ButtonStyle::GroupBox | style
) {
    setText( text );
}