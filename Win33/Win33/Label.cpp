#include "Label.h"

#include "BitfieldOperators.h"

Win33::Label::Label(
          Window*       parent,
    const Point&        position,
    const Size&         size,
    const std::wstring& text,
          StaticStyle   style
):
Control(
    Common::Type::Label,
    parent,
    position,
    size,
    WindowStyle::Child | StaticStyle::Notify | StaticStyle::Left | style,
    ExWindowStyle::None
) {
    setText( text );
}