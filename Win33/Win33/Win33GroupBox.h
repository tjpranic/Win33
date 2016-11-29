#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class GroupBox : public Control {
    public:
        GroupBox( ) = delete;
        GroupBox(
                  Win33::Window* parent,
            const Win33::Point&  position,
            const Win33::Size&   size,
            const std::wstring&  title
        );
        GroupBox            ( const GroupBox&  other ) = delete;
        GroupBox            (       GroupBox&& other );
        GroupBox& operator= ( const GroupBox&  other ) = delete;
        GroupBox& operator= (       GroupBox&& other );
        ~GroupBox           ( )                        = default;
        
        std::wstring getTitle( ) const;
        
        void setTitle( const std::wstring& title );
    };
    
};