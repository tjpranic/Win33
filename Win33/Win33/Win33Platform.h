#pragma once

#include <string>
#include <vector>

#include <Windows.h>

#include "Win33Point.h"
#include "Win33Size.h"

namespace Win33 {
    
    namespace WindowStyle {
        enum Type {
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
    };
    namespace ExWindowStyle {
        enum Type {
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
    };
    namespace ButtonStyle {
        enum Type {
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
    };
    namespace EditStyle {
        enum Type {
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
    };
    namespace StaticStyle {
        enum Type {
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
    };
    
    class Application;
    class Control;
    class ContextMenu;
    class TrayIcon;
    
    class Platform {
    friend class Application;
    friend class Control;
    friend class ContextMenu;
    friend class TrayIcon;
    public:
        enum Type {
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
        
        Platform            ( )                        = delete;
        Platform            ( const Platform&  other ) = delete;
        Platform            (       Platform&& other );
        Platform& operator= ( const Platform&  other ) = delete;
        Platform& operator= (       Platform&& other );
        virtual ~Platform   ( )                        = default;
        
        void show( );
        void hide( );
        
        bool      getEnabled( )     const;
        Platform& getParent( )      const;
        int       getX( )           const;
        int       getY( )           const;
        int       getWidth( )       const;
        int       getHeight( )      const;
        Point     getPosition( )    const;
        Size      getSize( )        const;
        Size      getMinimumSize( ) const;
        Size      getMaximumSize( ) const;
        bool      getVisible( )     const;
        
        void setEnabled     (       bool      enabled     );
        void setParent      (       Platform* parent      );
        void setX           (       int       x           );
        void setY           (       int       y           );
        void setWidth       (       int       width       );
        void setHeight      (       int       height      );
        void setPosition    ( const Point&    position    );
        void setSize        ( const Size&     size        );
        void setMinimumSize ( const Size&     minimumSize );
        void setMaximumSize ( const Size&     maximumSize );
        void setVisible     (       bool      visible     );
        
    protected:
        Platform(
                  Type                type,
                  Platform*           parent,
            const Point&              position,
            const Size&               size,
                  WindowStyle::Type   style   = WindowStyle::OverlappedWindow,
                  ExWindowStyle::Type exStyle = ExWindowStyle::NoExWindowStyle
        );
        
        Type                   mType;
        HWND                   mHandle;
        Platform*              mParent;
        std::vector<Platform*> mChildren;
        Point                  mInitialPosition;
        Size                   mInitialSize;
        Size                   mMinimumSize;
        Size                   mMaximumSize;
    };
    
};