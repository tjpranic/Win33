#include "String.h"

#include <locale>
#include <codecvt>

std::wstring String::widen( const std::string& string ) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes( string );
}
std::wstring String::widen( const char* string ) {
    return widen( std::string( string ) );
}

std::wstring String::nameof( const std::type_info& typeinfo ) {
    auto type  = std::wstring( String::widen( typeinfo.name( ) ) );
    auto index = type.find_last_of( L" " );
    if( index != std::wstring::npos ) {
        type = type.substr( index + 1 );
    }
    return type;
}