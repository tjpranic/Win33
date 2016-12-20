#include "Win33Console.h"

#include <iostream>

#include <Windows.h>
#include <stdio.h>

FILE* stream;

Win33::Console::Console( const std::wstring& title ) {
    if( !AllocConsole( ) ) {
        throw std::runtime_error( "Unable to allocate a console." );
    }
    
    SetConsoleTitle( title.c_str( ) );
    
    //redirect inputs to console
    freopen_s( &stream, "CONIN$",  "r", stdin  );
    freopen_s( &stream, "CONOUT$", "w", stdout );
    freopen_s( &stream, "CONOUT$", "w", stderr );
    
    std::wcout.clear( );
    std::cout.clear( );
    std::wcerr.clear( );
    std::cerr.clear( );
    std::wcin.clear( );
    std::cin.clear( );
}
Win33::Console::~Console( ) {
    std::cout << "\nPress enter to quit...";
    std::getchar( );
    FreeConsole( );
}