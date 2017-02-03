#include "Win33Keys.h"

Win33::Key Win33::toKey( Win33::VirtualKeyCode keyCode ) {
    auto shiftHeld = GetKeyState( VK_SHIFT ) < 0;
    switch( keyCode ) {
        case Win33::VirtualKeyCode::Backspace: {
            return Win33::Key::Backspace;
        }
        case Win33::VirtualKeyCode::Tab: {
            return Win33::Key::Tab;
        }
        case Win33::VirtualKeyCode::Enter: {
            return Win33::Key::Enter;
        }
        case Win33::VirtualKeyCode::Pause: {
            return Win33::Key::Pause;
        }
        case Win33::VirtualKeyCode::CapsLock: {
            return Win33::Key::CapsLock;
        }
        case Win33::VirtualKeyCode::Escape: {
            return Win33::Key::Escape;
        }
        case Win33::VirtualKeyCode::Spacebar: {
            return Win33::Key::Spacebar;
        }
        case Win33::VirtualKeyCode::PageUp: {
            return Win33::Key::PageUp;
        }
        case Win33::VirtualKeyCode::PageDown: {
            return Win33::Key::PageDown;
        }
        case Win33::VirtualKeyCode::End: {
            return Win33::Key::End;
        }
        case Win33::VirtualKeyCode::LeftArrow: {
            return Win33::Key::LeftArrow;
        }
        case Win33::VirtualKeyCode::UpArrow: {
            return Win33::Key::UpArrow;
        }
        case Win33::VirtualKeyCode::RightArrow: {
            return Win33::Key::RightArrow;
        }
        case Win33::VirtualKeyCode::DownArrow: {
            return Win33::Key::DownArrow;
        }
        case Win33::VirtualKeyCode::PrintScreen: {
            return Win33::Key::PrintScreen;
        }
        case Win33::VirtualKeyCode::Insert: {
            return Win33::Key::Insert;
        }
        case Win33::VirtualKeyCode::Delete: {
            return Win33::Key::Delete;
        }
        case Win33::VirtualKeyCode::Zero: {
            return shiftHeld ? Win33::Key::CloseBracket : Win33::Key::Zero;
        }
        case Win33::VirtualKeyCode::One: {
            return shiftHeld ? Win33::Key::ExlamationPoint : Win33::Key::One;
        }
        case Win33::VirtualKeyCode::Two: {
            return shiftHeld ? Win33::Key::AtSymbol : Win33::Key::Two;
        }
        case Win33::VirtualKeyCode::Three: {
            return shiftHeld ? Win33::Key::Hash : Win33::Key::Three;
        }
        case Win33::VirtualKeyCode::Four: {
            return shiftHeld ? Win33::Key::DollarSign : Win33::Key::Four;
        }
        case Win33::VirtualKeyCode::Five: {
            return shiftHeld ? Win33::Key::Percent : Win33::Key::Five;
        }
        case Win33::VirtualKeyCode::Six: {
            return shiftHeld ? Win33::Key::Caret : Win33::Key::Six;
        }
        case Win33::VirtualKeyCode::Seven: {
            return shiftHeld ? Win33::Key::Ampersand : Win33::Key::Seven;
        }
        case Win33::VirtualKeyCode::Eight: {
            return shiftHeld ? Win33::Key::Asterisk : Win33::Key::Eight;
        }
        case Win33::VirtualKeyCode::Nine: {
            return shiftHeld ? Win33::Key::OpenBracket : Win33::Key::Nine;
        }
        case Win33::VirtualKeyCode::A: {
            return Win33::Key::A;
        }
        case Win33::VirtualKeyCode::B: {
            return Win33::Key::B;
        }
        case Win33::VirtualKeyCode::C: {
            return Win33::Key::C;
        }
        case Win33::VirtualKeyCode::D: {
            return Win33::Key::D;
        }
        case Win33::VirtualKeyCode::E: {
            return Win33::Key::E;
        }
        case Win33::VirtualKeyCode::F: {
            return Win33::Key::F;
        }
        case Win33::VirtualKeyCode::G: {
            return Win33::Key::G;
        }
        case Win33::VirtualKeyCode::H: {
            return Win33::Key::H;
        }
        case Win33::VirtualKeyCode::I: {
            return Win33::Key::I;
        }
        case Win33::VirtualKeyCode::J: {
            return Win33::Key::J;
        }
        case Win33::VirtualKeyCode::K: {
            return Win33::Key::K;
        }
        case Win33::VirtualKeyCode::L: {
            return Win33::Key::L;
        }
        case Win33::VirtualKeyCode::M: {
            return Win33::Key::M;
        }
        case Win33::VirtualKeyCode::N: {
            return Win33::Key::N;
        }
        case Win33::VirtualKeyCode::O: {
            return Win33::Key::O;
        }
        case Win33::VirtualKeyCode::P: {
            return Win33::Key::P;
        }
        case Win33::VirtualKeyCode::Q: {
            return Win33::Key::Q;
        }
        case Win33::VirtualKeyCode::R: {
            return Win33::Key::R;
        }
        case Win33::VirtualKeyCode::S: {
            return Win33::Key::S;
        }
        case Win33::VirtualKeyCode::T: {
            return Win33::Key::T;
        }
        case Win33::VirtualKeyCode::U: {
            return Win33::Key::U;
        }
        case Win33::VirtualKeyCode::V: {
            return Win33::Key::V;
        }
        case Win33::VirtualKeyCode::W: {
            return Win33::Key::W;
        }
        case Win33::VirtualKeyCode::X: {
            return Win33::Key::X;
        }
        case Win33::VirtualKeyCode::Y: {
            return Win33::Key::Y;
        }
        case Win33::VirtualKeyCode::Z: {
            return Win33::Key::Z;
        }
        case Win33::VirtualKeyCode::Control: {
            return GetKeyState( VK_RCONTROL ) < 0 ? Win33::Key::RightControl : Win33::Key::LeftControl;
        }
        case Win33::VirtualKeyCode::LeftWindows: {
            return Win33::Key::LeftWindows;
        }
        case Win33::VirtualKeyCode::RightWindows: {
            return Win33::Key::RightWindows;
        }
        case Win33::VirtualKeyCode::NumpadZero: {
            return Win33::Key::NumpadZero;
        }
        case Win33::VirtualKeyCode::NumpadOne: {
            return Win33::Key::NumpadOne;
        }
        case Win33::VirtualKeyCode::NumpadTwo: {
            return Win33::Key::NumpadTwo;
        }
        case Win33::VirtualKeyCode::NumpadThree: {
            return Win33::Key::NumpadThree;
        }
        case Win33::VirtualKeyCode::NumpadFour: {
            return Win33::Key::NumpadFour;
        }
        case Win33::VirtualKeyCode::NumpadFive: {
            return Win33::Key::NumpadFive;
        }
        case Win33::VirtualKeyCode::NumpadSix: {
            return Win33::Key::NumpadSix;
        }
        case Win33::VirtualKeyCode::NumpadSeven: {
            return Win33::Key::NumpadSeven;
        }
        case Win33::VirtualKeyCode::NumpadEight: {
            return Win33::Key::NumpadEight;
        }
        case Win33::VirtualKeyCode::NumpadNine: {
            return Win33::Key::NumpadNine;
        }
        case Win33::VirtualKeyCode::NumpadMultiply: {
            return Win33::Key::NumpadMultiply;
        }
        case Win33::VirtualKeyCode::NumpadAdd: {
            return Win33::Key::NumpadAdd;
        }
        case Win33::VirtualKeyCode::NumpadSubtract: {
            return Win33::Key::NumpadSubtract;
        }
        case Win33::VirtualKeyCode::NumpadDecimal: {
            return Win33::Key::NumpadDecimal;
        }
        case Win33::VirtualKeyCode::NumpadDivide: {
            return Win33::Key::NumpadDivide;
        }
        case Win33::VirtualKeyCode::F1: {
            return Win33::Key::F1;
        }
        case Win33::VirtualKeyCode::F2: {
            return Win33::Key::F2;
        }
        case Win33::VirtualKeyCode::F3: {
            return Win33::Key::F3;
        }
        case Win33::VirtualKeyCode::F4: {
            return Win33::Key::F4;
        }
        case Win33::VirtualKeyCode::F5: {
            return Win33::Key::F5;
        }
        case Win33::VirtualKeyCode::F6: {
            return Win33::Key::F6;
        }
        case Win33::VirtualKeyCode::F7: {
            return Win33::Key::F7;
        }
        case Win33::VirtualKeyCode::F8: {
            return Win33::Key::F8;
        }
        case Win33::VirtualKeyCode::F9: {
            return Win33::Key::F9;
        }
        case Win33::VirtualKeyCode::F10: {
            return Win33::Key::F10;
        }
        case Win33::VirtualKeyCode::F11: {
            return Win33::Key::F11;
        }
        case Win33::VirtualKeyCode::F12: {
            return Win33::Key::F12;
        }
        case Win33::VirtualKeyCode::NumLock: {
            return Win33::Key::NumLock;
        }
        case Win33::VirtualKeyCode::ScrollLock: {
            return Win33::Key::ScrollLock;
        }
        case Win33::VirtualKeyCode::Shift: {
            return GetKeyState( VK_RSHIFT ) < 0 ? Win33::Key::RightShift : Win33::Key::LeftShift;
        }
        case Win33::VirtualKeyCode::Alt: {
            return GetKeyState( VK_RMENU ) < 0 ? Win33::Key::RightAlt : Win33::Key::LeftAlt;
        }
        case Win33::VirtualKeyCode::SemiColon: {
            return shiftHeld ? Win33::Key::Colon : Win33::Key::SemiColon;
        }
        case Win33::VirtualKeyCode::Plus: {
            return shiftHeld ? Win33::Key::Plus : Win33::Key::Equals;
        }
        case Win33::VirtualKeyCode::Comma: {
            return shiftHeld ? Win33::Key::LessThan : Win33::Key::Comma;
        }
        case Win33::VirtualKeyCode::Minus: {
            return shiftHeld ? Win33::Key::Underscore : Win33::Key::Minus;
        }
        case Win33::VirtualKeyCode::Period: {
            return shiftHeld ? Win33::Key::GreaterThan : Win33::Key::Period;
        }
        case Win33::VirtualKeyCode::QuestionMark: {
            return shiftHeld ? Win33::Key::QuestionMark : Win33::Key::Slash;
        }
        case Win33::VirtualKeyCode::Tilde: {
            return shiftHeld ? Win33::Key::Tilde : Win33::Key::Tick;
        }
        case Win33::VirtualKeyCode::OpenSquareBracket: {
            return shiftHeld ? Win33::Key::OpenCurlyBrace : Win33::Key::OpenSquareBracket;
        }
        case Win33::VirtualKeyCode::Pipe: {
            return shiftHeld ? Win33::Key::BackSlash : Win33::Key::Pipe;
        }
        case Win33::VirtualKeyCode::CloseSquareBracket: {
            return shiftHeld ? Win33::Key::CloseCurlyBrace : Win33::Key::CloseSquareBracket;
        }
        case Win33::VirtualKeyCode::SingleQuote: {
            return shiftHeld ? Win33::Key::DoubleQuote : Win33::Key::SingleQuote;
        }
        default: {
            return Win33::Key::Unknown;
        }
    }
}