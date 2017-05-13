#include "Resources.h"

Win33::Icon* Icons::getTestIcon1( ) {
    static auto testIcon1 = Win33::Icon( L"TestIcon1.ico" );
    return &testIcon1;
}
Win33::Icon* Icons::getTestIcon2( ) {
    static auto testIcon2 = Win33::Icon( L"TestIcon2.ico" );
    return &testIcon2;
}