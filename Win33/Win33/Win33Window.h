#pragma once

#include "Win33Platform.h"
#include "Win33MenuBar.h"
#include "Win33ContextMenu.h"
#include "Win33Interop.h"
#include "Win33WindowEvents.h"

namespace Win33 {
    
    const Win33::Point DefaultPosition = { CW_USEDEFAULT, CW_USEDEFAULT };
    const Win33::Size  DefaultSize     = { CW_USEDEFAULT, CW_USEDEFAULT };
    
    class Window : public Platform {
    public:
        Window            ( )                      = delete;
        Window            ( const Window&  other ) = delete;
        Window            (       Window&& other );
        Window& operator= ( const Window&  other ) = delete;
        Window& operator= (       Window&& other );
        virtual ~Window   ( )                      = default;
        
        void close( );
        void minimize( );
        void maximize( );
        void toggleVisibility( );
        
              std::wstring        getTitle( )       const;
              bool                getResizable( )   const;
              Win33::MenuBar*     getMenuBar( )     const;
              Win33::ContextMenu* getContextMenu( ) const;
        const std::wstring&       getIcon( )        const;
        
        void setTitle       ( const std::wstring&       title       );
        void setResizable   (       bool                resizable   );
        void setMenuBar     (       Win33::MenuBar*     menuBar     );
        void setContextMenu (       Win33::ContextMenu* contextMenu );
        void setIcon        ( const std::wstring&       icon        );
        void setMaximizable (       bool                maximizable );
        void setMinimizable (       bool                minimizable );
        
        Win33::WindowEvents::Idle   onIdle;
        Win33::WindowEvents::Close  onClose;
        Win33::WindowEvents::Resize onResize;
        Win33::WindowEvents::Move   onMove;
        
        friend HWND Win33::Interop::windowToHandle( Win33::Window* window );
        
    protected:
        Window(
            const Win33::Point&              position,
            const Win33::Size&               size,
                  Win33::WindowStyle::Type   style   = Win33::WindowStyle::OverlappedWindow,
                  Win33::ExWindowStyle::Type exStyle = Win33::ExWindowStyle::NoExWindowStyle
        );
        Window(
                  Win33::Window*             parent,
            const Win33::Point&              position,
            const Win33::Size&               size,
                  Win33::WindowStyle::Type   style   = Win33::WindowStyle::OverlappedWindow,
                  Win33::ExWindowStyle::Type exStyle = Win33::ExWindowStyle::NoExWindowStyle
        );
        
    private:
        bool                mResizable;
        bool                mMaximizable;
        bool                mMinimizable;
        Win33::MenuBar*     mMenuBar;
        Win33::ContextMenu* mContextMenu;
        std::wstring        mIcon;
    };
    
};