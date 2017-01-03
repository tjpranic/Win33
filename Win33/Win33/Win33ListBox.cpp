#include "Win33ListBox.h"

#include <windowsx.h>

#include "Win33BitfieldOperators.h"

Win33::ListBox::ListBox(
          Win33::Window*             parent,
    const Win33::Point&              position,
    const Win33::Size&               size,
    const std::vector<std::wstring>& options,
          Win33::ListBoxStyle        style
):
Control(
    Win33::Common::getTypeFromStyle( style ),
    parent,
    position,
    size,
    Win33::WindowStyle::Tabstop | Win33::WindowStyle::Child | Win33::ListBoxStyle::HasStrings | style,
    Win33::ExWindowStyle::ClientEdge
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