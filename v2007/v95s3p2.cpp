#include <iostream>
using namespace std;

void inter(float &a, float &b) {
  float aux = a;
  a = b;
  b = aux;
}

void circ(float v[], int n) {
  float aux;
  inter(v[0], aux);
  
  for (int i = 0; i < n - 1; i++) {
    inter(v[i], v[i + 1]);
  }
  
  inter(v[n - 1], aux);
}

int main() {
  int n;
  cin >> n;
  
  float v[100];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  circ(v, n);
  
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  
  return 0;
}
