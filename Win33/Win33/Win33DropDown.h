#pragma once

#include "Win33ComboBox.h"

namespace Win33 {
    
    class DropDown : public ComboBox {
    public:
        DropDown(
                  Win33::Window*             parent,
            const Win33::Point&              position,
            const Win33::Size&               size,
            const std::vector<std::wstring>& options  = { },
                  bool                       readonly = false,
                  Win33::ComboBoxStyle       style    = Win33::ComboBoxStyle::None
        );
        DropDown            ( )                        = delete;
        DropDown            ( const DropDown&  other ) = delete;
        DropDown            (       DropDown&& other ) = default;
        DropDown& operator= ( const DropDown&  other ) = delete;
        DropDown& operator= (       DropDown&& other ) = default;
        ~DropDown           ( )                        = default;
        
        void showDropDown( );
        void hideDropDown( );
        
    };
    
};