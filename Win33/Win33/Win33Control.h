#pragma once

#include "Win33Common.h"
#include "Win33Window.h"
#include "Win33Interop.h"
#include "Win33Font.h"

namespace Win33 {
    
    enum class Anchor : int {
        All,
        TopLeft,
        TopLeftRight,
        TopLeftBottom,
        LeftRightBottom,
        TopRightBottom,
        TopRight,
        LeftBottom,
        RightBottom
    };
    
    class Control : public Common {
    public:
        Control            ( )                       = delete;
        Control            ( const Control&  other ) = delete;
        Control            (       Control&& other ) = delete;
        Control& operator= ( const Control&  other ) = delete;
        Control& operator= (       Control&& other ) = delete;
        virtual ~Control   ( )                       = default;
        
        Win33::Anchor getAnchor( ) const;
        std::wstring  getText( )   const;
        int           getX( )      const;
        int           getY( )      const;
        
        void setAnchor (       Win33::Anchor anchor );
        void setText   ( const std::wstring& text   );
        void setX      (       int           x      );
        void setY      (       int           y      );
        void setFont   ( const Win33::Font*  font   );
        
        friend HWND Win33::Interop::toHandle( const Win33::Control* control );
        
    protected:
        Control(
                  Win33::Common::Type  type,
                  Win33::Window*       parent,
            const Win33::Point&        position,
            const Win33::Size&         size,
                  Win33::WindowStyle   style,
                  Win33::ExWindowStyle exStyle = Win33::ExWindowStyle::None
        );
        
        Win33::Anchor mAnchor;
    };
    
};