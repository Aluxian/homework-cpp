#include <fstream>
#include <stdio.h>
using namespace std;

int count(float x[2500], float a, float b) {
  if (b > a) {
    float c = a;
    a = b;
    b = c;
  }
  
  int n = 2500;
  
  if (x[2499] < a || x[0] > b)
    n = 0;
  else {
    for (int i = 0; i < 2500; i++)
      if (x[i] < a)
        n--;

    for (int i = 2499; i >= 0; i--)
      if (x[i] > b)
        n--;

    if (n < 0)
      n = 0;
  }
  
  return n;
}
