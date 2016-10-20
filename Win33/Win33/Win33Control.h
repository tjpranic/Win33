#pragma once

#include "Win33Platform.h"

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
    
    class Button;
    class CheckBox;
    class RadioButton;
    class TextBox;
    class PasswordBox;
    class MultilineTextBox;
    class Label;
    class GroupBox;
    
    class Control : public Platform {
    friend class Button;
    friend class CheckBox;
    friend class RadioButton;
    friend class TextBox;
    friend class PasswordBox;
    friend class MultilineTextBox;
    friend class Label;
    friend class GroupBox;
    public:
        Control         ( ) = delete;
        virtual ~Control( ) = default;
        
        Anchor::Type getAnchor( ) const;
        int          getX( )      const;
        int          getY( )      const;
        
        void setAnchor ( Anchor::Type anchor );
        void setX      ( int x );
        void setY      ( int y );
        
    protected:
        Control            ( Control&  other ) = default;
        Control            ( Control&& other );
        Control& operator= ( Control&  other ) = default;
        Control& operator= ( Control&& other );
        
        using Platform::mHandle;
        
    private:
        Control(
                  Type                type,
                  Win33::Window*      parent,
            const Point&              position,
            const Size&               size,
                  WindowStyle::Type   style,
                  ExWindowStyle::Type exStyle = ExWindowStyle::NoExWindowStyle
        );
        
        Anchor::Type mAnchor;
    };
    
};