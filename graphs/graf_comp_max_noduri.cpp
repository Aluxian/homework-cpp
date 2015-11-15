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

    int comp = -1;
    int max = -1;

    for (int i = 1; i <= k; i++) {
        int nr = 0;

        for (int j = 1; j <= n; j++) {
            if (viz[j] == i) {
                nr++;
            }
        }

        if (nr > max) {
            max = nr;
            comp = i;
        }
    }

    printf("componenta cu cele mai multe noduri (%i) este %i", max, comp);
    return 0;
}
