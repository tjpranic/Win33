#include "Button.h"

#include "BitfieldOperators.h"

Win33::Button::Button(
          Window*       parent,
    const Point&        position,
    const Size&         size,
    const std::wstring& text,
          ButtonStyle   style
):
Control(
    Common::Type::Button,
    parent,
    position,
    size,
    WindowStyle::Tabstop | WindowStyle::Child | ButtonStyle::PushButton | style
) {
    setText( text );
}