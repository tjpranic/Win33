#include "Win33Button.h"

#include "Win33BitfieldOperators.h"

Win33::Button::Button(
          Win33::Window*     parent,
    const Win33::Point&      position,
    const Win33::Size&       size,
    const std::wstring&      text,
          Win33::ButtonStyle style
):
Control(
    Win33::Common::Type::Button,
    parent,
    position,
    size,
    Win33::WindowStyle::Tabstop | Win33::WindowStyle::Child | Win33::ButtonStyle::PushButton | style
) {
    setText( text );
}