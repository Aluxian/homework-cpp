#include <iostream>
using namespace std;



int main() {
  long a, b;
  cin >> a >> b;
  
  int exista = 0;
  int c1, c2;
  
  while (a != 0 && !exista) {
    c1 = a % 10;
    
    long d = b;
    while (d != 0 && !exista) {
      c2 = d % 10;
      if (c1 == c2)
        exista = 1;
      d = d / 10;
    }
    
    a = a / 10;
  }
  
  if (exista) {
    cout << "DA";
  } else {
    cout << "NU";
  }
  
  return 0;
}
