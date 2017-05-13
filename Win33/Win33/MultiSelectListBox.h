#pragma once

#include "ListBox.h"

namespace Win33 {
    
    class MultiSelectListBox : public ListBox {
    public:
        MultiSelectListBox(
                  Window*                    parent,
            const Point&                     position,
            const Size&                      size,
            const std::vector<std::wstring>& options  = { },
                  ListBoxStyle               style    = ListBoxStyle::None
        );
        MultiSelectListBox            ( )                                  = delete;
        MultiSelectListBox            ( const MultiSelectListBox&  other ) = delete;
        MultiSelectListBox            (       MultiSelectListBox&& other ) = delete;
        MultiSelectListBox& operator= ( const MultiSelectListBox&  other ) = delete;
        MultiSelectListBox& operator= (       MultiSelectListBox&& other ) = delete;
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