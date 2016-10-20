#include "Win33Console.h"

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include <Windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

const WORD MaxConsoleLines = 500;

Win33::Console::Console( const std::wstring& title ) {
    if( !AllocConsole( ) ) {
        throw std::runtime_error( "Unable to allocate a console." );
    }
    
    SetConsoleTitle( title.c_str( ) );
    
    CONSOLE_SCREEN_BUFFER_INFO csbi = { };
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    csbi.dwSize.Y = MaxConsoleLines;
    SetConsoleScreenBufferSize( GetStdHandle( STD_OUTPUT_HANDLE ), csbi.dwSize );
    
    //redirect output
    auto stdioHandle   = reinterpret_cast<long long>( GetStdHandle( STD_OUTPUT_HANDLE ) );
    auto consoleHandle = _open_osfhandle( stdioHandle, _O_TEXT );
    
    FILE* fp = _fdopen( consoleHandle, "w" );
    *stdout  = *fp;
    setvbuf( stdout, 0, _IONBF, 0 );
    
    //redirect input
    stdioHandle   = reinterpret_cast<long long>( GetStdHandle( STD_INPUT_HANDLE ) );
    consoleHandle = _open_osfhandle( stdioHandle, _O_TEXT );
    
    fp     = _fdopen( consoleHandle, "r" );
    *stdin = *fp;
    setvbuf( stdin, 0, _IONBF, 0 );
    
    //redirect error
    stdioHandle   = reinterpret_cast<long long>( GetStdHandle( STD_ERROR_HANDLE ) );
    consoleHandle = _open_osfhandle( stdioHandle, _O_TEXT );
    
    fp      = _fdopen( consoleHandle, "w" );
    *stderr = *fp;
    setvbuf( stderr, 0, _IONBF, 0 );
    
    //redirect cout, cin, etc...
    std::ios::sync_with_stdio( );
}
Win33::Console::~Console( ) {
    std::cout << "\nPress enter to quit...";
    std::getchar( );
    FreeConsole( );
}