#include <iostream>
#include <math.h>
using namespace std;

int main() {
  float x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  
  int prop = x1 == sqrt(x2 * x3)
    || x2 == sqrt(x1 * x3)
    || x3 == sqrt(x1 * x2);
  
  if (prop)
    cout << "DA";
  else
    cout << "NU";
  
  return 0;
}
