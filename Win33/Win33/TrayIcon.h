#pragma once

#include "Window.h"
#include "TrayIconEvents.h"
#include "Icon.h"

#define WM_TRAYICON ( WM_USER + 0x01 )

namespace Win33 {
    
    class TrayIcon {
    public:
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
        
        TrayIconEvents::LeftClick  onLeftClick;
        TrayIconEvents::RightClick onRightClick;
        
    private:
        int generateID( );
        
        NOTIFYICONDATA mNID;
    };
    
};