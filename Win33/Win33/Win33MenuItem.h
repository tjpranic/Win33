#pragma once

#include "Win33Menu.h"
#include "Win33MenuItemEvents.h"

namespace Win33 {
    
    class MenuItem {
    public:
        MenuItem            ( Win33::ContextMenu* contextMenu, const std::wstring& text );
        MenuItem            ( Win33::Menu*        menu,        const std::wstring& text );
        MenuItem            ( )                        = delete;
        MenuItem            ( const MenuItem&  other ) = delete;
        MenuItem            (       MenuItem&& other ) = delete;
        MenuItem& operator= ( const MenuItem&  other ) = delete;
        MenuItem& operator= (       MenuItem&& other ) = delete;
        ~MenuItem           ( );
        
        void toggleChecked( );
        
        std::wstring getText( )    const;
        bool         getEnabled( ) const;
        bool         getChecked( ) const;
        
        void setText    ( const std::wstring& text    );
        void setEnabled (       bool          enabled );
        void setChecked (       bool          checked );
        
        Win33::MenuItemEvents::Click onClick;
        
    private:
        static int generateID( );
        
        HMENU mParent;
        int   mID;
    };
    
};