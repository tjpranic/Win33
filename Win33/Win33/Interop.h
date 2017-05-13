#pragma once

#include <Windows.h>

namespace Win33 {
    
    class Window;
    class Control;
    class ContextMenu;
    class MenuBar;
    class Menu;
    class Font;
    class Icon;
    
    namespace Interop {
        
        HWND  toHandle( Window*      window      );
        HWND  toHandle( Control*     control     );
        HMENU toHandle( ContextMenu* contextMenu );
        HMENU toHandle( MenuBar*     menuBar     );
        HMENU toHandle( Menu*        menu        );
        HFONT toHandle( Font*        font        );
        HICON toHandle( Icon*        icon        );
        
    };
    
};