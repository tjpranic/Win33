#include "Keys.h"

Win33::Key Win33::toKey( VirtualKeyCode keyCode ) {
    auto shiftHeld = GetKeyState( VK_SHIFT ) < 0;
    switch( keyCode ) {
        case VirtualKeyCode::Backspace: {
            return Key::Backspace;
        }
        case VirtualKeyCode::Tab: {
            return Key::Tab;
        }
        case VirtualKeyCode::Enter: {
            return Key::Enter;
        }
        case VirtualKeyCode::Pause: {
            return Key::Pause;
        }
        case VirtualKeyCode::CapsLock: {
            return Key::CapsLock;
        }
        case VirtualKeyCode::Escape: {
            return Key::Escape;
        }
        case VirtualKeyCode::Spacebar: {
            return Key::Spacebar;
        }
        case VirtualKeyCode::PageUp: {
            return Key::PageUp;
        }
        case VirtualKeyCode::PageDown: {
            return Key::PageDown;
        }
        case VirtualKeyCode::End: {
            return Key::End;
        }
        case VirtualKeyCode::LeftArrow: {
            return Key::LeftArrow;
        }
        case VirtualKeyCode::UpArrow: {
            return Key::UpArrow;
        }
        case VirtualKeyCode::RightArrow: {
            return Key::RightArrow;
        }
        case VirtualKeyCode::DownArrow: {
            return Key::DownArrow;
        }
        case VirtualKeyCode::PrintScreen: {
            return Key::PrintScreen;
        }
        case VirtualKeyCode::Insert: {
            return Key::Insert;
        }
        case VirtualKeyCode::Delete: {
            return Key::Delete;
        }
        case VirtualKeyCode::Zero: {
            return shiftHeld ? Key::CloseBracket : Key::Zero;
        }
        case VirtualKeyCode::One: {
            return shiftHeld ? Key::ExclamationPoint : Key::One;
        }
        case VirtualKeyCode::Two: {
            return shiftHeld ? Key::AtSymbol : Key::Two;
        }
        case VirtualKeyCode::Three: {
            return shiftHeld ? Key::Hash : Key::Three;
        }
        case VirtualKeyCode::Four: {
            return shiftHeld ? Key::DollarSign : Key::Four;
        }
        case VirtualKeyCode::Five: {
            return shiftHeld ? Key::Percent : Key::Five;
        }
        case VirtualKeyCode::Six: {
            return shiftHeld ? Key::Caret : Key::Six;
        }
        case VirtualKeyCode::Seven: {
            return shiftHeld ? Key::Ampersand : Key::Seven;
        }
        case VirtualKeyCode::Eight: {
            return shiftHeld ? Key::Asterisk : Key::Eight;
        }
        case VirtualKeyCode::Nine: {
            return shiftHeld ? Key::OpenBracket : Key::Nine;
        }
        case VirtualKeyCode::A: {
            return Key::A;
        }
        case VirtualKeyCode::B: {
            return Key::B;
        }
        case VirtualKeyCode::C: {
            return Key::C;
        }
        case VirtualKeyCode::D: {
            return Key::D;
        }
        case VirtualKeyCode::E: {
            return Key::E;
        }
        case VirtualKeyCode::F: {
            return Key::F;
        }
        case VirtualKeyCode::G: {
            return Key::G;
        }
        case VirtualKeyCode::H: {
            return Key::H;
        }
        case VirtualKeyCode::I: {
            return Key::I;
        }
        case VirtualKeyCode::J: {
            return Key::J;
        }
        case VirtualKeyCode::K: {
            return Key::K;
        }
        case VirtualKeyCode::L: {
            return Key::L;
        }
        case VirtualKeyCode::M: {
            return Key::M;
        }
        case VirtualKeyCode::N: {
            return Key::N;
        }
        case VirtualKeyCode::O: {
            return Key::O;
        }
        case VirtualKeyCode::P: {
            return Key::P;
        }
        case VirtualKeyCode::Q: {
            return Key::Q;
        }
        case VirtualKeyCode::R: {
            return Key::R;
        }
        case VirtualKeyCode::S: {
            return Key::S;
        }
        case VirtualKeyCode::T: {
            return Key::T;
        }
        case VirtualKeyCode::U: {
            return Key::U;
        }
        case VirtualKeyCode::V: {
            return Key::V;
        }
        case VirtualKeyCode::W: {
            return Key::W;
        }
        case VirtualKeyCode::X: {
            return Key::X;
        }
        case VirtualKeyCode::Y: {
            return Key::Y;
        }
        case VirtualKeyCode::Z: {
            return Key::Z;
        }
        case VirtualKeyCode::Control: {
            return GetKeyState( VK_RCONTROL ) < 0 ? Key::RightControl : Key::LeftControl;
        }
        case VirtualKeyCode::LeftWindows: {
            return Key::LeftWindows;
        }
        case VirtualKeyCode::RightWindows: {
            return Key::RightWindows;
        }
        case VirtualKeyCode::NumpadZero: {
            return Key::NumpadZero;
        }
        case VirtualKeyCode::NumpadOne: {
            return Key::NumpadOne;
        }
        case VirtualKeyCode::NumpadTwo: {
            return Key::NumpadTwo;
        }
        case VirtualKeyCode::NumpadThree: {
            return Key::NumpadThree;
        }
        case VirtualKeyCode::NumpadFour: {
            return Key::NumpadFour;
        }
        case VirtualKeyCode::NumpadFive: {
            return Key::NumpadFive;
        }
        case VirtualKeyCode::NumpadSix: {
            return Key::NumpadSix;
        }
        case VirtualKeyCode::NumpadSeven: {
            return Key::NumpadSeven;
        }
        case VirtualKeyCode::NumpadEight: {
            return Key::NumpadEight;
        }
        case VirtualKeyCode::NumpadNine: {
            return Key::NumpadNine;
        }
        case VirtualKeyCode::NumpadMultiply: {
            return Key::NumpadMultiply;
        }
        case VirtualKeyCode::NumpadAdd: {
            return Key::NumpadAdd;
        }
        case VirtualKeyCode::NumpadSubtract: {
            return Key::NumpadSubtract;
        }
        case VirtualKeyCode::NumpadDecimal: {
            return Key::NumpadDecimal;
        }
        case VirtualKeyCode::NumpadDivide: {
            return Key::NumpadDivide;
        }
        case VirtualKeyCode::F1: {
            return Key::F1;
        }
        case VirtualKeyCode::F2: {
            return Key::F2;
        }
        case VirtualKeyCode::F3: {
            return Key::F3;
        }
        case VirtualKeyCode::F4: {
            return Key::F4;
        }
        case VirtualKeyCode::F5: {
            return Key::F5;
        }
        case VirtualKeyCode::F6: {
            return Key::F6;
        }
        case VirtualKeyCode::F7: {
            return Key::F7;
        }
        case VirtualKeyCode::F8: {
            return Key::F8;
        }
        case VirtualKeyCode::F9: {
            return Key::F9;
        }
        case VirtualKeyCode::F10: {
            return Key::F10;
        }
        case VirtualKeyCode::F11: {
            return Key::F11;
        }
        case VirtualKeyCode::F12: {
            return Key::F12;
        }
        case VirtualKeyCode::NumLock: {
            return Key::NumLock;
        }
        case VirtualKeyCode::ScrollLock: {
            return Key::ScrollLock;
        }
        case VirtualKeyCode::Shift: {
            return GetKeyState( VK_RSHIFT ) < 0 ? Key::RightShift : Key::LeftShift;
        }
        case VirtualKeyCode::Alt: {
            return GetKeyState( VK_RMENU ) < 0 ? Key::RightAlt : Key::LeftAlt;
        }
        case VirtualKeyCode::SemiColon: {
            return shiftHeld ? Key::Colon : Key::SemiColon;
        }
        case VirtualKeyCode::Plus: {
            return shiftHeld ? Key::Plus : Key::Equals;
        }
        case VirtualKeyCode::Comma: {
            return shiftHeld ? Key::LessThan : Key::Comma;
        }
        case VirtualKeyCode::Minus: {
            return shiftHeld ? Key::Underscore : Key::Minus;
        }
        case VirtualKeyCode::Period: {
            return shiftHeld ? Key::GreaterThan : Key::Period;
        }
        case VirtualKeyCode::QuestionMark: {
            return shiftHeld ? Key::QuestionMark : Key::Slash;
        }
        case VirtualKeyCode::Tilde: {
            return shiftHeld ? Key::Tilde : Key::Tick;
        }
        case VirtualKeyCode::OpenSquareBracket: {
            return shiftHeld ? Key::OpenCurlyBrace : Key::OpenSquareBracket;
        }
        case VirtualKeyCode::Pipe: {
            return shiftHeld ? Key::BackSlash : Key::Pipe;
        }
        case VirtualKeyCode::CloseSquareBracket: {
            return shiftHeld ? Key::CloseCurlyBrace : Key::CloseSquareBracket;
        }
        case VirtualKeyCode::SingleQuote: {
            return shiftHeld ? Key::DoubleQuote : Key::SingleQuote;
        }
        default: {
            return Key::Unknown;
        }
    }
}