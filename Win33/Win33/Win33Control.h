#pragma once

#include "Win33Platform.h"
#include "Win33Window.h"

namespace Win33 {
    
    namespace Anchor {
        enum Type {
            All,
            TopLeftRight,
            TopLeftBottom,
            LeftRightBottom,
            TopRightBottom,
            TopRight,
            LeftBottom,
            RightBottom
        };
    };
    namespace ScrollBar {
        enum Type {
            None,
            Vertical,
            Horizontal,
            Both
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
        
        Win33::Anchor::Type getAnchor( ) const;
        int                 getX( )      const;
        int                 getY( )      const;
        
        void setAnchor ( Win33::Anchor::Type anchor );
        void setX      ( int                 x      );
        void setY      ( int                 y      );
        
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
    };
    
};