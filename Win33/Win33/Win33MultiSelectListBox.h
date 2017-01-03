#pragma once

#include "Win33ListBox.h"

namespace Win33 {
    
    class MultiSelectListBox : public ListBox {
    public:
        MultiSelectListBox(
                  Win33::Window*             parent,
            const Win33::Point&              position,
            const Win33::Size&               size,
            const std::vector<std::wstring>& options  = { },
                  Win33::ListBoxStyle        style    = Win33::ListBoxStyle::None
        );
        MultiSelectListBox            ( )                                  = delete;
        MultiSelectListBox            ( const MultiSelectListBox&  other ) = delete;
        MultiSelectListBox            (       MultiSelectListBox&& other ) = default;
        MultiSelectListBox& operator= ( const MultiSelectListBox&  other ) = delete;
        MultiSelectListBox& operator= (       MultiSelectListBox&& other ) = default;
        ~MultiSelectListBox           ( )                                  = default;
        
        void setSelection   ( const std::vector<int>& selections );
        void unsetSelection ( const std::vector<int>& selections );
        void clearSelection ( );
        void selectAll      ( );
        
        int                       getSelectedOptionCount( ) const;
        std::vector<int>          getSelection( )           const;
        std::vector<std::wstring> getText( )                const;
    };
    
};