#pragma once

#include <unordered_map>

#include "Win33Platform.h"
#include "Win33MenuItem.h"
#include "Win33TrayIcon.h"

namespace Win33 {
    
    class Application {
    public:
        Application            ( );
        Application            ( const Application&  other ) = delete;
        Application            (       Application&& other ) = delete;
        Application& operator= ( const Application&  other ) = delete;
        Application& operator= (       Application&& other ) = delete;
        virtual ~Application   ( )                           = default;
        
        int run( );
        
        static void registerPlatform ( Win33::Platform* platform ); //*
        static void registerMenuItem ( Win33::MenuItem* menuItem ); //*
        static void registerTrayIcon ( Win33::TrayIcon* trayIcon ); //*
        
        static void unregisterPlatform ( Win33::Platform* platform ); //*
        static void unregisterMenuItem ( Win33::MenuItem* menuItem ); //*
        static void unregisterTrayIcon ( Win33::TrayIcon* trayIcon ); //*
        
    private:
        static LRESULT CALLBACK windowProcessor      ( HWND window, UINT message, WPARAM wordParameter, LPARAM longParameter );
        static BOOL    CALLBACK childWindowDestroyer ( HWND window, LPARAM longParameter );
        
        static Win33::Application*                        mInstance;
        static std::unordered_map<HWND, Win33::Platform*> mPlatforms;
        static std::unordered_map<int,  Win33::MenuItem*> mMenuItems;
        static std::unordered_map<int,  Win33::TrayIcon*> mTrayIcons;
    };
    
};