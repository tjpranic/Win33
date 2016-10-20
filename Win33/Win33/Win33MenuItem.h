#pragma once

#include "Win33MenuEvents.h"

namespace Win33 {
    
    class Application;
    class Menu;
    
    class MenuItem {
    friend class Application;
    friend class Menu;
    public:
        MenuItem  ( const std::wstring& text, bool checkable = false );
        ~MenuItem ( );
        
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
        static int generateID( );
        
        MenuEvents::Click mClick;
        
        HMENU        mParent;
        int          mID;
        std::wstring mText;
        bool         mEnabled;
        bool         mCheckable;
        bool         mChecked;
    };
    
};