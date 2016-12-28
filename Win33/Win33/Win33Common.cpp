#include "Win33Common.h"

#include "Win33Application.h"
#include "Win33System.h"
#include "Win33Utility.h"

Win33::Common::Common(
          Win33::Common::Type  type,
          Win33::Common*       parent,
    const Win33::Point&        position,
    const Win33::Size&         size,
          Win33::WindowStyle   style,
          Win33::ExWindowStyle exStyle
):
mHandle          ( nullptr ),
mType            ( type ),
mParent          ( parent ),
mInitialPosition ( position ),
mInitialSize     ( size ),
mMinimumSize     ( { 0, 0 } ),
mMaximumSize     ( Win33::System::getMonitorSize( ) ),
mPosition        ( position ),
mSize            ( size )
{
    auto identifier = L"";
    switch( mType ) {
        case Win33::Common::Type::Button:
        case Win33::Common::Type::CheckBox:
        case Win33::Common::Type::RadioButton:
        case Win33::Common::Type::GroupBox: {
            identifier = L"BUTTON";
            break;
        }
        case Win33::Common::Type::TextBox:
        case Win33::Common::Type::PasswordBox:
        case Win33::Common::Type::MultilineTextBox: {
            identifier = L"EDIT";
            break;
        }
        case Win33::Common::Type::Window: {
            identifier = L"WINDOW";
            break;
        }
        case Win33::Common::Type::Label: {
            identifier = L"STATIC";
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
    
    Win33::Application::mCommons[mHandle] = this;
}

Win33::Common::Common( Common&& other )
:
mHandle          ( other.mHandle ),
mType            ( other.mType ),
mParent          ( other.mParent ),
mInitialPosition ( std::move( other.mInitialPosition ) ),
mInitialSize     ( std::move( other.mInitialSize ) ),
mMinimumSize     ( std::move( other.mMinimumSize ) ),
mMaximumSize     ( std::move( other.mMaximumSize ) ),
mPosition        ( std::move( other.mPosition ) ),
mSize            ( std::move( other.mSize ) )
{
    other.mHandle = nullptr;
    other.mParent = nullptr;
    
    Win33::Application::mCommons[mHandle] = this;
}
Win33::Common& Win33::Common::operator=( Common&& other ) {
    mHandle          = other.mHandle;
    mType            = other.mType;
    mParent          = other.mParent;
    mInitialPosition = std::move( other.mInitialPosition );
    mInitialSize     = std::move( other.mInitialSize );
    mMinimumSize     = std::move( other.mMinimumSize );
    mMaximumSize     = std::move( other.mMaximumSize );
    mPosition        = std::move( other.mPosition );
    mSize            = std::move( other.mSize );
    other.mHandle    = nullptr;
    other.mParent    = nullptr;
    
    Win33::Application::mCommons[mHandle] = this;
    
    return *this;
}

void Win33::Common::show( ) {
    ShowWindow( mHandle, SW_SHOW );
}
void Win33::Common::hide( ) {
    ShowWindow( mHandle, SW_HIDE );
}

const Win33::Point& Win33::Common::getInitialPosition( ) const {
    return mInitialPosition;
}
const Win33::Size& Win33::Common::getInitialSize( ) const {
    return mInitialSize;
}
const Win33::Size& Win33::Common::getMinimumSize( ) const {
    return mMinimumSize;
}
const Win33::Size& Win33::Common::getMaximumSize( ) const {
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
const Win33::Point& Win33::Common::getPosition( ) const {
    *const_cast<Win33::Point*>( &mPosition ) = { getX( ), getY( ) };
    return mPosition;
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
const Win33::Size& Win33::Common::getSize( ) const {
    *const_cast<Win33::Size*>( &mSize ) = { getWidth( ), getHeight( ) };
    return mSize;
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