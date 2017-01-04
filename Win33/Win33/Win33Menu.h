#pragma once

#include "Win33MenuBar.h"

namespace Win33 {
    
    class Menu {
    public:
        Menu            ( Win33::ContextMenu* contextMenu, const std::wstring& text );
        Menu            ( Win33::MenuBar*     menuBar,     const std::wstring& text );
        Menu            ( Win33::Menu*        menu,        const std::wstring& text );
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
        
        friend HMENU Win33::Interop::toHandle( const Win33::Menu* menu );
        
    private:
        HMENU mHandle;
        HMENU mParent;
        int   mPosition;
    };
    
};