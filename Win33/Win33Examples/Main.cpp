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
#include <Win33/Strings.h>

//TODO add common controls
//TODO improve this vvvvvvvvvvv
int CALLBACK WinMain( HINSTANCE instance, HINSTANCE previousInstance, PSTR commandLine, int showCommand ) {
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
    catch( const Win33::Exception& exception ) {
        Win33::PopupBox::error( exception.getMessage( ) );
    }
    return 0;
}