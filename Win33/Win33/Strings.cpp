#include "Strings.h"

#include <locale>
#include <codecvt>

namespace Win33::String {

    std::string narrow( const std::wstring& string ) {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.to_bytes( string );
    }
    std::string narrow( const wchar_t* string ) {
        return String::narrow( std::wstring( string ) );
    }
    std::wstring widen( const std::string& string ) {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.from_bytes( string );
    }
    std::wstring widen( const char* string ) {
        return String::widen( std::string( string ) );
    }

    std::wstring nameof( const std::type_info& typeinfo ) {
              auto type  = String::widen( typeinfo.name( ) );
        const auto index = type.find_last_of( L" " );
        if( index != std::wstring::npos ) {
            type = type.substr( index + 1 );
        }
        return type;
    }

}