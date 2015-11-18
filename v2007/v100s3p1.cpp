#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  float sum = 0;
  
  for (int i = 1; i <= n; i += 2) {
    sum += sqrt(i);
  }
  
  for (int i = 2; i <= n; i += 2) {
    sum -= sqrt(i);
  }
  
  printf("%.4f", sum);
  return 0;
}
