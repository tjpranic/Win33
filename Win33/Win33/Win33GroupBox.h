#pragma once

#include "Win33Control.h"

namespace Win33 {
    
    class Application;
    
    class GroupBox : public Control {
    friend class Application;
    public:
        GroupBox( ) = delete;
        GroupBox(
                  Win33::Window* parent,
            const Point&         position,
            const Size&          size,
            const std::wstring&  title
        );
        GroupBox            ( const GroupBox&  other ) = default;
        GroupBox            (       GroupBox&& other );
        GroupBox& operator= ( const GroupBox&  other ) = default;
        GroupBox& operator= (       GroupBox&& other );
        ~GroupBox           ( )                        = default;
        
        std::wstring getTitle( ) const;
        
        void setTitle( const std::wstring& title );
    };
    
};