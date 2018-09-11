#include "SequenceVec.h"
#include <iostream>
#include <algorithm>
#include <vector>

int main ()
{
  cxx_challenges::SequenceVec vec;
  vector<int> v = {4,1,3,2};

  for_each( v.cbegin(), v.cend(),
   [](int x){cout << x << " ";} );

  cout << endl << "Is a sequence: " <<
  (vec.IsSequence(v) ? "true" : "false") << endl;

 return 0;
}