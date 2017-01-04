#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class ListBox : public Control {
    public:
        ListBox(
                  Win33::Window*             parent,
            const Win33::Point&              position,
            const Win33::Size&               size,
            const std::vector<std::wstring>& options = { },
                  Win33::ListBoxStyle        style   = Win33::ListBoxStyle::None
        );
        ListBox            ( )                       = delete;
        ListBox            ( const ListBox&  other ) = delete;
        ListBox            (       ListBox&& other ) = delete;
        ListBox& operator= ( const ListBox&  other ) = delete;
        ListBox& operator= (       ListBox&& other ) = delete;
        virtual ~ListBox   ( )                       = default;
        
        void addOption    ( const std::wstring& option );
        void insertOption ( int index, const std::wstring& option );
        void removeOption ( int index );
        
        void setSelection   ( int index );
        void clearSelection ( );
        
        int          getOptionCount ( )               const;
        int          getSelection   ( )               const;
        std::wstring getText        ( int index = 0 ) const;
    };
    
};