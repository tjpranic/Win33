#include "Win33MenuBar.h"

#include "Win33Window.h"

Win33::MenuBar::MenuBar( Win33::Window* window )
:
mLastPosition ( 0 ),
mHandle       ( CreateMenu( ) ),
mWindow       ( window ),
mMenus        ( )
{
    assert( window != nullptr );
    
    if( !mHandle ) {
        throw std::runtime_error( "Unable to create menu bar." );
    }
    
    SetMenu( Win33::Interop::toHandle( mWindow ), mHandle );
    
    window->onDestroy += [&]( Win33::WindowEvents::DestroyData& data ) {
        mMenus.clear( );
    };
}

Win33::Menu& Win33::MenuBar::appendMenu( const std::wstring& text ) {
    mMenus.push_back( std::move( Win33::Menu( this, mLastPosition, text ) ) );
    auto& menu = mMenus.back( );
    
    AppendMenu( mHandle, MF_POPUP, reinterpret_cast<UINT_PTR>( Win33::Interop::toHandle( &menu ) ), text.c_str( ) );
    
    DrawMenuBar( Win33::Interop::toHandle( mWindow ) );
    
    mLastPosition++;
    return menu;
}