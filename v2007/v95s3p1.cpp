#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char u[101], v[101];
  cin >> u >> v;
  
  int lu = strlen(u);
  int lv = strlen(v);
  
  if (lu != lv) {
    cout << "EROARE";
  } else {
    cout << u << endl;
    
    for (int i = 0; i < lu; i++) {
      if (u[i] != v[i]) {
        u[i] = v[i];
        cout << u << endl;
      }
    }
  }
  
  return 0;
}
