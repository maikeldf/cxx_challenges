#include "Factorial.h"

namespace fat
{
  Factorial::Factorial()
  {
  }
  Factorial::~Factorial()
  {
  }

  int Factorial::Calc(int number)
  {
    return (number <= 1) ? 
      number : Calc(number - 1) * number;
  }
}
