#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

int interval(float x, int a, int b) {
  if (a > b) {
    int c = a;
    a = b;
    b = c;
  }
  
  if (a <= x && x <= b)
    return 1;
  else
    return 0;
}

int main() {
  ifstream fin("v100_numere.in");
  FILE *out = fopen("v100_numere.out", "w");
  
  int a, b;
  cin >> a >> b;
  float x;
  
  while (fin >> x) {
    if (interval(x, a, b)) {
      fprintf(out, "%.2f ", x);
    }
  }
  
  fprintf(out, "\n");
  fin.close();
  fclose(out);
  
  return 0;
}
