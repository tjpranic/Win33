#include "Win33Platform.h"

#include "Win33Application.h"
#include "Win33System.h"
#include "Win33Utility.h"

void updatePositionProperty( int x, int y, Win33::Point* property ) {
    *property = Win33::Point( x, y );
}
void updateSizeProperty( int width, int height, Win33::Size* property ) {
    *property = Win33::Size( width, height );
}


Win33::Platform::Platform(
          Win33::Platform::Type      type,
          Win33::Platform*           parent,
    const Win33::Point&              position,
    const Win33::Size&               size,
          Win33::WindowStyle::Type   style,
          Win33::ExWindowStyle::Type exStyle
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
        case Win33::Platform::Type::Button:
        case Win33::Platform::Type::CheckBox:
        case Win33::Platform::Type::RadioButton:
        case Win33::Platform::Type::GroupBox: {
            identifier = L"BUTTON";
            break;
        }
        case Win33::Platform::Type::TextBox:
        case Win33::Platform::Type::PasswordBox:
        case Win33::Platform::Type::MultilineTextBox: {
            identifier = L"EDIT";
            break;
        }
        case Win33::Platform::Type::Window: {
            identifier = L"WINDOW";
            break;
        }
        case Win33::Platform::Type::Label: {
            identifier = L"STATIC";
            break;
        }
        default: {
            throw std::runtime_error( "Unknown type." );
        }
    }
    
    mHandle = CreateWindowEx(
        exStyle,
        identifier,
        L"",
        style,
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
    
    Win33::Application::mPlatforms[mHandle] = this;
}

Win33::Platform::Platform( Platform&& other )
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
    
    Win33::Application::mPlatforms[mHandle] = this;
}
Win33::Platform& Win33::Platform::operator=( Platform&& other ) {
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
    
    Win33::Application::mPlatforms[mHandle] = this;
    
    return *this;
}

void Win33::Platform::show( ) {
    ShowWindow( mHandle, SW_SHOW );
}
void Win33::Platform::hide( ) {
    ShowWindow( mHandle, SW_HIDE );
}

const Win33::Point& Win33::Platform::getInitialPosition( ) const {
    return mInitialPosition;
}
const Win33::Size& Win33::Platform::getInitialSize( ) const {
    return mInitialSize;
}
const Win33::Size& Win33::Platform::getMinimumSize( ) const {
    return mMinimumSize;
}
const Win33::Size& Win33::Platform::getMaximumSize( ) const {
    return mMaximumSize;
}
bool Win33::Platform::getEnabled( ) const {
    return IsWindowEnabled( mHandle ) != 0;
}
int Win33::Platform::getX( ) const {
    RECT cr;
    GetClientRect( mHandle, &cr );
    MapWindowPoints( mHandle, HWND_DESKTOP, reinterpret_cast<LPPOINT>( &cr ), 2 );
    RECT wr;
    GetWindowRect( mHandle, &wr );
    POINT p = { wr.left, wr.top };
    ScreenToClient( mHandle, &p );
    return cr.left + p.x;
}
int Win33::Platform::getY( ) const {
    RECT cr;
    GetClientRect( mHandle, &cr );
    MapWindowPoints( mHandle, HWND_DESKTOP, reinterpret_cast<LPPOINT>( &cr ), 2 );
    RECT wr;
    GetWindowRect( mHandle, &wr );
    POINT p = { wr.left, wr.top };
    ScreenToClient( mHandle, &p );
    return cr.top + p.y;
}
const Win33::Point& Win33::Platform::getPosition( ) const {
    Win33::Utility::mutate( const_cast<Win33::Point*>( &mPosition ), getX( ), getY( ) );
    return mPosition;
}
int Win33::Platform::getWidth( ) const {
    RECT wr;
    GetWindowRect( mHandle, &wr );
    return wr.right - wr.left;
}
int Win33::Platform::getHeight( ) const {
    RECT wr;
    GetWindowRect( mHandle, &wr );
    return wr.bottom - wr.top;
}
const Win33::Size& Win33::Platform::getSize( ) const {
    Win33::Utility::mutate( const_cast<Win33::Size*>( &mSize ), getWidth( ), getHeight( ) );
    return mSize;
}
bool Win33::Platform::getVisible( ) const {
    return IsWindowVisible( mHandle ) != 0;
}

void Win33::Platform::setMinimumSize( const Size& size ) {
    mMinimumSize = size;
}
void Win33::Platform::setMaximumSize( const Size& size ) {
    mMaximumSize = size;
}
void Win33::Platform::setEnabled( bool enabled ) {
    EnableWindow( mHandle, enabled );
}
void Win33::Platform::setX( int x ) {
    SetWindowPos( mHandle, HWND_TOP, x, getY( ), 0, 0, SWP_NOSIZE );
}
void Win33::Platform::setY( int y ) {
    SetWindowPos( mHandle, HWND_TOP, getX( ), y, 0, 0, SWP_NOSIZE );
}
void Win33::Platform::setPosition( const Win33::Point& position ) {
    SetWindowPos( mHandle, HWND_TOP, position.getX( ), position.getY( ), 0, 0, SWP_NOSIZE );
}
void Win33::Platform::setWidth( int width ) {
    SetWindowPos( mHandle, HWND_TOP, 0, 0, width, getHeight( ), SWP_NOMOVE );
}
void Win33::Platform::setHeight( int height ) {
    SetWindowPos( mHandle, HWND_TOP, 0, 0, getWidth( ), height, SWP_NOMOVE );
}
void Win33::Platform::setSize( const Win33::Size& size ) {
    SetWindowPos( mHandle, HWND_TOP, 0, 0, size.getWidth( ), size.getHeight( ), SWP_NOMOVE );
}
void Win33::Platform::setVisible( bool visible ) {
    ShowWindow( mHandle, visible ? SW_SHOW : SW_HIDE );
}