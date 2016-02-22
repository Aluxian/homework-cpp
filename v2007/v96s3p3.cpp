#include <iostream>
#include <fstream>
using namespace std;

int sp(int x) {
  int n = 1;
  
  for (int i = 1; i <= x/2; i++) {
    if (x%i == 0) {
      n++;
    }
  }
  
  return n % 2;
}

int main() {
  ifstream fin("v96_bac.txt");
  
  long n;
  fin >> n;
  
  long nums = 0;
  long long sum = 0;
  int x;
  
  for (long i = 0; i < n; i++) {
    fin >> x;
    if (sp(x) == 1) {
      sum = sum + x;
      nums++;
    }
  }
  
  printf("MA: %.2f", sum / (nums * 1.0));
  
  fin.close();
  return 0;
}
