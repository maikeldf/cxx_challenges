#include "catch.hpp"
#include "SequenceVec.h"

TEST_CASE( "Sequence vector test (pass)", "[single-file]"  ) {

    vector<int> v = {4,1,3,2,5};
    cxx_challenges::SequenceVec vec;

    SECTION( "Is this a sequence? ")
    {
        REQUIRE(vec.IsSequence(v) == true);
    }

}

