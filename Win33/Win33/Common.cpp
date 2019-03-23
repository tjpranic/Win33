#include "Common.h"

#include "Application.h"
#include "BitfieldOperators.h"
#include "Error.h"
#include "Misc.h"

namespace Win33 {

    Common::Common(
              Type          type,
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
    mMaximumSize     ( Monitor::getSize( ) ),
    mPosition        ( position ),
    mSize            ( size )
    {
        auto identifier = L"";
        switch( mType ) {
            case Type::Button:
            case Type::CheckBox:
            case Type::RadioButton:
            case Type::GroupBox: {
                identifier = L"BUTTON";
                break;
            }
            case Type::TextBox:
            case Type::PasswordBox:
            case Type::MultilineTextBox: {
                identifier = L"EDIT";
                break;
            }
            case Type::Window: {
                identifier = L"WINDOW";
                break;
            }
            case Type::Label: {
                identifier = L"STATIC";
                break;
            }
            case Type::ComboBox:
            case Type::DropDown: {
                identifier = L"COMBOBOX";
                break;
            }
            case Type::ListBox:
            case Type::MultiSelectListBox: {
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
            throw EXCEPTION( L"Unable to create window." );
        }

        Application::mCommons[mHandle] = this;
    }

    void Common::show( ) {
        ShowWindow( mHandle, SW_SHOW );
    }
    void Common::hide( ) {
        ShowWindow( mHandle, SW_HIDE );
    }

    Point Common::getInitialPosition( ) const {
        return mInitialPosition;
    }
    Size Common::getInitialSize( ) const {
        return mInitialSize;
    }
    Size Common::getMinimumSize( ) const {
        return mMinimumSize;
    }
    Size Common::getMaximumSize( ) const {
        return mMaximumSize;
    }
    bool Common::getEnabled( ) const {
        return IsWindowEnabled( mHandle ) != 0;
    }
    int Common::getX( ) const {
        RECT cr = { };
        GetClientRect( mHandle, &cr );
        MapWindowPoints( mHandle, HWND_DESKTOP, reinterpret_cast<LPPOINT>( &cr ), 2 );
        RECT wr = { };
        GetWindowRect( mHandle, &wr );
        POINT p = { wr.left, wr.top };
        ScreenToClient( mHandle, &p );
        return cr.left + p.x;
    }
    int Common::getY( ) const {
        RECT cr = { };
        GetClientRect( mHandle, &cr );
        MapWindowPoints( mHandle, HWND_DESKTOP, reinterpret_cast<LPPOINT>( &cr ), 2 );
        RECT wr = { };
        GetWindowRect( mHandle, &wr );
        POINT p = { wr.left, wr.top };
        ScreenToClient( mHandle, &p );
        return cr.top + p.y;
    }
    Point Common::getPosition( ) const {
        return { getX( ), getY( ) };
    }
    int Common::getWidth( ) const {
        RECT wr = { };
        GetWindowRect( mHandle, &wr );
        return wr.right - wr.left;
    }
    int Common::getHeight( ) const {
        RECT wr = { };
        GetWindowRect( mHandle, &wr );
        return wr.bottom - wr.top;
    }
    Size Common::getSize( ) const {
        return { getWidth( ), getHeight( ) };
    }
    bool Common::getVisible( ) const {
        return IsWindowVisible( mHandle ) != 0;
    }

    void Common::setMinimumSize( const Size& size ) {
        mMinimumSize = size;
    }
    void Common::setMaximumSize( const Size& size ) {
        mMaximumSize = size;
    }
    void Common::setEnabled( bool enabled ) {
        EnableWindow( mHandle, enabled );
    }
    void Common::setX( int x ) {
        SetWindowPos( mHandle, HWND_TOP, x, getY( ), 0, 0, SWP_NOSIZE );
    }
    void Common::setY( int y ) {
        SetWindowPos( mHandle, HWND_TOP, getX( ), y, 0, 0, SWP_NOSIZE );
    }
    void Common::setPosition( const Point& position ) {
        SetWindowPos( mHandle, HWND_TOP, position.getX( ), position.getY( ), 0, 0, SWP_NOSIZE );
    }
    void Common::setWidth( int width ) {
        SetWindowPos( mHandle, HWND_TOP, 0, 0, width, getHeight( ), SWP_NOMOVE );
    }
    void Common::setHeight( int height ) {
        SetWindowPos( mHandle, HWND_TOP, 0, 0, getWidth( ), height, SWP_NOMOVE );
    }
    void Common::setSize( const Size& size ) {
        SetWindowPos( mHandle, HWND_TOP, 0, 0, size.getWidth( ), size.getHeight( ), SWP_NOMOVE );
    }
    void Common::setVisible( bool visible ) {
        ShowWindow( mHandle, visible ? SW_SHOW : SW_HIDE );
    }

    Common::operator HWND( ) const {
        return mHandle;
    }

    Common::Type Common::getTypeFromStyle( WindowStyle style ) const {
        return Type::Window;
    }
    Common::Type Common::getTypeFromStyle( ExWindowStyle style ) const {
        return Type::Window;
    }
    Common::Type Common::getTypeFromStyle( ButtonStyle style ) const {
        if( ( style & ButtonStyle::RadioButton ) == ButtonStyle::RadioButton ) {
            return Type::RadioButton;
        }
        else if( ( style & ButtonStyle::AutoRadioButton ) == ButtonStyle::AutoRadioButton ) {
            return Type::RadioButton;
        }
        else if( ( style & ButtonStyle::CheckBox ) == ButtonStyle::CheckBox ) {
            return Type::CheckBox;
        }
        else if( ( style & ButtonStyle::AutoCheckBox ) == ButtonStyle::AutoCheckBox ) {
            return Type::CheckBox;
        }
        else {
            return Type::Button;
        }
    }
    Common::Type Common::getTypeFromStyle( EditStyle style ) const {
        if( ( style & EditStyle::Password ) == EditStyle::Password ) {
            return Type::PasswordBox;
        }
        else if( ( style & EditStyle::Multiline ) == EditStyle::Multiline ) {
            return Type::MultilineTextBox;
        }
        else {
            return Type::TextBox;
        }
    }
    Common::Type Common::getTypeFromStyle( StaticStyle style ) const {
        return Type::Label;
    }
    Common::Type Common::getTypeFromStyle( ComboBoxStyle style ) const {
        if( ( style & ComboBoxStyle::DropDown ) == ComboBoxStyle::DropDown ) {
            return Type::DropDown;
        }
        else {
            return Type::ComboBox;
        }
    }
    Common::Type Common::getTypeFromStyle( ListBoxStyle style ) const {
        if( ( style & ListBoxStyle::MultipleSelect ) == ListBoxStyle::MultipleSelect ) {
            return Type::MultiSelectListBox;
        }
        else {
            return Type::ListBox;
        }
    }

}