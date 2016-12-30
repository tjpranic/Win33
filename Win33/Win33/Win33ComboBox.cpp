#include "Win33ComboBox.h"

#include "Win33BitfieldOperators.h"

Win33::ComboBox::ComboBox(
          Win33::Window*             parent,
    const Win33::Point&              position,
    const Win33::Size&               size,
          Win33::ComboBoxStyle       style,
    const std::vector<std::wstring>& options
):
Win33::Control(
    Win33::Common::Type::ComboBox,
    parent,
    position,
    size,
    Win33::WindowStyle::Tabstop | Win33::WindowStyle::Child | Win33::ComboBoxStyle::AutoHorizontalScroll | Win33::ComboBoxStyle::Simple | Win33::ComboBoxStyle::HasStrings | style,
    Win33::ExWindowStyle::None
) {
    for( auto& option : options ) {
        addOption( option );
    }
}

void Win33::ComboBox::addOption( const std::wstring& option ) {
    SendMessage( mHandle, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>( option.c_str( ) ) );
}

void Win33::ComboBox::setSelection( int index ) {
    SendMessage( mHandle, CB_SETCURSEL, index, 0 );
}

void Win33::ComboBox::clearSelection( ) {
    SendMessage( mHandle, CB_SETCURSEL, -1, 0 );
}