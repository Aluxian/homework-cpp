#include <iostream>
#include <fstream>

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
    int u, p, c[100], t = x;
    u = p = 1;

    viz[x] = 1;
    c[p] = x;

    while (p <= u) {
        x = c[p++];

        for (int y = 1; y <= n; y++) {
            if (a[x][y] && !viz[y]) {
                c[++u] = y;
                viz[y] = viz[x] + 1;
            }
        }
    }

    cout << "c: ";
    for (int i = 1; i < p; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        if (viz[i] != 0) {
            printf("lantul %i-%i de lungime minima %i\n", t, i, viz[i] - 1);
        }
    }

    cout << endl;
}

int main() {
    citire();

    int start;
    cin >> start;

    bfs(start);
    return 0;
}
