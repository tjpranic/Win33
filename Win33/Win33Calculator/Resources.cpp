#include "Resources.h"

Win33::Font* Fonts::getSegoeUI18( ) {
    static auto segoeUI18 = Win33::Font( L"SegoeUI", 18 );
    return &segoeUI18;
}
Win33::Font* Fonts::getSegoeUI24Bold( ) {
    static auto segoeUI24Bold = Win33::Font( L"SegoeUI", 24, Win33::FontDecoration::Bold );
    return &segoeUI24Bold;
}