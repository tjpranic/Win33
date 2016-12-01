#pragma once

#include <Windows.h>

namespace Win33 {
    
    class Window;
    class Control;
    class ContextMenu;
    class MenuBar;
    class Menu;
    
    namespace Interop {
        
        HWND  toHandle( Win33::Window*      window      );
        HWND  toHandle( Win33::Control*     control     );
        HMENU toHandle( Win33::ContextMenu* contextMenu );
        HMENU toHandle( Win33::MenuBar*     menuBar     );
        HMENU toHandle( Win33::Menu*        menu        );
        
    };
    
};