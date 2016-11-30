#include "Win33Interop.h"

#include "Win33Window.h"
#include "Win33Control.h"
#include "Win33ContextMenu.h"
#include "Win33MenuBar.h"
#include "Win33Menu.h"

HWND Win33::Interop::windowToHandle( Win33::Window* window ) {
    return window->mHandle;
}
HWND Win33::Interop::controlToHandle( Win33::Control* control ) {
    return control->mHandle;
}
HMENU Win33::Interop::contextMenuToHandle( Win33::ContextMenu* contextMenu ) {
    return contextMenu->mHandle;
}
HMENU Win33::Interop::menuBarToHandle( Win33::MenuBar* menuBar ) {
    return menuBar->mHandle;
}
HMENU Win33::Interop::menuToHandle( Win33::Menu* menu ) {
    return menu->mHandle;
}