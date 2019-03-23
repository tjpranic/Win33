#include "Error.h"

namespace Win33 {

    namespace Error {

        void Error::abortWithMessage( const std::wstring& message ) {
            PopupBox::error( message );
            std::terminate( );
        }

    };

    Exception::Exception( const std::wstring& message )
    :
    mMessage( message )
    { }

    const std::wstring& Exception::getMessage( ) const {
        return mMessage;
    }

};