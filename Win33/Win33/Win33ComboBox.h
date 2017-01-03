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
            const std::vector<std::wstring>& options = { },
                  Win33::ComboBoxStyle       style   = Win33::ComboBoxStyle::None
        );
        ComboBox            ( )                        = delete;
        ComboBox            ( const ComboBox&  other ) = delete;
        ComboBox            (       ComboBox&& other ) = default;
        ComboBox& operator= ( const ComboBox&  other ) = delete;
        ComboBox& operator= (       ComboBox&& other ) = default;
        virtual ~ComboBox   ( )                        = default;
        
        void addOption    ( const std::wstring& option );
        void insertOption ( int index, const std::wstring& option );
        void removeOption ( int index );
        
        void setSelection   ( int index );
        void clearSelection ( );
        
        int getOptionCount( ) const;
        int getSelection( )   const;
    };
    
};