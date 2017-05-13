#include "Common.h"

#include "Application.h"
#include "System.h"
#include "BitfieldOperators.h"

Win33::Common::Common(
          Common::Type  type,
          Common*       parent,
    const Point&        position,
    const Size&         size,
          WindowStyle   style,
          ExWindowStyle exStyle
):
mHandle          ( nullptr ),
mType            ( type ),
mParent          ( parent ),
mInitialPosition ( position ),
mInitialSize     ( size ),
mMinimumSize     ( { 0, 0 } ),
mMaximumSize     ( System::getMonitorSize( ) ),
mPosition        ( position ),
mSize            ( size )
{
    auto identifier = L"";
    switch( mType ) {
        case Common::Type::Button:
        case Common::Type::CheckBox:
        case Common::Type::RadioButton:
        case Common::Type::GroupBox: {
            identifier = L"BUTTON";
            break;
        }
        case Common::Type::TextBox:
        case Common::Type::PasswordBox:
        case Common::Type::MultilineTextBox: {
            identifier = L"EDIT";
            break;
        }
        case Common::Type::Window: {
            identifier = L"WINDOW";
            break;
        }
        case Common::Type::Label: {
            identifier = L"STATIC";
            break;
        }
        case Common::Type::ComboBox:
        case Common::Type::DropDown: {
            identifier = L"COMBOBOX";
            break;
        }
        case Common::Type::ListBox:
        case Common::Type::MultiSelectListBox: {
            identifier = L"LISTBOX";
            break;
        }
        default: {
            throw std::runtime_error( "Unknown type." );
        }
    }
    
    mHandle = CreateWindowEx(
        static_cast<DWORD>( exStyle ),
        identifier,
        L"",
        static_cast<DWORD>( style ),
        position.getX( ),
        position.getY( ),
        size.getWidth( ),
        size.getHeight( ),
        parent ? parent->mHandle : nullptr,
        nullptr,
        GetModuleHandle( nullptr ),
        nullptr
    );
    
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create window." );
    }
    
    Application::mCommons[mHandle] = this;
}

void Win33::Common::show( ) {
    ShowWindow( mHandle, SW_SHOW );
}
void Win33::Common::hide( ) {
    ShowWindow( mHandle, SW_HIDE );
}

Win33::Point Win33::Common::getInitialPosition( ) const {
    return mInitialPosition;
}
Win33::Size Win33::Common::getInitialSize( ) const {
    return mInitialSize;
}
Win33::Size Win33::Common::getMinimumSize( ) const {
    return mMinimumSize;
}
Win33::Size Win33::Common::getMaximumSize( ) const {
    return mMaximumSize;
}
bool Win33::Common::getEnabled( ) const {
    return IsWindowEnabled( mHandle ) != 0;
}
int Win33::Common::getX( ) const {
    RECT cr;
    GetClientRect( mHandle, &cr );
    MapWindowPoints( mHandle, HWND_DESKTOP, reinterpret_cast<LPPOINT>( &cr ), 2 );
    RECT wr;
    GetWindowRect( mHandle, &wr );
    POINT p = { wr.left, wr.top };
    ScreenToClient( mHandle, &p );
    return cr.left + p.x;
}
int Win33::Common::getY( ) const {
    RECT cr;
    GetClientRect( mHandle, &cr );
    MapWindowPoints( mHandle, HWND_DESKTOP, reinterpret_cast<LPPOINT>( &cr ), 2 );
    RECT wr;
    GetWindowRect( mHandle, &wr );
    POINT p = { wr.left, wr.top };
    ScreenToClient( mHandle, &p );
    return cr.top + p.y;
}
Win33::Point Win33::Common::getPosition( ) const {
    return { getX( ), getY( ) };
}
int Win33::Common::getWidth( ) const {
    RECT wr;
    GetWindowRect( mHandle, &wr );
    return wr.right - wr.left;
}
int Win33::Common::getHeight( ) const {
    RECT wr;
    GetWindowRect( mHandle, &wr );
    return wr.bottom - wr.top;
}
Win33::Size Win33::Common::getSize( ) const {
    return { getWidth( ), getHeight( ) };
}
bool Win33::Common::getVisible( ) const {
    return IsWindowVisible( mHandle ) != 0;
}

void Win33::Common::setMinimumSize( const Size& size ) {
    mMinimumSize = size;
}
void Win33::Common::setMaximumSize( const Size& size ) {
    mMaximumSize = size;
}
void Win33::Common::setEnabled( bool enabled ) {
    EnableWindow( mHandle, enabled );
}
void Win33::Common::setX( int x ) {
    SetWindowPos( mHandle, HWND_TOP, x, getY( ), 0, 0, SWP_NOSIZE );
}
void Win33::Common::setY( int y ) {
    SetWindowPos( mHandle, HWND_TOP, getX( ), y, 0, 0, SWP_NOSIZE );
}
void Win33::Common::setPosition( const Win33::Point& position ) {
    SetWindowPos( mHandle, HWND_TOP, position.getX( ), position.getY( ), 0, 0, SWP_NOSIZE );
}
void Win33::Common::setWidth( int width ) {
    SetWindowPos( mHandle, HWND_TOP, 0, 0, width, getHeight( ), SWP_NOMOVE );
}
void Win33::Common::setHeight( int height ) {
    SetWindowPos( mHandle, HWND_TOP, 0, 0, getWidth( ), height, SWP_NOMOVE );
}
void Win33::Common::setSize( const Win33::Size& size ) {
    SetWindowPos( mHandle, HWND_TOP, 0, 0, size.getWidth( ), size.getHeight( ), SWP_NOMOVE );
}
void Win33::Common::setVisible( bool visible ) {
    ShowWindow( mHandle, visible ? SW_SHOW : SW_HIDE );
}

Win33::Common::Type Win33::Common::getTypeFromStyle( Win33::WindowStyle style ) const {
    return Common::Type::Window;
}
Win33::Common::Type Win33::Common::getTypeFromStyle( Win33::ExWindowStyle style ) const {
    return Common::Type::Window;
}
Win33::Common::Type Win33::Common::getTypeFromStyle( Win33::ButtonStyle style ) const {
    if( ( style & ButtonStyle::RadioButton ) == ButtonStyle::RadioButton ) {
        return Common::Type::RadioButton;
    }
    else if( ( style & ButtonStyle::AutoRadioButton ) == ButtonStyle::AutoRadioButton ) {
        return Common::Type::RadioButton;
    }
    else if( ( style & ButtonStyle::CheckBox ) == ButtonStyle::CheckBox ) {
        return Common::Type::CheckBox;
    }
    else if( ( style & ButtonStyle::AutoCheckBox ) == ButtonStyle::AutoCheckBox ) {
        return Common::Type::CheckBox;
    }
    else {
        return Common::Type::Button;
    }
}
Win33::Common::Type Win33::Common::getTypeFromStyle( Win33::EditStyle style ) const {
    if( ( style & EditStyle::Password ) == EditStyle::Password ) {
        return Common::Type::PasswordBox;
    }
    else if( ( style & EditStyle::Multiline ) == EditStyle::Multiline ) {
        return Common::Type::MultilineTextBox;
    }
    else {
        return Common::Type::TextBox;
    }
}
Win33::Common::Type Win33::Common::getTypeFromStyle( Win33::StaticStyle style ) const {
    return Common::Type::Label;
}
Win33::Common::Type Win33::Common::getTypeFromStyle( Win33::ComboBoxStyle style ) const {
    if( ( style & ComboBoxStyle::DropDown ) == ComboBoxStyle::DropDown ) {
        return Common::Type::DropDown;
    }
    else {
        return Common::Type::ComboBox;
    }
}
Win33::Common::Type Win33::Common::getTypeFromStyle( Win33::ListBoxStyle style ) const {
    if( ( style & ListBoxStyle::MultipleSelect ) == ListBoxStyle::MultipleSelect ) {
        return Common::Type::MultiSelectListBox;
    }
    else {
        return Common::Type::ListBox;
    }
}