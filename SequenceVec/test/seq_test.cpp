#include "catch.hpp"
#include "SequenceVec.h"

TEST_CASE( "Check if it is a sequence!" ) {

    vector<int> v = {4,1,3,2,5};
    cxx_example::SequenceVec vec;

    SECTION( "Is this a sequence? ")
    {
        REQUIRE(vec.IsSequence(v) == true);
    }

}

