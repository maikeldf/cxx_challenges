#include "src/SequenceVec.h"
#include <iostream>
#include <algorithm>

int main ()
{
  cxx_example::SequenceVec vec;
  vector<int> v = {4,1,3,2};
  
  for_each( v.cbegin(), v.cend(),
    [](int x){cout << x << " ";} );

  cout << endl << "Is a sequence: " <<
  (vec.IsSequence(v) ? "true" : "false") << endl;
  
  return 0;
}