#pragma once

#include "Win33ContextMenu.h"
#include "Win33Menu.h"

namespace Win33 {
    
    class Separator {
    public:
        Separator            ( Win33::ContextMenu* contextMenu );
        Separator            ( Win33::Menu*        menu        );
        Separator            ( )                         = delete;
        Separator            ( const Separator&  other ) = delete;
        Separator            (       Separator&& other ) = delete;
        Separator& operator= ( const Separator&  other ) = delete;
        Separator& operator= (       Separator&& other ) = delete;
        ~Separator           ( )                         = default;
    };
    
};