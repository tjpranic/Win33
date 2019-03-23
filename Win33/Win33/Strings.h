#pragma once

#include <string>

namespace Win33::String {

    std::string  narrow ( const std::wstring& string );
    std::string  narrow ( const wchar_t*      string );
    std::wstring widen  ( const std::string&  string );
    std::wstring widen  ( const char*         string );

    template<typename... A>
    std::string format( const char* string, const A&... args ) {
        char buffer[256];
        sprintf_s( buffer, 256, string, args... );
        return buffer;
    }
    template<typename... A>
    static std::wstring format( const wchar_t* string, const A&... args ) {
        wchar_t buffer[256];
        swprintf_s( buffer, 256, string, args... );
        return buffer;
    }

    //get the name of a type with "class"/"struct" removed
    std::wstring nameof( const std::type_info& typeinfo );

}