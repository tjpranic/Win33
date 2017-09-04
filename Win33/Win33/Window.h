#pragma once

#include "Common.h"
#include "Interop.h"
#include "WindowEvents.h"

namespace Win33 {
    
    class Window : public Common {
    public:
        Window            ( const Window&  other ) = delete;
        Window            (       Window&& other ) = delete;
        Window& operator= ( const Window&  other ) = delete;
        Window& operator= (       Window&& other ) = delete;
        virtual ~Window   ( )                      = default;
        
        static const Point DefaultPosition;
        static const Size  DefaultSize;
        
        void close( );
        void minimize( );
        void maximize( );
        void restore( );
        void toggleVisibility( );
        
        std::wstring getTitle( )       const;
        bool         getResizable( )   const;
        bool         getMaximizable( ) const;
        bool         getMinimizable( ) const;
        bool         getMinimized( )   const;
        bool         getMaximized( )   const;
        
        void setTitle       ( const std::wstring& title       );
        void setResizable   (       bool          resizable   );
        void setIcon        ( const std::wstring& icon        );
        void setMaximizable (       bool          maximizable );
        void setMinimizable (       bool          minimizable );
        void setMinimzed    (       bool          minimized   );
        void setMaximized   (       bool          maximized   );
        
        WindowEvents::Close      onClose;
        WindowEvents::Destroy    onDestroy;
        WindowEvents::Resize     onResize;
        WindowEvents::Move       onMove;
        WindowEvents::LeftClick  onLeftClick;
        WindowEvents::RightClick onRightClick;
        WindowEvents::KeyDown    onKeyDown;
        WindowEvents::KeyUp      onKeyUp;
        
        friend HWND Interop::toHandle( const Window* window );
        
    protected:
        Window(
            const Point&        position = Window::DefaultPosition,
            const Size&         size     = Window::DefaultSize,
                  WindowStyle   style    = WindowStyle::OverlappedWindow,
                  ExWindowStyle exStyle  = ExWindowStyle::None
        );
        Window(
                  Window*       parent,
            const Point&        position = Window::DefaultPosition,
            const Size&         size     = Window::DefaultSize,
                  WindowStyle   style    = WindowStyle::OverlappedWindow,
                  ExWindowStyle exStyle  = ExWindowStyle::None
        );
    };
    
};