#pragma once

#include <string>

namespace Win33 {
    
    namespace PopupBox {
        
        void exclamation ( const std::wstring& message, const std::wstring& title = L"" );
        void information ( const std::wstring& message, const std::wstring& title = L"Information" );
        void error       ( const std::wstring& message, const std::wstring& title = L"Error" );
        bool confirm     ( const std::wstring& message, const std::wstring& title = L"" );
        
    };
    
};