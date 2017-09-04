#include "MultiSelectListBox.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

Win33::MultiSelectListBox::MultiSelectListBox(
          Window*                    parent,
    const Point&                     position,
    const Size&                      size,
    const std::vector<std::wstring>& options,
          ListBoxStyle               style
):
ListBox(
    parent,
    position,
    size,
    options,
    ListBoxStyle::MultipleSelect | style
)
{ }

void Win33::MultiSelectListBox::setSelection( const std::vector<int>& selections ) {
    for( const auto& selection : selections ) {
        ListBox_SetSel( mHandle, true, selection );
    }
}
void Win33::MultiSelectListBox::unsetSelection( const std::vector<int>& selections ) {
    for( const auto& selection : selections ) {
        ListBox_SetSel( mHandle, false, selection );
    }
}
void Win33::MultiSelectListBox::clearSelection( ) {
    ListBox_SetSel( mHandle, false, -1 );
}
void Win33::MultiSelectListBox::selectAll( ) {
    ListBox_SetSel( mHandle, true, -1 );
}

int Win33::MultiSelectListBox::getSelectedOptionCount( ) const {
    return ListBox_GetSelCount( mHandle );
}
std::vector<int> Win33::MultiSelectListBox::getSelection( ) const {
    const auto count = getSelectedOptionCount( );
    if( count > 0 ) {
        const auto selections = std::vector<int>( count );
        ListBox_GetSelItems( mHandle, count, &selections[0] );
        return selections;
    }
    else {
        return std::vector<int>( );
    }
}
std::vector<std::wstring> Win33::MultiSelectListBox::getText( ) const {
          auto texts      = std::vector<std::wstring>( );
    const auto selections = getSelection( );
    for( auto selection : selections ) {
        texts.push_back( Win33::ListBox::getText( selection ) );
    }
    return texts;
}