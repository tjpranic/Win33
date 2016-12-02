#pragma once

#include <Win33Application.h>
#include <Win33Window.h>
#include <Win33Dialog.h>
#include <Win33Button.h>
#include <Win33PopupBox.h>

class Dialog : public Win33::Dialog<std::wstring> {
public:
    Dialog( Win33::Window* parent )
    :
    Win33::Dialog<std::wstring>( parent, Win33::Window::DefaultPosition, { 320, 240 } )
    {
        setTitle( L"Dialog" );
        
        mResult = L"Hello, world!";
    }
    ~Dialog( ) = default;
};

class DialogWindow : public Win33::Window {
public:
    DialogWindow( )
    :
    Win33::Window ( Win33::Window::DefaultPosition, { 640, 480 } ),
    mShowDialog   ( this, { 515, 407 }, { 100, 25 }, L"Show Dialog" )
    {
        setTitle( L"DialogWindow" );
        
        mShowDialog.setAnchor( Win33::Anchor::RightBottom );
        mShowDialog.onClick += [&]( ) {
            auto result = Dialog( this ).show( );
            
            Win33::PopupBox::information( result, L"Dialog Result" );
        };
    }
    ~DialogWindow( ) = default;
    
private:
    Win33::Button mShowDialog;
};

class DialogApplication : public Win33::Application {
public:
    DialogApplication( )
    :
    Win33::Application ( ),
    mDialogWindow      ( )
    {
        mDialogWindow.show( );
    }
    ~DialogApplication( ) = default;
    
private:
    DialogWindow mDialogWindow;
};