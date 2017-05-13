#include "ListBox.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

Win33::ListBox::ListBox(
          Window*                    parent,
    const Point&                     position,
    const Size&                      size,
    const std::vector<std::wstring>& options,
          ListBoxStyle               style
):
Control(
    Common::getTypeFromStyle( style ),
    parent,
    position,
    size,
    WindowStyle::Tabstop | WindowStyle::Child | ListBoxStyle::HasStrings | style,
    ExWindowStyle::ClientEdge
) {
    for( auto& option : options ) {
        addOption( option );
    }
}

void Win33::ListBox::addOption( const std::wstring& option ) {
    ListBox_AddString( mHandle, option.c_str( ) );
}
void Win33::ListBox::insertOption( int index, const std::wstring& option ) {
    ListBox_InsertString( mHandle, index, option.c_str( ) );
}
void Win33::ListBox::removeOption( int index ) {
    ListBox_DeleteString( mHandle, index );
}

void Win33::ListBox::setSelection( int index ) {
    ListBox_SetCurSel( mHandle, index );
}
void Win33::ListBox::clearSelection( ) {
    ListBox_SetCurSel( mHandle, -1 );
}

int Win33::ListBox::getOptionCount( ) const {
    return ListBox_GetCount( mHandle );
}
int Win33::ListBox::getSelection( ) const {
    return ListBox_GetCurSel( mHandle );
}

std::wstring Win33::ListBox::getText( int index ) const {
    if( index >= 0 ) {
        static wchar_t text[256];
        ListBox_GetText( mHandle, index, text );
        return std::wstring( text );
    }
    else {
        return L"";
    }
}