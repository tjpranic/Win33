#pragma once

#include <Win33/Application.h>
#include <Win33/Window.h>
#include <Win33/Dialog.h>
#include <Win33/Button.h>
#include <Win33/PopupBox.h>

class Dialog : public Win33::Dialog<std::wstring> {
public:
    Dialog( Win33::Window* parent )
    :
    Win33::Dialog<std::wstring>( parent, Win33::Window::DefaultPosition, { 320, 240 } )
    {
        setTitle( L"Dialog" );

        mResult = L"Hello, world!";
    }
    Dialog            ( const Dialog&  other ) = delete;
    Dialog            (       Dialog&& other ) = delete;
    Dialog& operator= ( const Dialog&  other ) = delete;
    Dialog& operator= (       Dialog&& other ) = delete;
    ~Dialog           ( )                      = default;
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
            const auto result = Dialog( this ).show( );

            Win33::PopupBox::information( result, L"Dialog Result" );
        };
    }
    DialogWindow            ( const DialogWindow&  other ) = delete;
    DialogWindow            (       DialogWindow&& other ) = delete;
    DialogWindow& operator= ( const DialogWindow&  other ) = delete;
    DialogWindow& operator= (       DialogWindow&& other ) = delete;
    ~DialogWindow           ( )                            = default;

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
    DialogApplication            ( const DialogApplication&  other ) = delete;
    DialogApplication            (       DialogApplication&& other ) = delete;
    DialogApplication& operator= ( const DialogApplication&  other ) = delete;
    DialogApplication& operator= (       DialogApplication&& other ) = delete;
    ~DialogApplication           ( )                                 = default;

private:
    DialogWindow mDialogWindow;
};