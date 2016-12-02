#include "Calculator.h"

#include <Win33PopupBox.h>
#include <Win33Utility.h>

int CALLBACK WinMain( HINSTANCE instance, HINSTANCE previousInstance, PSTR commandLine, int showCommand ) {
    try {
        return CalculatorApplication( ).run( );
    }
    catch( const std::exception& ex ) {
        Win33::PopupBox::error( Win33::Utility::widen( ex.what( ) ) );
    }
    return 0;
}