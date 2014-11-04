#include <iostream>
using namespace std;

int n, a[100][100], v[100], nr;

void read() {
  cin >> n;

  int x, y;
  cin >> x >> y;

  while (x && y) {
    a[x][y] = a[y][x] = 1;
    cin >> x >> y;
    nr++;
  }
}

void greedy() {
  int k = 0;

  for (int i = 0; i < n; i++) {
    int clr;
    bool keepLooking = true;

    for (clr = 0; clr <= k && keepLooking; clr++) {
      v[i] = k;
      keepLooking = false;

      for (int j = 0; j < i; j++) {
        if (a[i][j]) {
          keepLooking = true;
          break;
        }
      }
    }

    if (clr == k) k++;
  }

  for (int i = 0; i < nr; i++) {
    cout << i << v[i];
  }
}

int main() {
  read();
  greedy();
  return 0;
}

