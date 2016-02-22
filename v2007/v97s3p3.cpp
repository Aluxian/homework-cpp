#include <iostream>
using namespace std;

long subprogram(float x[10][10], int n, int p) {
  long sum = 0;
  
  for (int i = 0; i < n; i++) {
    sum = sum + x[p][i];
  }
  
  return sum;
}

int main() {
  int n;
  cin >> n;
  
  float x[10][10];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> x[i][j];
  
  long maxSum = 0;
  int maxPos = 0;
  
  for (int i = 0; i < n; i++) {
    long sum = subprogram(x, n, i);
    if (sum > maxSum) {
      maxSum = sum;
      maxPos = i;
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << x[maxPos][i] << " ";
  }
  
  return 0;
}
