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
        
        HWND  toHandle( const Window*      window      );
        HWND  toHandle( const Control*     control     );
        HMENU toHandle( const ContextMenu* contextMenu );
        HMENU toHandle( const MenuBar*     menuBar     );
        HMENU toHandle( const Menu*        menu        );
        HFONT toHandle( const Font*        font        );
        HICON toHandle( const Icon*        icon        );
        
    };
    
};