#pragma once

#include <string>

namespace Win33 {
    
    namespace Utility {
        
        //forcibly reconstunct and object over itself.
        //this is used to stealthily update a property when necessary
        template<class T, class... Args>
        void mutate( T* property, Args... args ) {
            *property = T( args... );
        }
        
        std::wstring widen( const std::string& string );
        std::wstring widen( const char*        string );
        
        template<typename... A>
        static std::wstring format( const wchar_t* string, const A&... args ) {
            wchar_t buffer[256];
            swprintf_s( buffer, 256, string, args... );
            return buffer;
        }
        
        //get the name of a type with "class"/"struct" removed
        std::wstring nameof( const std::type_info& typeinfo );
        
    };
    
};