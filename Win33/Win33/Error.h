#pragma once

#include "Debug.h"
#include "PopupBox.h"
#include "Strings.h"

namespace Win33 {

    namespace Error {

        void abortWithMessage( const std::wstring& message );

    };

    class Exception {
    public:
        Exception            ( const std::wstring& message );
        Exception            ( )                         = delete;
        Exception            ( const Exception&  other ) = default;
        Exception            (       Exception&& other ) = default;
        Exception& operator= ( const Exception&  other ) = default;
        Exception& operator= (       Exception&& other ) = default;
        ~Exception           ( )                         = default;

        const std::wstring& getMessage( ) const;

    private:
        std::wstring mMessage;
    };

}

#if defined( _DEBUG )
#define ASSERT_TRUE( expression, message )  if(  !( expression ) ) { ::Win33::Error::abortWithMessage( ::Win33::String::format( L"\"%s\" in %s at line %i.", message, THIS_FILE, THIS_LINE ) ); }
#define ASSERT_FALSE( expression, message ) if( !!( expression ) ) { ::Win33::Error::abortWithMessage( ::Win33::String::format( L"\"%s\" in %s at line %i.", message, THIS_FILE, THIS_LINE ) ); }
#else
#define ASSERT_TRUE( expression, message )
#define ASSERT_FALSE( expression, message )
#endif

#define EXCEPTION( message ) ( ::Win33::Exception( ::Win33::String::format( L"\"%s\" in %s at line %i.", message, THIS_FILE, THIS_LINE ) ) )