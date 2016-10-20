#pragma once

#include "Win33MenuItem.h"

namespace Win33 {
    
    class MenuBar;
    class ContextMenu;
    
    class Menu {
    friend class MenuBar;
    friend class ContextMenu;
    public:
        Menu  ( const std::wstring& text );
        ~Menu ( ) = default;
        
        std::wstring getText( )    const;
        bool         getEnabled( ) const;
        
        void setText    ( const std::wstring& text    );
        void setEnabled (       bool          enabled );
        
        void addSeparator ( );
        void addSubMenu   ( Menu*     menu );
        void addMenuItem  ( MenuItem* item );
        
    private:
        HMENU        mHandle;
        HMENU        mParent;
        int          mPosition;
        int          mSubMenuPosition;
        std::wstring mText;
    };
};