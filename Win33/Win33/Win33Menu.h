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
        
        void      addSeparator ( );
        Menu&     addSubMenu   ( const std::wstring& text );
        MenuItem& addMenuItem  ( const std::wstring& text, bool checkable = false );
        
    private:
        Menu( HMENU parent, int position, const std::wstring& text );
        
        HMENU        mHandle;
        HMENU        mParent;
        int          mPosition;
        std::wstring mText;
        int          mLastPosition;
        
        std::list<std::pair<int, Menu>>     mSubMenus;
        std::list<std::pair<int, MenuItem>> mMenuItems;
    };
};