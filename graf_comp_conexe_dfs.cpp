#include <iostream>
#include <fstream>

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

void dfs(int x, int k) {
    viz[x] = k;
    c[++p] = x;

    for (int y = 1; y <= n; y++) {
        if (a[x][y] && !viz[y]) {
            dfs(y, k);
        }
    }
}

int main() {
    citire();
    int k = 0;

    for (int i = 1; i <= n; i++) {
        if (!viz[i]) {
            dfs(i, ++k);
        }
    }

    for (int i = 1; i <= k; i++) {
        printf("componenta %i:", i);

        for (int j = 1; j <= n; j++) {
            if (viz[j] == i) {
                printf(" %i", j);
            }
        }

        cout << endl;
    }

    return 0;
}
