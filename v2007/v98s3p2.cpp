#include <iostream>
using namespace std;

int v[5], perm[5], iv = 0, n = 0;

void generateSet(int k) {
  for (int i = 1; i < k; i++) {
    v[iv] = i;
    iv++;
  }
  
  for (int i = k + 5; i <= 10; i++) {
    v[iv] = i;
    iv++;
  }
}

void reverseSet() {
  int aux;
  for (int i = 0; i < iv / 2; i++) {
    aux = v[i];
    v[i] = v[iv - i - 1];
    v[i] = aux;
  }
}

void printK(int k) {
  for (int i = 0; i <= 4; i++) {
    cout << k + i << " ";
  }
}

void generatePerm(int k) {
  for (int i = 0; i <= iv; i++) {
    for (int j = 0; j < iv; j++) {
      if (i == j)
        printK(k);
      cout << v[j] << " ";
    }
    
    if (i == iv)
      printK(k);
    
    cout << endl;
  }
}

int main() {
  int k;
  cin >> k;
  
  generateSet(k);
  generatePerm(k);
  reverseSet();
  generatePerm(k);
  
  return 0;
}
