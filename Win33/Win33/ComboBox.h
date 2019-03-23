#pragma once

#include <vector>

#include "Control.h"

namespace Win33 {

    class ComboBox : public Control {
    public:
        ComboBox(
                  Window*                    parent,
            const Point&                     position,
            const Size&                      size,
            const std::vector<std::wstring>& options = { },
                  ComboBoxStyle              style   = ComboBoxStyle::None
        );
        ComboBox            ( )                        = delete;
        ComboBox            ( const ComboBox&  other ) = delete;
        ComboBox            (       ComboBox&& other ) = delete;
        ComboBox& operator= ( const ComboBox&  other ) = delete;
        ComboBox& operator= (       ComboBox&& other ) = delete;
        virtual ~ComboBox   ( )                        = default;

        void addOption    ( const std::wstring& option );
        void insertOption ( int index, const std::wstring& option );
        void removeOption ( int index );

        void setSelection   ( int index );
        void clearSelection ( );

        int getOptionCount( ) const;
        int getSelection( )   const;
    };

}