#pragma once

#include "Common.h"
#include "Window.h"
#include "Font.h"

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

        Anchor       getAnchor( ) const;
        std::wstring getText( )   const;
        int          getX( )      const;
        int          getY( )      const;

        void setAnchor (       Anchor        anchor );
        void setText   ( const std::wstring& text   );
        void setX      (       int           x      );
        void setY      (       int           y      );
        void setFont   (       Font*         font   );

    protected:
        Control(
                  Common::Type  type,
                  Window*       parent,
            const Point&        position,
            const Size&         size,
                  WindowStyle   style,
                  ExWindowStyle exStyle = ExWindowStyle::None
        );

        Anchor mAnchor;
    };

}