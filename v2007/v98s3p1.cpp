#include <iostream>
using namespace std;

int main() {
  long x;
  cin >> x;
  
  int identice = 1;
  int cifra = x%10;
  
  while (x != 0) {
    int c = x%10;
    
    if (c != cifra) {
      identice = 0;
    }
    
    x = x/10;
  }
  
  if (identice)
    cout << "DA";
  else
    cout << "NU";
  
  return 0;
}
