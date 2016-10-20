#pragma once

#include "Win33Menu.h"

namespace Win33 {
    
    class Window;
    
    class MenuBar {
    friend class Window;
    public:
        MenuBar( );
        ~MenuBar( ) = default;
        
        void addMenu( Menu* menu );
        
    private:
        static int generatePosition( );
        
        HMENU mHandle;
    };
    
};