#include <fstream>
#include <stdio.h>
using namespace std;

int main() {
  int a, b;
  
  ifstream fin("v99_numere.in");
  FILE *out = fopen("v99_numere.out", "w");
  
  while (fin >> a && fin >> b) {
    if (a < b) {
      fprintf(out, "%i ", a);
    } else {
      fprintf(out, "%i ", b);
    }
    
    fprintf(out, "%.1f ", ((float)(a+b))/2);
    
    if (a > b) {
      fprintf(out, "%i\n", a);
    } else {
      fprintf(out, "%i\n", b);
    }
  }
  
  fin.close();
  fclose(out);
  
  return 0;
}
