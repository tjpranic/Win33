#pragma once

#include "Menu.h"
#include "MenuItemEvents.h"

namespace Win33 {
    
    class MenuItem {
    public:
        MenuItem            ( ContextMenu* contextMenu, const std::wstring& text );
        MenuItem            ( Menu*        menu,        const std::wstring& text );
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
        
        MenuItemEvents::Click onClick;
        
    private:
        static int generateID( );
        
        HMENU mParent;
        int   mID;
    };
    
};