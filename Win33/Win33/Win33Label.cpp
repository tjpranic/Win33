#include "Win33Label.h"

#include "Win33BitfieldOperators.h"

Win33::Label::Label(
          Win33::Window*     parent,
    const Win33::Point&      position,
    const Win33::Size&       size,
    const std::wstring&      text,
          Win33::StaticStyle style
):
Control(
    Win33::Common::Type::Label,
    parent,
    position,
    size,
    Win33::WindowStyle::Child | Win33::StaticStyle::Notify | Win33::StaticStyle::Left | style,
    Win33::ExWindowStyle::NoExWindowStyle
) {
    setText( text );
}
Win33::Label::Label( Label&& other )
:
Control( std::move( other ) ),
onClick( std::move( other.onClick ) )
{ }
Win33::Label& Win33::Label::operator=( Label&& other ) {
    Control::operator=( std::move( other ) );
    onClick = std::move( other.onClick );
    return *this;
}