#include "ComboBox.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

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
          Window*                    parent,
    const Point&                     position,
    const Size&                      size,
    const std::vector<std::wstring>& options,
          ComboBoxStyle              style
):
Control(
    Common::getTypeFromStyle( style ),
    parent,
    position,
    size,
    WindowStyle::Tabstop | WindowStyle::Child | ComboBoxStyle::AutoHorizontalScroll | ComboBoxStyle::HasStrings | restyle( style ),
    ExWindowStyle::None
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
int Win33::ComboBox::getSelection( ) const {
    return ComboBox_GetCurSel( mHandle );
}