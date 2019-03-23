#pragma once

#include "Control.h"

namespace Win33 {

    class ListBox : public Control {
    public:
        ListBox(
                  Window*                    parent,
            const Point&                     position,
            const Size&                      size,
            const std::vector<std::wstring>& options = { },
                  ListBoxStyle               style   = ListBoxStyle::None
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

}