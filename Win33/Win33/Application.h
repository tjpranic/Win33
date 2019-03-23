#pragma once

#include <unordered_map>

#include <Windows.h>

namespace Win33 {

    class Application {
    friend class Common;
    friend class MenuItem;
    friend class TrayIcon;
    public:
        Application            ( const Application&  other ) = delete;
        Application            (       Application&& other ) = delete;
        Application& operator= ( const Application&  other ) = delete;
        Application& operator= (       Application&& other ) = delete;
        ~Application           ( )                           = default;

        int run( );

    protected:
        Application( );

    private:
        static LRESULT CALLBACK windowProcessor( HWND windowHandle, UINT message, WPARAM wordParameter, LPARAM longParameter );

        static Application*                        mInstance;
        static HWND                                mCurrentWindow;
        static std::unordered_map<HWND, Common*>   mCommons;
        static std::unordered_map<int,  MenuItem*> mMenuItems;
        static std::unordered_map<int,  TrayIcon*> mTrayIcons;
    };

}