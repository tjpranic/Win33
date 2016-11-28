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
        Control            ( const Control&  other ) = default;
        Control            (       Control&& other );
        Control& operator= ( const Control&  other ) = default;
        Control& operator= (       Control&& other );
        virtual ~Control   ( )                       = default;
        
        Anchor::Type getAnchor( ) const;
        int          getX( )      const;
        int          getY( )      const;
        
        void setAnchor ( Anchor::Type anchor );
        void setX      ( int x );
        void setY      ( int y );
        
    protected:
        Control(
                  Type                type,
                  Win33::Window*      parent,
            const Point&              position,
            const Size&               size,
                  WindowStyle::Type   style,
                  ExWindowStyle::Type exStyle = ExWindowStyle::NoExWindowStyle
        );
        
    private:
        Anchor::Type mAnchor;
    };
    
};