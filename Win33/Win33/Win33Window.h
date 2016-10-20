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
        Window          ( ) = delete;
        virtual ~Window ( ) = default;
        
        void close( );
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
        
        void addIdleHandler   ( const WindowEvents::Handler&       handler );
        void addCloseHandler  ( const WindowEvents::Handler&       handler );
        void addResizeHandler ( const WindowEvents::ResizeHandler& handler );
        void addMovedHandler  ( const WindowEvents::MoveHandler&   handler );
        
        void removeIdleHandler   ( const WindowEvents::Handler&       handler );
        void removeCloseHandler  ( const WindowEvents::Handler&       handler );
        void removeResizeHandler ( const WindowEvents::ResizeHandler& handler );
        void removeMovedHandler  ( const WindowEvents::MoveHandler&   handler );
        
        void removeMenuBar( );
        void removeContextMenu( );
        
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
        Window            ( Window&  other ) = default;
        Window            ( Window&& other );
        Window& operator= ( Window&  other ) = default;
        Window& operator= ( Window&& other );
        
    private:
        WindowEvents::Idle   mIdle;
        WindowEvents::Close  mClose;
        WindowEvents::Resize mResize;
        WindowEvents::Move   mMove;
        
        bool         mResizable;
        bool         mMaximizable;
        bool         mMinimizable;
        MenuBar*     mMenuBar;
        ContextMenu* mContextMenu;
        Icon         mIcon;
    };
    
};