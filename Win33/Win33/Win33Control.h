#pragma once

#include "Win33Platform.h"
#include "Win33Window.h"
#include "Win33Interop.h"

namespace Win33 {
    
    namespace Anchor {
        enum Type {
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
    };
    
    class Control : public Platform {
    public:
        Control            ( )                       = delete;
        Control            ( const Control&  other ) = delete;
        Control            (       Control&& other );
        Control& operator= ( const Control&  other ) = delete;
        Control& operator= (       Control&& other );
        virtual ~Control   ( )                       = default;
        
              Win33::Window*      getParent( ) const;
              Win33::Anchor::Type getAnchor( ) const;
        const std::wstring&       getText( )   const;
              int                 getX( )      const;
              int                 getY( )      const;
        
        void setAnchor (       Win33::Anchor::Type anchor );
        void setText   ( const std::wstring&       text   );
        void setX      (       int                 x      );
        void setY      (       int                 y      );
        
        friend HWND Win33::Interop::toHandle( Win33::Control* control );
        
    protected:
        Control(
                  Win33::Platform::Type      type,
                  Win33::Window*             parent,
            const Win33::Point&              position,
            const Win33::Size&               size,
                  Win33::WindowStyle::Type   style,
                  Win33::ExWindowStyle::Type exStyle = Win33::ExWindowStyle::NoExWindowStyle
        );
        
    private:
        Win33::Anchor::Type mAnchor;
        std::wstring        mText;
    };
    
};