#include <iostream>
using namespace std;

int main() {
  long a, b;
  cin >> a >> b;
  
  if (a < b) {
    int aux = a;
    a = b;
    b = aux;
  }
  
  if (b == 0) {
    cout << "EROARE";
  } else {
    cout << "CAT: " << a / b << endl;
    cout << "REST: " << a % b << endl;
  }
  
  return 0;
}
