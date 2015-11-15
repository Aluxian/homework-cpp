#include <iostream>
#include <fstream>
#include "print_tools.h"

using namespace std;

int a[100][100], viz[100], n;

void citire() {
    ifstream fin("graf.in");
    fin >> n;

    int x, y;
    while (fin >> x >> y) {
        a[x][y] = a[y][x] = 1;
    }

    fin.close();
}

void bfs(int x) {
    int u, p, c[100];
    u = p = 1;

    viz[x] = 1;
    c[p] = x;

    while (p <= u) {
        x = c[p++];

        for (int y = 1; y <= n; y++) {
            if (a[x][y] && !viz[y]) {
                viz[y] = 1;
                c[++u] = y;
            }
        }
    }

    for (int i = 1; i < p; i++) {
        cout << c[i] << " ";
    }
}

int main() {
    citire();
    print_mat(a, n);

    int start;
    cin >> start;

    bfs(start);
    return 0;
}
