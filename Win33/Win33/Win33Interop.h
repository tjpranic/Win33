#pragma once

#include <Windows.h>

namespace Win33 {
    
    class Window;
    class Control;
    class ContextMenu;
    class MenuBar;
    class Menu;
    
    namespace Interop {
        
        HWND  windowToHandle      ( Win33::Window*      window      );
        HWND  controlToHandle     ( Win33::Control*     control     );
        HMENU contextMenuToHandle ( Win33::ContextMenu* contextMenu );
        HMENU menuBarToHandle     ( Win33::MenuBar*     menuBar     );
        HMENU menuToHandle        ( Win33::Menu*        menu        );
        
    };
    
};