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
        ~TrayIcon( );
        
        ContextMenu& getContextMenu( ) const;
        
        void setContextMenu( ContextMenu* menu );
        
        void addLeftClickHandler  ( const TrayIconEvents::Handler& handler );
        void addRightClickHandler ( const TrayIconEvents::Handler& handler );
        
        void removeLeftClickHandler  ( const TrayIconEvents::Handler& handler );
        void removeRightClickHandler ( const TrayIconEvents::Handler& handler );
        
    private:
        int generateID( );
        
        TrayIconEvents::LeftClick  mLeftClick;
        TrayIconEvents::RightClick mRightClick;
        
        Window*        mParent;
        NOTIFYICONDATA mNID;
        ContextMenu*   mContextMenu;
    };
    
};