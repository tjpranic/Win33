#pragma once

#include <string>

namespace Win33 {
    
    class Console {
    public:
        Console  ( const std::wstring& title = L"Console" );
        ~Console ( );
        
    private:
        Console            ( const Console&  ) = delete;
        Console            ( const Console&& ) = delete;
        Console& operator= ( const Console&  ) = delete;
        Console& operator= ( const Console&& ) = delete;
    };
    
};