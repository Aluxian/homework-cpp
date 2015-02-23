#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], viz[100], c[100], n;

void citire() {
    ifstream fin("graf_bfs.in");
    fin >> n;

    int x, y;

    while (fin >> x >> y) {
        a[x][y] = a[y][x] = 1;
    }

    fin.close();
}

void bfs(int x) {

}

int main() {
    citire();

    int start;
    cin >> start;

    bfs(start);
    return 0;
}
