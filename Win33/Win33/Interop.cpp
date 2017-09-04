#include "Interop.h"

#include "Window.h"
#include "Control.h"
#include "ContextMenu.h"
#include "MenuBar.h"
#include "Menu.h"
#include "Font.h"
#include "Icon.h"

HWND Win33::Interop::toHandle( const Window* window ) {
    return window->mHandle;
}
HWND Win33::Interop::toHandle( const Control* control ) {
    return control->mHandle;
}
HMENU Win33::Interop::toHandle( const ContextMenu* contextMenu ) {
    return contextMenu->mHandle;
}
HMENU Win33::Interop::toHandle( const MenuBar* menuBar ) {
    return menuBar->mHandle;
}
HMENU Win33::Interop::toHandle( const Menu* menu ) {
    return menu->mHandle;
}
HFONT Win33::Interop::toHandle( const Font* font ) {
    return font->mHandle;
}
HICON Win33::Interop::toHandle( const Icon* icon ) {
    return icon->mHandle;
}