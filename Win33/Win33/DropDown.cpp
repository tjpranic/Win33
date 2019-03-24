#include "DropDown.h"

#include <windowsx.h>

#include "BitfieldOperators.h"

namespace Win33 {

    DropDown::DropDown(
              Window*                    parent,
        const Point&                     position,
        const Size&                      size,
        const std::vector<std::wstring>& options,
              bool                       readonly,
              ComboBoxStyle              style
    ):
    ComboBox(
        parent,
        position,
        size,
        options,
        ( readonly ? ComboBoxStyle::DropDownList : ComboBoxStyle::DropDown )
    )
    { }

    void DropDown::showDropDown( ) {
        ComboBox_ShowDropdown( mHandle, true );
    }
    void DropDown::hideDropDown( ) {
        ComboBox_ShowDropdown( mHandle, false );
    }

}