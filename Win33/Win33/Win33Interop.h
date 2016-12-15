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
        
        HWND  toHandle( const Win33::Window*      window      );
        HWND  toHandle( const Win33::Control*     control     );
        HMENU toHandle( const Win33::ContextMenu* contextMenu );
        HMENU toHandle( const Win33::MenuBar*     menuBar     );
        HMENU toHandle( const Win33::Menu*        menu        );
        HFONT toHandle( const Win33::Font*        font        );
        HICON toHandle( const Win33::Icon*        icon        );
        
    };
    
};