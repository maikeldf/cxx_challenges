#include "Factorial.h"
#include <stdio.h>

int main()
{
  int number(5);
  printf("Factorial of %d is %d\n", 
    number, fat::Factorial().Calc(number));

  return 0;
}