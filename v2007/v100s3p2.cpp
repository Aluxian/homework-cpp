#include <iostream>
using namespace std;

int m, n;
int a[20][38];
int i = 1;

void read() {
  cin >> n;
  m = 2*n-2;
}

int different() {
  int diff = 0;
  
  for (int k = 0; k < n; k++) {
    if (a[i][k] != a[i-1][k]) {
      diff++;
    }
  }
  
  return diff == 2;
}

int unique() {
  int unique = 1;
  
  for (int ti = 0; unique && ti < i; ti++) {
    int same = 1;
    
    for (int tj = 0; same && tj < n; tj++) {
      if (a[ti][tj] != a[i][tj]) {
        same = 0;
      }
    }
    
    if (same) {
      unique = 0;
    }
  }
  
  return unique;
}

int solution(int p) {
  return (p == (n-1)) && different() && unique();
}

void bkt(int p);

void bkt(int d, int p) {
  if (p < n) {
    a[i][p] = d;
  
    if (solution(p)) {
      i++;
      if (i < m) {
        bkt(0);
      }
    } else {
      bkt(d, p+1);
    }
  }
}

void bkt(int p) {
  bkt(0, p);
  bkt(1, p);
}

void print() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
}

int main() {
  read();
  bkt(0);
  print();
  return 0;
}
