#include <iostream>
using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int a[100][100], n, x0, y0;

void citire() {
    cin >> n >> x0 >> y0;
}

bool valid(int x, int y) {
    return a[x][y] == 0;
}

bool solutie(int x, int y) {
    return a[x][y] == n*n;
}

bool interior(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void afis() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void bkt(int x, int y, int k) {
    a[x][y] = k;
    
    if (solutie(x, y))
        afis();
    else {
        for (int i = 0; i < 8; i++) {
            int xn = x + dx[i];
            int yn = y + dy[i];
            
            if (valid(xn, yn) && interior(xn, yn)) {
                bkt(xn, yn, k+1);
            }
        }
    }
    
    a[x][y] = 0;
}

int main() {
    citire();
    bkt(x0, y0, 1);
    return 0;
}

