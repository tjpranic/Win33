#pragma once

#include <unordered_map>

#include <Windows.h>

namespace Win33 {

    //TODO: add common controls
    class Application {
    friend class Window;
    friend class MenuItem;
    friend class TrayIcon;
    public:
        Application            ( const Application&  other ) = delete;
        Application            (       Application&& other ) = delete;
        Application& operator= ( const Application&  other ) = delete;
        Application& operator= (       Application&& other ) = delete;
        ~Application           ( )                           = default;

        static Application& get( );

        int run( );

    protected:
        Application( );

    private:
        static LRESULT CALLBACK windowProcessor( HWND windowHandle, UINT message, WPARAM wordParameter, LPARAM longParameter );

        static Application* mInstance;

        HWND                                mCurrentWindow;
        std::unordered_map<HWND, Window*>   mWindows;
        std::unordered_map<int,  MenuItem*> mMenuItems;
        std::unordered_map<int,  TrayIcon*> mTrayIcons;
    };

}