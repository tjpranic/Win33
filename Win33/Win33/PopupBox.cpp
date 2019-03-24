#include "PopupBox.h"

#include <Windows.h>

namespace Win33 {

    void PopupBox::exclamation( const std::wstring& message, const std::wstring& title ) {
        MessageBox( nullptr, message.c_str( ), title.c_str( ), MB_OK | MB_ICONEXCLAMATION );
    }
    void PopupBox::information( const std::wstring& message, const std::wstring& title ) {
        MessageBox( nullptr, message.c_str( ), title.c_str( ), MB_OK | MB_ICONINFORMATION );
    }
    void PopupBox::error( const std::wstring& message, const std::wstring& title ) {
        MessageBox( nullptr, message.c_str( ), title.c_str( ), MB_OK | MB_ICONERROR );
    };
    bool PopupBox::confirm( const std::wstring& message, const std::wstring& title ) {
        return MessageBox( nullptr, message.c_str( ), title.c_str( ), MB_YESNO | MB_ICONINFORMATION ) == IDOK;
    }

}