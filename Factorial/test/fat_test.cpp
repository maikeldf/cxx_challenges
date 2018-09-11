#include <catch.hpp>
#include "Factorial.h"
using namespace cxx_challenges;

TEST_CASE( "Factorials of 1 and higher are computed (pass)", "[single-file]" ) {
    REQUIRE( Factorial().Calc(1) == 1 );
    REQUIRE( Factorial().Calc(2) == 2 );
    REQUIRE( Factorial().Calc(3) == 6 );
    REQUIRE( Factorial().Calc(10) == 3628800 );
}
