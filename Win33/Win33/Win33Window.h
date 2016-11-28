#pragma once

#include "Win33Platform.h"
#include "Win33MenuBar.h"
#include "Win33ContextMenu.h"
#include "Win33Icon.h"
#include "Win33WindowEvents.h"

namespace Win33 {
    
    const Point DefaultPosition = { CW_USEDEFAULT, CW_USEDEFAULT };
    const Size  DefaultSize     = { CW_USEDEFAULT, CW_USEDEFAULT };
    
    class Application;
    
    class Window : public Platform {
    friend class Application;
    public:
        Window            ( )                      = delete;
        Window            ( const Window&  other ) = delete;
        Window            (       Window&& other );
        Window& operator= ( const Window&  other ) = delete;
        Window& operator= (       Window&& other );
        virtual ~Window   ( )                      = default;
        
        void quit( );
        void minimize( );
        void maximize( );
        void toggleVisibility( );
        
              std::wstring getTitle( )       const;
              bool         getResizable( )   const;
              MenuBar&     getMenuBar( )     const;
              ContextMenu& getContextMenu( ) const;
        const Icon&        getIcon( )        const;
        
        void setTitle       ( const std::wstring& title     );
        void setResizable   (       bool          resizable );
        void setMenuBar     (       MenuBar*      menu      );
        void setContextMenu (       ContextMenu*  menu      );
        void setIcon        ( const Icon&         icon      );
        void setMaximizable ( bool maximizable );
        void setMinimizable ( bool minimizable );
        
        void removeMenuBar( );
        void removeContextMenu( );
        
        WindowEvents::Idle   idle;
        WindowEvents::Close  close;
        WindowEvents::Resize resize;
        WindowEvents::Move   move;
        
    protected:
        Window(
            const Point&              position,
            const Size&               size,
                  WindowStyle::Type   style   = WindowStyle::OverlappedWindow,
                  ExWindowStyle::Type exStyle = ExWindowStyle::NoExWindowStyle
        );
        Window(
                  Window*             parent,
            const Point&              position,
            const Size&               size,
                  WindowStyle::Type   style   = WindowStyle::OverlappedWindow,
                  ExWindowStyle::Type exStyle = ExWindowStyle::NoExWindowStyle
        );
        
    private:
        bool         mResizable;
        bool         mMaximizable;
        bool         mMinimizable;
        MenuBar*     mMenuBar;
        ContextMenu* mContextMenu;
        Icon         mIcon;
    };
    
};