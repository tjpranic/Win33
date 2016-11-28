#pragma once

#include <unordered_map>

#include "Win33Platform.h"

namespace Win33 {
    
    class Platform;
    class MenuItem;
    class TrayIcon;
    class Menu;
    class ContextMenu;
    
    class Application {
    friend class Platform;
    friend class MenuItem;
    friend class TrayIcon;
    friend class Menu;
    friend class ContextMenu;
    public:
        Application            ( );
        Application            ( const Application&  other ) = delete;
        Application            (       Application&& other ) = delete;
        Application& operator= ( const Application&  other ) = delete;
        Application& operator= (       Application&& other ) = delete;
        virtual ~Application   ( )                           = default;
        
        int run( );
        
    private:
        static LRESULT CALLBACK windowProcessor( HWND window, UINT message, WPARAM wordParameter, LPARAM longParameter );
        
        static Application*                        mInstance;
        static std::unordered_map<HWND, Platform*> mPlatforms;
        static std::unordered_map<int,  MenuItem*> mMenuItems;
        static std::unordered_map<int,  TrayIcon*> mTrayIcons;
    };
    
};