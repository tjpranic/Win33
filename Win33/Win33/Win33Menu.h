#pragma once

#include <list>

#include "Win33MenuItem.h"
#include "Win33Interop.h"

namespace Win33 {
    
    class ContextMenu;
    class MenuBar;
    
    class Menu {
    friend class ContextMenu;
    friend class MenuBar;
    public:
        Menu            ( )                    = delete;
        Menu            ( const Menu&  other ) = delete;
        Menu            (       Menu&& other );
        Menu& operator= ( const Menu&  other ) = delete;
        Menu& operator= (       Menu&& other );
        ~Menu           ( )                    = default;
        
        std::wstring getText( )    const;
        bool         getEnabled( ) const;
        
        void setText    ( const std::wstring& text    );
        void setEnabled (       bool          enabled );
        
        void      appendSeparator ( );
        Menu&     appendSubMenu   ( const std::wstring& text );
        MenuItem& appendMenuItem  ( const std::wstring& text, bool checkable = false );
        
        friend HMENU Win33::Interop::menuToHandle( Win33::Menu* menu );
        
    private:
        Menu( HMENU parent, int position, const std::wstring& text );
        
        int mLastPosition;
        
        HMENU                      mHandle;
        HMENU                      mParent;
        int                        mPosition;
        std::wstring               mText;
        std::list<Win33::Menu>     mSubMenus;
        std::list<Win33::MenuItem> mMenuItems;
    };
};