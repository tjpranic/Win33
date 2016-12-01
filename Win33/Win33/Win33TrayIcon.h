#pragma once

#include "Win33Window.h"
#include "Win33TrayIconEvents.h"

#define WM_TRAYICON ( WM_USER + 0x01 )

namespace Win33 {
    
    class TrayIcon {
    public:
        TrayIcon(
                  Win33::Window* window,
            const std::wstring&  icon,
            const std::wstring&  tooltip
        );
        TrayIcon            ( const TrayIcon&  other ) = delete;
        TrayIcon            (       TrayIcon&& other );
        TrayIcon& operator= ( const TrayIcon&  other ) = delete;
        TrayIcon& operator= (       TrayIcon&& other );
        ~TrayIcon           ( )                        = default;
        
        void setIcon    ( const std::wstring& icon    );
        void setTooltip ( const std::wstring& tooltip );
        
        Win33::TrayIconEvents::LeftClick  onLeftClick;
        Win33::TrayIconEvents::RightClick onRightClick;
        
    private:
        int generateID( );
        
        NOTIFYICONDATA mNID;
    };
    
};