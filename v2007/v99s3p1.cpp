#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  if (a < b && b < c)
    cout << 1;
  else if (a > b && b > c)
    cout << 2;
  else if (b > a && b > c)
    cout << 3;
  else if (b < a && b < c)
    cout << 4;
  
  return 0;
}
