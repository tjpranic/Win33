#pragma once

#include <string>
#include <typeinfo>

class String {
public:
    static std::wstring widen( const std::string& string );
    static std::wstring widen( const char* string );
    
    template<typename... A>
    static std::wstring format( const wchar_t* string, const A&... args ) {
        wchar_t buffer[256];
        swprintf_s( buffer, 256, string, args... );
        return buffer;
    }
    
    //get the name of a type with "class"/"struct" removed
    static std::wstring nameof( const std::type_info& typeinfo );
    
private:
    String            ( )          = delete;
    String            ( String&  ) = delete;
    String            ( String&& ) = delete;
    String& operator= ( String&  ) = delete;
    String& operator= ( String&& ) = delete;
};