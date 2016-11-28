#pragma once

#include <string>

namespace Win33 {
    
    class Console {
    public:
        Console            ( const std::wstring& title = L"Console" );
        Console            ( const Console&  other ) = delete;
        Console            (       Console&& other ) = delete;
        Console& operator= ( const Console&  other ) = delete;
        Console& operator= (       Console&& other ) = delete;
         ~Console          ( );
    };
    
};