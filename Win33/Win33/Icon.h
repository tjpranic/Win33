#pragma once

#include <string>

#include "Interop.h"

namespace Win33 {
    
    class Icon {
    public:
        Icon            ( const std::wstring& icon );
        Icon            ( )                    = delete;
        Icon            ( const Icon&  other ) = default;
        Icon            (       Icon&& other ) = default;
        Icon& operator= ( const Icon&  other ) = default;
        Icon& operator= (       Icon&& other ) = default;
        ~Icon           ( )                    = default;
        
        friend HICON Interop::toHandle( const Icon* icon );
        
    private:
        HICON mHandle;
    };
    
};