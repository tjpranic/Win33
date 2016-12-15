#include "Win33Interop.h"

#include "Win33Window.h"
#include "Win33Control.h"
#include "Win33ContextMenu.h"
#include "Win33MenuBar.h"
#include "Win33Menu.h"
#include "Win33Font.h"
#include "Win33Icon.h"

HWND Win33::Interop::toHandle( const Win33::Window* window ) {
    return window->mHandle;
}
HWND Win33::Interop::toHandle( const Win33::Control* control ) {
    return control->mHandle;
}
HMENU Win33::Interop::toHandle( const Win33::ContextMenu* contextMenu ) {
    return contextMenu->mHandle;
}
HMENU Win33::Interop::toHandle( const Win33::MenuBar* menuBar ) {
    return menuBar->mHandle;
}
HMENU Win33::Interop::toHandle( const Win33::Menu* menu ) {
    return menu->mHandle;
}
HFONT Win33::Interop::toHandle( const Win33::Font* font ) {
    return font->mHandle;
}
HICON Win33::Interop::toHandle( const Win33::Icon* icon ) {
    return icon->mHandle;
}