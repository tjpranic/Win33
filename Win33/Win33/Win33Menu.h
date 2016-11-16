#pragma once

#include <list>

#include "Win33MenuItem.h"

namespace Win33 {
    
    class MenuBar;
    class ContextMenu;
    
    class Menu {
    friend class MenuBar;
    friend class ContextMenu;
    public:
        ~Menu( ) = default;
        
        std::wstring getText( )    const;
        bool         getEnabled( ) const;
        
        void setText    ( const std::wstring& text    );
        void setEnabled (       bool          enabled );
        
        void      appendSeparator ( );
        Menu&     appendSubMenu   ( const std::wstring& text );
        MenuItem& appendMenuItem  ( const std::wstring& text, bool checkable = false );
        
    private:
        Menu( HMENU parent, int position, const std::wstring& text );
        
        HMENU        mHandle;
        HMENU        mParent;
        int          mPosition;
        std::wstring mText;
        int          mLastPosition;
        
        std::list<Menu>     mSubMenus;
        std::list<MenuItem> mMenuItems;
    };
};