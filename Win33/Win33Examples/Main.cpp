#include "MultipleWindows.h"
#include "HiddenWindow.h"
#include "MultipleTrayIcons.h"
#include "Menus.h"
#include "Dialog.h"
#include "Controls.h"
#include "TrayIcon.h"
#include "Window.h"

#include <Win33/Console.h>
#include <Win33/PopupBox.h>
#include <Win33/StringUtilities.h>

//TODO: replace SFINAE with static asserts, where applicable
//TODO? add common controls
int CALLBACK WinMain( HINSTANCE instance, HINSTANCE previousInstance, PSTR commandLine, int showCommand ) {
    //Win33::Console console;
    try {
        //return MultipleWindowsApplication( ).run( );
        //return HiddenWindowApplication( ).run( );
        //return MultipleTrayIconsApplication( ).run( );
        //return MenusApplication( ).run( );
        //return DialogApplication( ).run( );
        //return ControlsApplication( ).run( );
        //return TrayIconApplication( ).run( );
        return WindowApplication( ).run( );
    }
    catch( const std::exception& ex ) {
        Win33::PopupBox::error( Win33::String::widen( ex.what( ) ) );
    }
    return 0;
}