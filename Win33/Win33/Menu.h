#pragma once

#include "MenuBar.h"

namespace Win33 {
    
    class Menu {
    public:
        Menu            ( ContextMenu* contextMenu, const std::wstring& text );
        Menu            ( MenuBar*     menuBar,     const std::wstring& text );
        Menu            ( Menu*        menu,        const std::wstring& text );
        Menu            ( )                    = delete;
        Menu            ( const Menu&  other ) = delete;
        Menu            (       Menu&& other ) = delete;
        Menu& operator= ( const Menu&  other ) = delete;
        Menu& operator= (       Menu&& other ) = delete;
        ~Menu           ( )                    = default;
        
        std::wstring getText( )    const;
        bool         getEnabled( ) const;
        
        void setText    ( const std::wstring& text    );
        void setEnabled (       bool          enabled );
        
        friend HMENU Interop::toHandle( const Menu* menu );
        
    private:
        HMENU mHandle;
        HMENU mParent;
        int   mPosition;
    };
    
};