#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class GroupBox : public Control {
    public:
        GroupBox(
                  Win33::Window*     parent,
            const Win33::Point&      position,
            const Win33::Size&       size,
            const std::wstring&      title,
                  Win33::ButtonStyle style = Win33::ButtonStyle::None
        );
        GroupBox            ( )                        = delete;
        GroupBox            ( const GroupBox&  other ) = delete;
        GroupBox            (       GroupBox&& other ) = default;
        GroupBox& operator= ( const GroupBox&  other ) = delete;
        GroupBox& operator= (       GroupBox&& other ) = default;
        ~GroupBox           ( )                        = default;
        
        const std::wstring& getTitle( ) const;
        
        void setTitle( const std::wstring& title );
        
    private:
        std::wstring mTitle;
    };
    
};