#pragma once

#include "Win33MenuEvents.h"

namespace Win33 {
    
    class Menu;
    class ContextMenu;
    class Application;
    
    class MenuItem {
    friend class Menu;
    friend class ContextMenu;
    friend class Application;
    public:
        ~MenuItem( ) = default;
        
        void toggleChecked( );
        
        const std::wstring& getText( )      const;
              bool          getEnabled( )   const;
              bool          getCheckable( ) const;
              bool          getChecked( )   const;
        
        void setText      ( const std::wstring& text      );
        void setEnabled   (       bool          enabled   );
        void setCheckable (       bool          checkable );
        void setChecked   (       bool          checked   );
        
        void addClickHandler( const MenuEvents::ClickHandler& handler );
        
        void removeClickHandler( const MenuEvents::ClickHandler& handler );
        
    private:
        MenuItem( HMENU parent, int position, const std::wstring& text, bool checkable = false );
        
        MenuEvents::Click mClick;
        
        HMENU        mParent;
        int          mPosition;
        std::wstring mText;
        bool         mCheckable;
        bool         mEnabled;
        bool         mChecked;
    };
    
};