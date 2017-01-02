#include "Win33StringUtilities.h"

#include <locale>
#include <codecvt>

std::string Win33::String::narrow( const std::wstring& string ) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.to_bytes( string );
}
std::string Win33::String::narrow( const wchar_t* string ) {
    return Win33::String::narrow( std::wstring( string ) );
}
std::wstring Win33::String::widen( const std::string& string ) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes( string );
}
std::wstring Win33::String::widen( const char* string ) {
    return Win33::String::widen( std::string( string ) );
}

std::wstring Win33::String::nameof( const std::type_info& typeinfo ) {
    auto type  = Win33::String::widen( typeinfo.name( ) );
    auto index = type.find_last_of( L" " );
    if( index != std::wstring::npos ) {
        type = type.substr( index + 1 );
    }
    return type;
}