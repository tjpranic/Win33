#include "TestApplication.h"
#include "MultipleWindowApplication.h"
#include "HiddenWindowApplication.h"
#include "MultipleTrayIconApplication.h"
#include "MenuApplication.h"
#include "Calculator.h"

#include <Win33Console.h>
#include <Win33PopupBox.h>

#include "String.h"

//TODO: write nicer tests
//TODO: finish calculator example
//TODO? add event datas to all events
int CALLBACK WinMain( HINSTANCE instance, HINSTANCE previousInstance, PSTR commandLine, int showCommand ) {
    //Win33::Console console;
    try {
        //return TestApplication( ).run( );
        //return MultipleWindowApplication( ).run( );
        //return HiddenWindowApplication( ).run( );
        //return MultipleTrayIconApplication( ).run( );
        //return MenuApplication( ).run( );
        return CalculatorApplication( ).run( );
    }
    catch( const std::exception& ex ) {
        Win33::PopupBox::error( String::widen( ex.what( ) ) );
    }
    return 0;
}