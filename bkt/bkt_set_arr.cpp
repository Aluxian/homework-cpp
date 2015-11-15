#include <iostream>
using namespace std;

int v[100], nos[100], n, k;

void read() {
  cin >> n >> k;
  for (int i = 1; i <= n; cin >> nos[i], i++);
}

bool valid(int p) {
  for (int i = 1; i < p; i++)
    if (v[i] == v[p])
      return false;
  return true;
}

bool solutie(int p) {
  return p == k;
}

void print(int p) {
  for (int i = 1; i <= p; i++)
    cout << v[i] << " ";
  cout << endl;
}

void bkt(int p) {
  for (int i = 1; i <= n; i++) {
    v[p] = nos[i];

    if (valid(p)) {
      if (solutie(p))
        print(p);
      else
        bkt(p+1);
    }
  }
}

int main() {
  read();
  bkt(1);
  return 0;
}

