#include "Win33ComboBox.h"

#include <windowsx.h>

#include "Win33BitfieldOperators.h"

//adds Simple style to passed in style if not constructing from subclass
Win33::ComboBoxStyle restyle( Win33::ComboBoxStyle style ) {
    if( ( style & Win33::ComboBoxStyle::DropDownList ) == Win33::ComboBoxStyle::DropDownList ) {
        return style;
    }
    else if( ( style & Win33::ComboBoxStyle::DropDown ) == Win33::ComboBoxStyle::DropDown ) {
        return style;
    }
    else {
        return Win33::ComboBoxStyle::Simple | style;
    }
}

Win33::ComboBox::ComboBox(
          Win33::Window*             parent,
    const Win33::Point&              position,
    const Win33::Size&               size,
    const std::vector<std::wstring>& options,
          Win33::ComboBoxStyle       style
):
Control(
    Win33::Common::getTypeFromStyle( style ),
    parent,
    position,
    size,
    Win33::WindowStyle::Tabstop | Win33::WindowStyle::Child | Win33::ComboBoxStyle::AutoHorizontalScroll | Win33::ComboBoxStyle::HasStrings | restyle( style ),
    Win33::ExWindowStyle::None
) {
    for( auto& option : options ) {
        addOption( option );
    }
}

void Win33::ComboBox::addOption( const std::wstring& option ) {
    ComboBox_AddString( mHandle, option.c_str( ) );
}
void Win33::ComboBox::insertOption( int index, const std::wstring& option ) {
    ComboBox_InsertString( mHandle, index, option.c_str( ) );
}
void Win33::ComboBox::removeOption( int index ) {
    ComboBox_DeleteString( mHandle, index );
}

void Win33::ComboBox::setSelection( int index ) {
    ComboBox_SetCurSel( mHandle, index );
}
void Win33::ComboBox::clearSelection( ) {
    ComboBox_SetCurSel( mHandle, -1 );
}

int Win33::ComboBox::getOptionCount( ) const {
    return ComboBox_GetCount( mHandle );
}