#include "Win33Platform.h"

#include <algorithm>

#include "Win33Application.h"
#include "Win33System.h"

Win33::Platform::Platform(
          Type                type,
          Platform*           parent,
    const Point&              position,
    const Size&               size,
          WindowStyle::Type   style,
          ExWindowStyle::Type exStyle
):
mType            ( type ),
mHandle          ( nullptr ),
mParent          ( parent ),
mChildren        ( ),
mInitialPosition ( position ),
mInitialSize     ( size ),
mMinimumSize     ( { 0, 0 } ),
mMaximumSize     ( Win33::System::getMonitorSize( ) )
{
    if( mParent ) {
        mParent->mChildren.push_back( this );
    }
    
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
    
    Application::mPlatforms[mHandle] = this;
}

Win33::Platform::Platform( Platform&& other )
:
mHandle          ( other.mHandle ),
mParent          ( other.mParent ),
mChildren        ( std::move( other.mChildren ) ),
mInitialPosition ( std::move( other.mInitialPosition ) ),
mInitialSize     ( std::move( other.mInitialSize ) ),
mMinimumSize     ( std::move( other.mMinimumSize ) ),
mMaximumSize     ( std::move( other.mMaximumSize ) )
{
    other.mHandle = nullptr;
    other.mParent = nullptr;
    
    Application::mPlatforms[mHandle] = this;
    
    for( auto& c = mChildren.begin( ); c != mChildren.end( ); ++c ) {
        ( *c )->mParent = this;
    }
}
Win33::Platform& Win33::Platform::operator=( Platform&& other ) {
    mHandle          = other.mHandle;
    mParent          = other.mParent;
    mChildren        = std::move( other.mChildren );
    mInitialPosition = std::move( other.mInitialPosition );
    mInitialSize     = std::move( other.mInitialSize );
    mMinimumSize     = std::move( other.mMinimumSize );
    mMaximumSize     = std::move( other.mMaximumSize );
    other.mHandle    = nullptr;
    other.mParent    = nullptr;
    
    Application::mPlatforms[mHandle] = this;
    
    for( auto& c = mChildren.begin( ); c != mChildren.end( ); ++c ) {
        ( *c )->mParent = this;
    }
    return *this;
}

void Win33::Platform::show( ) {
    ShowWindow( mHandle, SW_SHOW );
}
void Win33::Platform::hide( ) {
    ShowWindow( mHandle, SW_HIDE );
}

bool Win33::Platform::getEnabled( ) const {
    return IsWindowEnabled( mHandle ) != 0;
}
Win33::Platform& Win33::Platform::getParent( ) const {
    return *mParent;
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
Win33::Size Win33::Platform::getMinimumSize( ) const {
    return mMinimumSize;
}
Win33::Size Win33::Platform::getMaximumSize( ) const {
    return mMaximumSize;
}
bool Win33::Platform::getVisible( ) const {
    return IsWindowVisible( mHandle ) != 0;
}

void Win33::Platform::setEnabled( bool enabled ) {
    EnableWindow( mHandle, enabled );
}
void Win33::Platform::setParent( Platform* parent ) {
    SetParent( mHandle, parent->mHandle );
    mParent = parent;
}
void Win33::Platform::setX( int x ) {
    SetWindowPos( mHandle, HWND_TOP, x, getY( ), 0, 0, SWP_NOSIZE );
}
void Win33::Platform::setY( int y ) {
    SetWindowPos( mHandle, HWND_TOP, getX( ), y, 0, 0, SWP_NOSIZE );
}
void Win33::Platform::setWidth( int width ) {
    SetWindowPos( mHandle, HWND_TOP, 0, 0, width, getHeight( ), SWP_NOMOVE );
}
void Win33::Platform::setHeight( int height ) {
    SetWindowPos( mHandle, HWND_TOP, 0, 0, getWidth( ), height, SWP_NOMOVE );
}
void Win33::Platform::setMinimumSize( const Size& size ) {
    mMinimumSize = size;
}
void Win33::Platform::setMaximumSize( const Size& size ) {
    mMaximumSize = size;
}
void Win33::Platform::setVisible( bool visible ) {
    ShowWindow( mHandle, visible ? SW_SHOW : SW_HIDE );
}