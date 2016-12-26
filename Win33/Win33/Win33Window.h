#pragma once

#include "Win33Common.h"
#include "Win33Interop.h"
#include "Win33WindowEvents.h"

namespace Win33 {
    
    class Window : public Common {
    public:
        Window            ( const Window&  other ) = delete;
        Window            (       Window&& other ) = default;
        Window& operator= ( const Window&  other ) = delete;
        Window& operator= (       Window&& other ) = default;
        ~Window           ( )                      = default;
        
        static const Win33::Point DefaultPosition;
        static const Win33::Size  DefaultSize;
        
        void close( );
        void minimize( );
        void maximize( );
        void toggleVisibility( );
        
        const std::wstring& getTitle( )       const;
              bool          getResizable( )   const;
              bool          getMaximizable( ) const;
              bool          getMinimizable( ) const;
        
        void setTitle       ( const std::wstring& title       );
        void setResizable   (       bool          resizable   );
        void setIcon        ( const std::wstring& icon        );
        void setMaximizable (       bool          maximizable );
        void setMinimizable (       bool          minimizable );
        
        Win33::WindowEvents::Close      onClose;
        Win33::WindowEvents::Resize     onResize;
        Win33::WindowEvents::Move       onMove;
        Win33::WindowEvents::LeftClick  onLeftClick;
        Win33::WindowEvents::RightClick onRightClick;
        
        friend HWND Win33::Interop::toHandle( const Win33::Window* window );
        
    protected:
        Window(
            const Win33::Point&        position = Win33::Window::DefaultPosition,
            const Win33::Size&         size     = Win33::Window::DefaultSize,
                  Win33::WindowStyle   style    = Win33::WindowStyle::OverlappedWindow,
                  Win33::ExWindowStyle exStyle  = Win33::ExWindowStyle::None
        );
        Window(
                  Win33::Window*       parent,
            const Win33::Point&        position,
            const Win33::Size&         size,
                  Win33::WindowStyle   style   = Win33::WindowStyle::OverlappedWindow,
                  Win33::ExWindowStyle exStyle = Win33::ExWindowStyle::None
        );
        
    private:
        bool         mResizable;
        bool         mMaximizable;
        bool         mMinimizable;
        std::wstring mTitle;
    };
    
};