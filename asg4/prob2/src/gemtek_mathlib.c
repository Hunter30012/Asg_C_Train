#include "gemtek_lib.h"
#include <stdio.h>

int tong(int x, int y)
{
    return x+y;
}

bool isFibonacci(int x)
{
  if (x == 0 || x == 1) {
    return true;
  }
 
  int a = 0, b = 1, c;
 
  while (true) {
    c = a + b;
    a = b;
    b = c;
 
    if (c == x) {
      return true;
    } else if (c >= x) {
      return false;
    }
  }
}