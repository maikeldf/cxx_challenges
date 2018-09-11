#include "SequenceVec.h"
#include <iostream>
#include <map>
#include <algorithm>

namespace cxx_challenges
{
  SequenceVec::SequenceVec(){}

  SequenceVec::~SequenceVec(){}

  bool SequenceVec::IsSequence(const vector<int> &a)
    {
        std::map<int,int> mymap;

         for(const auto& x : a)
         {
            mymap[x] += 1;
         }

         if (mymap.begin()->first != 1)
            return false;

         for (int i = mymap.begin()->first; i <= mymap.end()->first; i++)
         {
            if (( mymap[i] == 0 ) || ( mymap[i] > 1 ))
              return false;
         }

         return true;
    }
}
