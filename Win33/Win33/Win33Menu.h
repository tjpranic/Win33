#pragma once

#include <list>

#include "Win33MenuItem.h"

namespace Win33 {
    
    class Menu {
    public:
        Menu            ( HMENU parent, int position, const std::wstring& text );
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
        
        HMENU getHandle( ) const;
        
    private:
        int mLastPosition;
        
        HMENU                      mHandle;
        HMENU                      mParent;
        int                        mPosition;
        std::wstring               mText;
        std::list<Win33::Menu>     mSubMenus;
        std::list<Win33::MenuItem> mMenuItems;
    };
};