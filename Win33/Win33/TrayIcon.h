#pragma once

#include "Icon.h"
#include "Window.h"

#define WM_TRAYICON ( WM_USER + 0x01 )

namespace Win33 {

    class TrayIcon {
    public:
        DECLARE_EVENT( LeftClick,  void( const Point& position ), Application )
        DECLARE_EVENT( RightClick, void( const Point& position ), Application )

        TrayIcon(
                  Window*       window,
                  Icon*         icon,
            const std::wstring& tooltip
        );
        TrayIcon            ( )                        = delete;
        TrayIcon            ( const TrayIcon&  other ) = delete;
        TrayIcon            (       TrayIcon&& other ) = delete;
        TrayIcon& operator= ( const TrayIcon&  other ) = delete;
        TrayIcon& operator= (       TrayIcon&& other ) = delete;
        ~TrayIcon           ( )                        = default;

        void setIcon    (       Icon*         icon    );
        void setTooltip ( const std::wstring& tooltip );

        LeftClick  onLeftClick;
        RightClick onRightClick;

    private:
        NOTIFYICONDATA mNotifyIconData;
    };

}