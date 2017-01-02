#include "Win33DropDown.h"

#include <windowsx.h>

#include "Win33BitfieldOperators.h"

Win33::DropDown::DropDown(
          Win33::Window*             parent,
    const Win33::Point&              position,
    const Win33::Size&               size,
    const std::vector<std::wstring>& options,
          bool                       readonly,
          Win33::ComboBoxStyle       style
):
ComboBox(
    parent,
    position,
    size,
    options,
    ( readonly ? Win33::ComboBoxStyle::DropDownList : Win33::ComboBoxStyle::DropDown )
)
{ }

void Win33::DropDown::showDropDown( ) {
    ComboBox_ShowDropdown( mHandle, true );
}
void Win33::DropDown::hideDropDown( ) {
    ComboBox_ShowDropdown( mHandle, false );
}