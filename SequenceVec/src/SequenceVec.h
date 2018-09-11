#ifndef SEQUENCEVEC_H
#define SEQUENCEVEC_H

/*
Check whether array A is a sequence.

A non-empty array X consisting of N integers .

A sequence containis each element from 1 to N once only once.

For example:
    X[0] = 4
    X[1] = 1
    X[2] = 3
    X[3] = 2

is a sequence, but this array:
    X[0] = 4
    X[1] = 1
    X[2] = 2

is not a sequence, because value 3 is missing.

The goal is to check whether array is a sequence,
returning "true" if it is and "false" if it is not.
*/

#include <vector>

using namespace std;

namespace cxx_challenges
{
   class SequenceVec
   {
   public:
      SequenceVec();
      ~SequenceVec();
      bool IsSequence(const vector<int>& a);
   };
}

#endif // SEQUENCEVEC_H
