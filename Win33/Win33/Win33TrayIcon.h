#pragma once

#include "Win33Window.h"
#include "Win33ContextMenu.h"
#include "Win33TrayIconEvents.h"

#define WM_TRAYICON ( WM_USER + 0x02 )

namespace Win33 {
    
    class TrayIcon {
    public:
        TrayIcon(
                  Win33::Window* parent,
            const std::wstring&  icon,
            const std::wstring&  tooltip
        );
        TrayIcon            ( const TrayIcon&  other ) = delete;
        TrayIcon            (       TrayIcon&& other );
        TrayIcon& operator= ( const TrayIcon&  other ) = delete;
        TrayIcon& operator= (       TrayIcon&& other );
        ~TrayIcon           ( );
        
              int                 getID( )          const;
              Win33::Window*      getParent( )      const;
              Win33::ContextMenu* getContextMenu( ) const;
        const std::wstring&       getIcon( )        const;
        
        void setIcon        ( const std::wstring&       icon        );
        void setContextMenu (       Win33::ContextMenu* contextMenu );
        
        Win33::TrayIconEvents::Click click;
        
    private:
        int generateID( );
        
        Win33::Window*      mParent;
        Win33::ContextMenu* mContextMenu;
        std::wstring        mIcon;
        NOTIFYICONDATA      mNID;
    };
    
};