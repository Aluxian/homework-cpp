#include <iostream>
#include <fstream>

using namespace std;

int n, a[100][100], viz[100];

void citire() {
    ifstream fin("graf.in");
    fin >> n;

    int x, y;

    while (fin >> x >> y) {
        a[x][y] = a[y][x] = 1;
    }

    fin.close();
}

void lanturi_min(int x) {
    int p, u, c[100];
    p = u = 1;

    viz[x] = -1;
    c[p] = x;

    while (p <= u) {
        x = c[p++];

        for (int y = 1; y <= n; y++) {
            if (a[x][y] && !viz[y]) {
                c[++u] = y;
                viz[y] = x;
            }
        }
    }
}

void afis_lanturi_min(int x) {
    if (x != -1) {
        afis_lanturi_min(viz[x]);
        cout << x << " ";
    } else {
        cout << endl;
    }
}

int main() {
    citire();

    int start;
    cin >> start;

    lanturi_min(start);

    for (int i = 1; i <= n; i++) {
        if (viz[i] != 0) {
            afis_lanturi_min(i);
        }
    }

    return 0;
}
