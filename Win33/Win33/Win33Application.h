#pragma once

#include <unordered_map>

#include <Windows.h>

namespace Win33 {
    
    class Common;
    class MenuItem;
    class TrayIcon;
    
    class Application {
    friend class Common;
    friend class MenuItem;
    friend class TrayIcon;
    public:
        Application            ( );
        Application            ( const Application&  other ) = delete;
        Application            (       Application&& other ) = delete;
        Application& operator= ( const Application&  other ) = delete;
        Application& operator= (       Application&& other ) = delete;
        virtual ~Application   ( )                           = default;
        
        int run( );
        
    private:
        static LRESULT CALLBACK windowProcessor   ( HWND window, UINT message, WPARAM wordParameter, LPARAM longParameter );
        static BOOL    CALLBACK childWindowEraser ( HWND window, LPARAM longParameter );
        
        static Win33::Application*                        mInstance;
        static std::unordered_map<HWND, Win33::Common*>   mCommons;
        static std::unordered_map<int,  Win33::MenuItem*> mMenuItems;
        static std::unordered_map<int,  Win33::TrayIcon*> mTrayIcons;
    };
    
};