#include "AttrParser.h"
#include <sstream>
#include <limits>
#include <iostream>
using namespace std;
using namespace cxx_challenges;

int main()
{
  int n, q;
  string input, r;
  cin >> n >> q;

  if(( n > 20 ) || ( q > 20 ))
    return -1;

  cin.clear(); 
  cin.ignore(
    numeric_limits<int>::max(), '\n');

  AttrParser attrParser;
  for(unsigned int i= 0; i < n; i++)
  {
    getline(cin, input);
    
    if(input.size() > 200 )
      return -1;

    attrParser.SetLine(input);
  }

  for(unsigned int i= 0; i < q; i++)
  {
    std::getline(cin, input);
    cout << attrParser.GetValue(input) << endl;
  }

  return 0;
}
