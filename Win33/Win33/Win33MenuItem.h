#pragma once

#include "Win33MenuItemEvents.h"

namespace Win33 {
    
    class Menu;
    class ContextMenu;
    class Application;
    
    class MenuItem {
    friend class Menu;
    friend class ContextMenu;
    friend class Application;
    public:
        MenuItem            ( const MenuItem&  other ) = delete;
        MenuItem            (       MenuItem&& other );
        MenuItem& operator= ( const MenuItem&  other ) = delete;
        MenuItem& operator= (       MenuItem&& other );
        ~MenuItem( )                                   = default;
        
        void toggleChecked( );
        
        const std::wstring& getText( )      const;
              bool          getEnabled( )   const;
              bool          getCheckable( ) const;
              bool          getChecked( )   const;
        
        void setText      ( const std::wstring& text      );
        void setEnabled   (       bool          enabled   );
        void setCheckable (       bool          checkable );
        void setChecked   (       bool          checked   );
        
        MenuItemEvents::Click click;
        
    private:
        MenuItem( HMENU parent, const std::wstring& text, bool checkable = false );
        
        static int nextID( );
        
        HMENU        mParent;
        int          mID;
        std::wstring mText;
        bool         mCheckable;
        bool         mEnabled;
        bool         mChecked;
    };
    
};