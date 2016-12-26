#include "MultipleWindows.h"
#include "HiddenWindow.h"
#include "MultipleTrayIcons.h"
#include "Menus.h"
#include "Dialog.h"
#include "Controls.h"

#include <Win33Console.h>
#include <Win33PopupBox.h>
#include <Win33Utility.h>

//TODO: finish calculator
int CALLBACK WinMain( HINSTANCE instance, HINSTANCE previousInstance, PSTR commandLine, int showCommand ) {
    //Win33::Console console;
    try {
        //return MultipleWindowsApplication( ).run( );
        //return HiddenWindowApplication( ).run( );
        //return MultipleTrayIconsApplication( ).run( );
        //return MenusApplication( ).run( );
        //return DialogApplication( ).run( );
        return ControlsApplication( ).run( );
    }
    catch( const std::exception& ex ) {
        Win33::PopupBox::error( Win33::Utility::widen( ex.what( ) ) );
    }
    return 0;
}