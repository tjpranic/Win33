#include "Interop.h"

#include "Window.h"
#include "Control.h"
#include "ContextMenu.h"
#include "MenuBar.h"
#include "Menu.h"
#include "Font.h"
#include "Icon.h"

HWND Win33::Interop::toHandle( Window* window ) {
    return window->mHandle;
}
HWND Win33::Interop::toHandle( Control* control ) {
    return control->mHandle;
}
HMENU Win33::Interop::toHandle( ContextMenu* contextMenu ) {
    return contextMenu->mHandle;
}
HMENU Win33::Interop::toHandle( MenuBar* menuBar ) {
    return menuBar->mHandle;
}
HMENU Win33::Interop::toHandle( Menu* menu ) {
    return menu->mHandle;
}
HFONT Win33::Interop::toHandle( Font* font ) {
    return font->mHandle;
}
HICON Win33::Interop::toHandle( Icon* icon ) {
    return icon->mHandle;
}