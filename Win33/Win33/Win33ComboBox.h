#pragma once

#include <vector>

#include "Win33Control.h"

namespace Win33 {
    
    class ComboBox : public Control {
    public:
        ComboBox(
                  Win33::Window*             parent,
            const Win33::Point&              position,
            const Win33::Size&               size,
                  Win33::ComboBoxStyle       style   = Win33::ComboBoxStyle::None,
            const std::vector<std::wstring>& options = { L"" }
        );
        ComboBox            ( )                        = delete;
        ComboBox            ( const ComboBox&  other ) = delete;
        ComboBox            (       ComboBox&& other ) = default;
        ComboBox& operator= ( const ComboBox&  other ) = delete;
        ComboBox& operator= (       ComboBox&& other ) = default;
        ~ComboBox           ( )                        = default;
        
        void addOption( const std::wstring& option );
        
        void setSelection( int index );
        
        void clearSelection( );
    };
    
};