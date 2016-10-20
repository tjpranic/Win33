#include "Win33PopupBox.h"

#include <Windows.h>

void Win33::PopupBox::exclamation( const std::wstring& message, const std::wstring& title ) {
    MessageBox( nullptr, message.c_str( ), title.c_str( ), MB_OK | MB_ICONEXCLAMATION );
}
void Win33::PopupBox::information( const std::wstring& message, const std::wstring& title ) {
    MessageBox( nullptr, message.c_str( ), title.c_str( ), MB_OK | MB_ICONINFORMATION );
}
void Win33::PopupBox::error( const std::wstring& message, const std::wstring& title ) {
    MessageBox( nullptr, message.c_str( ), title.c_str( ), MB_OK | MB_ICONERROR );
};
bool Win33::PopupBox::confirm( const std::wstring& message, const std::wstring& title ) {
    return MessageBox( nullptr, message.c_str( ), title.c_str( ), MB_YESNO | MB_ICONINFORMATION ) == IDOK;
}