#pragma once

#include <Windows.h>

#include "Filesystem.h"

namespace Win33 {

    class Icon {
    public:
        Icon            ( const std::path& path );
        Icon            ( )                    = delete;
        Icon            ( const Icon&  other ) = default;
        Icon            (       Icon&& other ) = default;
        Icon& operator= ( const Icon&  other ) = default;
        Icon& operator= (       Icon&& other ) = default;
        ~Icon           ( )                    = default;

        operator HICON( ) const;

    private:
        HICON mHandle;
    };

}