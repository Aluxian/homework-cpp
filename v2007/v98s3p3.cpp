#include <fstream>
#include <stdio.h>
#include <math.h>
using namespace std;

float expr(long n) {
  float sum = 0;
  
  for (int i = 1; i <= n; i++) {
    sum += 1.0 / sqrt(i);
  }
  
  return sum;
}

int main() {
  ifstream fin("v98_bac.in");
  FILE *out = fopen("v98_bac.out", "w");
  
  long x;
  fin >> x;
  float sum = 0;
  
  for (int i = 1; i <= x; i++) {
    if (i%2 == 0) {
      sum = sum - (expr(i) - expr(i-1));
    } else {
      sum = sum + (expr(i) - expr(i-1));
    }
  }
  
  fprintf(out, "%.3f", sum);
  
  fin.close();
  fclose(out);
  
  return 0;
}
