#include <iostream>
#include <fstream>
#include "print_tools.h"

using namespace std;

int a[100][100], viz[100], c[100], n, p = 0;

void citire() {
    ifstream fin("graf.in");
    fin >> n;

    int x, y;
    while (fin >> x >> y) {
        a[x][y] = a[y][x] = 1;
    }

    fin.close();
}

void dfs(int x) {
    viz[x] = 1;
    c[++p] = x;

    for (int y = 1; y <= n; y++) {
        if (a[x][y] && !viz[y]) {
            dfs(y);
        }
    }
}

int main() {
    citire();
    print_mat(a, n);

    int start;
    cin >> start;

    dfs(start);
    for (int i = 1; i <= p; i++) {
        cout << c[i] << " ";
    }

    return 0;
}
