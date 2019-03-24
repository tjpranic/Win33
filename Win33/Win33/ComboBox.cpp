#include "ComboBox.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

namespace Win33 {

    //adds Simple style to passed in style if not constructing from subclass
    ComboBoxStyle restyle( Win33::ComboBoxStyle style ) {
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

    ComboBox::ComboBox(
              Window*                    parent,
        const Point&                     position,
        const Size&                      size,
        const std::vector<std::wstring>& options,
              ComboBoxStyle              style
    ):
    Control(
        L"COMBOBOX",
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

    void ComboBox::addOption( const std::wstring& option ) {
        ComboBox_AddString( mHandle, option.c_str( ) );
    }
    void ComboBox::insertOption( int index, const std::wstring& option ) {
        ComboBox_InsertString( mHandle, index, option.c_str( ) );
    }
    void ComboBox::removeOption( int index ) {
        ComboBox_DeleteString( mHandle, index );
    }

    void ComboBox::setSelection( int index ) {
        ComboBox_SetCurSel( mHandle, index );
    }
    void ComboBox::clearSelection( ) {
        ComboBox_SetCurSel( mHandle, -1 );
    }

    int ComboBox::getOptionCount( ) const {
        return ComboBox_GetCount( mHandle );
    }
    int ComboBox::getSelection( ) const {
        return ComboBox_GetCurSel( mHandle );
    }

}