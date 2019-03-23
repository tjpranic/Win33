#include "Console.h"

#include <iostream>

#include <stdio.h>
#include <Windows.h>

namespace Win33 {

    Console::Console( const std::wstring& title ) {
        if( !AllocConsole( ) ) {
            throw std::runtime_error( "Unable to allocate a console." );
        }

        SetConsoleTitle( title.c_str( ) );

        FILE* stream = nullptr;

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
    Console::~Console( ) {
        std::cout << "\nPress enter to quit...";
        std::getchar( );
        FreeConsole( );
    }

    void Console::flush( ) {
        std::cin.clear   ( );
        std::cin.ignore  ( ( std::numeric_limits<std::streamsize>::max )( ), '\n' );
        std::wcin.clear  ( );
        std::wcin.ignore ( ( std::numeric_limits<std::streamsize>::max )( ), L'\n' );
    }
    void Console::clear( ) {
        std::system( "cls" );
    }
    void Console::stall( ) {
        std::wcout << L"\nPress enter to quit...";
        flush( );
    }

    void Console::setTitle( const std::wstring& title ) {
        SetConsoleTitle( title.c_str( ) );
    }

    std::wstring Console::getTitle( ) {
        static wchar_t buffer[256];
        GetConsoleTitle( buffer, 256 );
        return std::wstring( buffer );
    }

}