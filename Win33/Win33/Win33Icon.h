#pragma once

#include <string>

#include <Windows.h>

#include "Win33Size.h"

namespace Win33 {
    
    class Window;
    class TrayIcon;
    
    class Icon {
    friend class Window;
    friend class TrayIcon;
    public:
        Icon  ( );
        Icon  ( const std::wstring& filepath );
        ~Icon ( ) = default;
        
        const std::wstring& getFilepath( ) const;
        
    private:
        HICON        mHandle;
        std::wstring mFilepath;
    };
    
};