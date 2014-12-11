#include <iostream>
using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

struct PUNCT { int x, y; };

int a[100][100], n, x0, y0, steps;
PUNCT moves[10000];

void citire() {
    cin >> n >> x0 >> y0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            steps += a[i][j];
        }
    }
}

bool valid(int x, int y) {
    return a[x][y] > 0;
}

bool solutie() {
    return steps == 0;
}

bool interior(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void afis(int k) {
    for (int i = 1; i <= k; i++)
        cout << moves[i].x << "x" << moves[i].y << " ";
    cout << endl;
}

void bkt(int x, int y, int k) {
    a[x][y]--;
    steps--;
    
    if (solutie())
        afis(k-1);
    else {
        moves[k] = *new PUNCT;
        moves[k].x = x;
        moves[k].y = y;
        
        for (int i = 0; i < 8; i++) {
            int xn = x + dx[i];
            int yn = y + dy[i];
            
            if (valid(xn, yn) && interior(xn, yn)) {
                bkt(xn, yn, k+1);
            }
        }
    }
    
    a[x][y]++;
    steps++;
}

int main() {
    citire();
    bkt(x0, y0, 1);
    return 0;
}

