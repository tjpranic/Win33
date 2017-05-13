#include "System.h"

#include <Windows.h>

int Win33::System::getMonitorWidth( ) {
    return GetSystemMetrics( SM_CXSCREEN );
}
int Win33::System::getMonitorHeight( ) {
    return GetSystemMetrics( SM_CYSCREEN );
}
Win33::Size Win33::System::getMonitorSize( ) {
    return { GetSystemMetrics( SM_CXSCREEN ), GetSystemMetrics( SM_CYSCREEN ) };
}
Win33::Point Win33::System::getCursorPosition( ) {
    POINT p;
    GetCursorPos( &p );
    return { p.x, p.y };
}