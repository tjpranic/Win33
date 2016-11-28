#pragma once

#include <string>

#include <Windows.h>

#include "Win33Window.h"
#include "Win33ContextMenu.h"
#include "Win33Icon.h"
#include "Win33TrayIconEvents.h"

#define WM_TRAYICON ( WM_USER + 0x02 )

namespace Win33 {
    
    class Application;
    
    class TrayIcon {
    friend class Application;
    public:
        TrayIcon(
                  Window*       parent,
            const Icon&         icon,
            const std::wstring& tooltip
        );
        TrayIcon            ( const TrayIcon&  other ) = delete;
        TrayIcon            (       TrayIcon&& other );
        TrayIcon& operator= ( const TrayIcon&  other ) = delete;
        TrayIcon& operator= (       TrayIcon&& other );
        ~TrayIcon           ( );
        
        void setContextMenu( ContextMenu* menu );
        
        TrayIconEvents::LeftClick  leftClick;
        TrayIconEvents::RightClick rightClick;
        
    private:
        int generateID( );
        
        Window*        mParent;
        NOTIFYICONDATA mNID;
        ContextMenu*   mContextMenu;
    };
    
};