#pragma once

#include "ContextMenu.h"
#include "Menu.h"

namespace Win33 {
    
    class Separator {
    public:
        Separator            ( ContextMenu* contextMenu );
        Separator            ( Menu*        menu        );
        Separator            ( )                         = delete;
        Separator            ( const Separator&  other ) = delete;
        Separator            (       Separator&& other ) = delete;
        Separator& operator= ( const Separator&  other ) = delete;
        Separator& operator= (       Separator&& other ) = delete;
        ~Separator           ( )                         = default;
    };
    
};