#pragma once

#include "Win33Window.h"
#include "Win33ContextMenu.h"
#include "Win33TrayIconEvents.h"

#define WM_TRAYICON ( WM_USER + 0x02 )

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
        ~TrayIcon           ( );
        
        Win33::ContextMenu* getContextMenu( ) const;
        
        void setIcon        ( const std::wstring&       icon        );
        void setTooltip     ( const std::wstring&       tooltip     );
        void setContextMenu (       Win33::ContextMenu* contextMenu );
        
        Win33::TrayIconEvents::Click onClick;
        
    private:
        int generateID( );
        
        NOTIFYICONDATA      mNID;
        Win33::ContextMenu* mContextMenu;
    };
    
};