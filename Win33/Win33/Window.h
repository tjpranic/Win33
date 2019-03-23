#pragma once

#include "Common.h"
#include "Event.h"
#include "Keys.h"

namespace Win33 {

    class Window : public Common {
    public:
        DECLARE_EVENT( Destroy,    void( ),                        Application )
        DECLARE_EVENT( Close,      void(       bool&  cancelled ), Application )
        DECLARE_EVENT( Resize,     void( const Size&  size ),      Application )
        DECLARE_EVENT( Move,       void( const Point& position ),  Application )
        DECLARE_EVENT( LeftClick,  void( const Point& position ),  Application )
        DECLARE_EVENT( RightClick, void( const Point& position ),  Application )
        DECLARE_EVENT( KeyDown,    void(       Key    key ),       Application )
        DECLARE_EVENT( KeyUp,      void(       Key    key ),       Application )

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

        Destroy    onDestroy;
        Close      onClose;
        Resize     onResize;
        Move       onMove;
        LeftClick  onLeftClick;
        RightClick onRightClick;
        KeyDown    onKeyDown;
        KeyUp      onKeyUp;

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

}