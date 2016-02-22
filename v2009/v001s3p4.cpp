#include <iostream>
using namespace std;

int sub(int v[], int n, int a) {
  int num = 0;
  
  for (int i = 0; i < n; i++) {
    if (v[i] < a) {
      num++;
    }
  }
  
  return num;
}

int eq(int a, int b) {
  int va[] = {a};
  int vb[] = {b};
  return sub(va, 1, b) + sub(vb, 1, a) == 0;
}

int check(int v[], int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      if (eq(v[i], v[j])) {
        return 0;
      }
    }
  }
  
  return 1;
}

int main() {
  int n; cin >> n;
  int a[100];
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  if (check(a, n)) {
    cout << "DA";
  } else {
    cout << "NU";
  }
  
  return 0;
}
