#pragma once

#include <string>
#include <vector>
#include <cassert>

#include <Windows.h>

#include "Win33Point.h"
#include "Win33Size.h"

namespace Win33 {
    
    enum class WindowStyle : DWORD {
        NoStyle          = 0,
        Border           = WS_BORDER,
        Caption          = WS_CAPTION,
        Child            = WS_CHILD,
        ChildWindow      = WS_CHILDWINDOW,
        ClipChildren     = WS_CLIPCHILDREN,
        ClipSiblings     = WS_CLIPSIBLINGS,
        Disabled         = WS_DISABLED,
        DialogFrame      = WS_DLGFRAME,
        Group            = WS_GROUP,
        HorizontalScroll = WS_HSCROLL,
        Iconic           = WS_ICONIC,
        Maximized        = WS_MAXIMIZE,
        MaximizedBox     = WS_MAXIMIZEBOX,
        Minimized        = WS_MINIMIZE,
        MinimizedBox     = WS_MAXIMIZEBOX,
        OverlappedWindow = WS_OVERLAPPEDWINDOW,
        Popup            = WS_POPUP,
        PopupWindow      = WS_POPUPWINDOW,
        SizeBox          = WS_SIZEBOX,
        SystemMenu       = WS_SYSMENU,
        Tabstop          = WS_TABSTOP,
        Thickframe       = WS_THICKFRAME,
        Tiled            = WS_TILED,
        TiledWindow      = WS_TILEDWINDOW,
        Visible          = WS_VISIBLE,
        VerticalScroll   = WS_VSCROLL
    };
    enum class ExWindowStyle : DWORD {
        NoExWindowStyle     = 0,
        DragAndDrop         = WS_EX_ACCEPTFILES,
        AppWindow           = WS_EX_APPWINDOW,
        ClientEdge          = WS_EX_CLIENTEDGE,
        Composited          = WS_EX_COMPOSITED,
        ContextHelp         = WS_EX_CONTEXTHELP,
        ControlTransparent  = WS_EX_CONTROLPARENT,
        DialogModalFrame    = WS_EX_DLGMODALFRAME,
        Layered             = WS_EX_LAYERED,
        RightToLeftLayout   = WS_EX_LAYOUTRTL,
        Left                = WS_EX_LEFT,
        LeftScrollbar       = WS_EX_LEFTSCROLLBAR,
        LeftToRightReading  = WS_EX_LTRREADING,
        MDIWindow           = WS_EX_MDICHILD,
        NoActivate          = WS_EX_NOACTIVATE,
        NoInheritLayout     = WS_EX_NOINHERITLAYOUT,
        NoParentNotify      = WS_EX_NOPARENTNOTIFY,
        NoRedirectionBitmap = WS_EX_NOREDIRECTIONBITMAP,
        ExOverlappedWindow  = WS_EX_OVERLAPPEDWINDOW,
        PaletteWindow       = WS_EX_PALETTEWINDOW,
        Right               = WS_EX_RIGHT,
        RightScrollBar      = WS_EX_RIGHTSCROLLBAR,
        RightToLeftReading  = WS_EX_RTLREADING,
        StaticEdge          = WS_EX_STATICEDGE,
        ToolWindow          = WS_EX_TOOLWINDOW,
        TopMost             = WS_EX_TOPMOST,
        Transparent         = WS_EX_TRANSPARENT,
        WindowEdge          = WS_EX_WINDOWEDGE
    };
    enum class ButtonStyle : DWORD {
        NoButtonStyle      = 0,
        ThreeState         = BS_3STATE,
        AutoThreeState     = BS_AUTO3STATE,
        AutoCheckBox       = BS_AUTOCHECKBOX,
        AutoRadioButton    = BS_AUTORADIOBUTTON,
        Bitmap             = BS_BITMAP,
        Bottom             = BS_BOTTOM,
        Center             = BS_CENTER,
        CheckBox           = BS_CHECKBOX,
        //CommandLink        = BS_COMMANDLINK,
        //DefaultCommandLink = BS_DEFCOMMANDLINK,
        DefaultPushButton  = BS_DEFPUSHBUTTON,
        //DefaultSplitButton = BS_DEFSPLITBUTTON,
        GroupBox           = BS_GROUPBOX,
        Icon               = BS_ICON,
        Flat               = BS_FLAT,
        Left               = BS_LEFT,
        LeftText           = BS_LEFTTEXT,
        Multiline          = BS_MULTILINE,
        Notify             = BS_NOTIFY,
        OwnerDraw          = BS_OWNERDRAW,
        PushButton         = BS_PUSHBUTTON,
        PushLike           = BS_PUSHLIKE,
        RadioButton        = BS_RADIOBUTTON,
        Right              = BS_RIGHT,
        RightButton        = BS_RIGHTBUTTON,
        //SplitButton        = BS_SPLITBUTTON,
        Text               = BS_TEXT,
        Top                = BS_TOP,
        Typemask           = BS_TYPEMASK,
        UserButton         = BS_USERBUTTON,
        VerticalCenter     = BS_VCENTER
    };
    enum class EditStyle : DWORD {
        NoEditControlStyle   = 0,
        AutoHorizontalScroll = ES_AUTOHSCROLL,
        AutoVerticalScroll   = ES_AUTOVSCROLL,
        Center               = ES_CENTER,
        Left                 = ES_LEFT,
        Lowercase            = ES_LOWERCASE,
        Multiline            = ES_MULTILINE,
        HideSelection        = ES_NOHIDESEL,
        Numbers              = ES_NUMBER,
        OEMConvert           = ES_OEMCONVERT,
        Password             = ES_PASSWORD,
        ReadOnly             = ES_READONLY,
        Right                = ES_RIGHT,
        Uppercase            = ES_UPPERCASE,
        WantReturn           = ES_WANTRETURN
    };
    enum class StaticStyle : DWORD {
        Bitmap           = SS_BITMAP,
        BlackFrame       = SS_BLACKFRAME,
        BlackRectangle   = SS_BLACKRECT,
        Center           = SS_CENTER,
        CenterImage      = SS_CENTERIMAGE,
        EditControl      = SS_EDITCONTROL,
        EndEllipsis      = SS_ENDELLIPSIS,
        EnhancedMetaFile = SS_ENHMETAFILE,
        EtchedFrame      = SS_ETCHEDFRAME,
        EtchedHorizontal = SS_ETCHEDHORZ,
        EtchedVertical   = SS_ETCHEDVERT,
        GrayFrame        = SS_GRAYFRAME,
        GrayRectangle    = SS_GRAYRECT,
        Icon             = SS_ICON,
        Left             = SS_LEFT,
        LeftNoWordWrap   = SS_LEFTNOWORDWRAP,
        NoPrefix         = SS_NOPREFIX,
        Notify           = SS_NOTIFY,
        OwnerDraw        = SS_OWNERDRAW,
        PathEllipsis     = SS_PATHELLIPSIS,
        RealSizeControl  = SS_REALSIZECONTROL,
        RealSizeImage    = SS_REALSIZEIMAGE,
        Right            = SS_RIGHT,
        RightJustify     = SS_RIGHTJUST,
        Simple           = SS_SIMPLE,
        Sunken           = SS_SUNKEN,
        Typemask         = SS_TYPEMASK,
        WhiteFrame       = SS_WHITEFRAME,
        WhiteRectangle   = SS_WHITERECT,
        WordEllipsis     = SS_WORDELLIPSIS
    };
    
    class Application;
    
    class Common {
    friend class Application;
    public:
        Common            ( )                      = delete;
        Common            ( const Common&  other ) = delete;
        Common            (       Common&& other );
        Common& operator= ( const Common&  other ) = delete;
        Common& operator= (       Common&& other );
        virtual ~Common   ( )                      = default;
        
        void show( );
        void hide( );
        
        const Win33::Point& getInitialPosition( ) const;
        const Win33::Size&  getInitialSize( )     const;
        const Win33::Size&  getMinimumSize( )     const;
        const Win33::Size&  getMaximumSize( )     const;
              bool          getEnabled( )         const;
              int           getX( )               const;
              int           getY( )               const;
        const Win33::Point& getPosition( )        const;
              int           getWidth( )           const;
              int           getHeight( )          const;
        const Win33::Size&  getSize( )            const;
              bool          getVisible( )         const;
        
        void setMinimumSize ( const Win33::Size&  minimumSize );
        void setMaximumSize ( const Win33::Size&  maximumSize );
        void setEnabled     (       bool          enabled     );
        void setX           (       int           x           );
        void setY           (       int           y           );
        void setPosition    ( const Win33::Point& position    );
        void setWidth       (       int           width       );
        void setHeight      (       int           height      );
        void setSize        ( const Win33::Size&  size        );
        void setVisible     (       bool          visible     );
        
    protected:
        enum class Type : int {
            Window,
            Button,
            CheckBox,
            RadioButton,
            TextBox,
            PasswordBox,
            MultilineTextBox,
            Label,
            GroupBox
        };
        
        Common(
                  Win33::Common::Type  type,
                  Win33::Common*       parent,
            const Win33::Point&        position,
            const Win33::Size&         size,
                  Win33::WindowStyle   style   = Win33::WindowStyle::OverlappedWindow,
                  Win33::ExWindowStyle exStyle = Win33::ExWindowStyle::NoExWindowStyle
        );
        
        HWND                mHandle;
        Win33::Common::Type mType;
        Win33::Common*      mParent;
        Win33::Point        mInitialPosition;
        Win33::Size         mInitialSize;
        Win33::Size         mMinimumSize;
        Win33::Size         mMaximumSize;
        Win33::Point        mPosition;
        Win33::Size         mSize;
    };
    
};