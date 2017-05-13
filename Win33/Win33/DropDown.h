#pragma once

#include "ComboBox.h"

namespace Win33 {
    
    class DropDown : public ComboBox {
    public:
        DropDown(
                  Window*                    parent,
            const Point&                     position,
            const Size&                      size,
            const std::vector<std::wstring>& options  = { },
                  bool                       readonly = false,
                  ComboBoxStyle              style    = ComboBoxStyle::None
        );
        DropDown            ( )                        = delete;
        DropDown            ( const DropDown&  other ) = delete;
        DropDown            (       DropDown&& other ) = delete;
        DropDown& operator= ( const DropDown&  other ) = delete;
        DropDown& operator= (       DropDown&& other ) = delete;
        ~DropDown           ( )                        = default;
        
        void showDropDown( );
        void hideDropDown( );
    };
    
};