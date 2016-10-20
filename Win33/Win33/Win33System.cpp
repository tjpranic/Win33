#include "Win33System.h"

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