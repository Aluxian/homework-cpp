#include <iostream>
#include <string.h>
using namespace std;

// 0 - liber
// 1 - ocupat
// 2 - un cal
// 3 - alt cal
// 4.. - pasi

/*
 
 4 6
 1 1 0 0 3 0
 0 0 0 1 0 1
 0 1 0 0 1 0
 0 2 1 0 0 0
 
 1	1	0	0	3	0
 0	0	5	1	0	1
 0	1	0	0	1	0
 0	4	1	0	0	0
 
 1	1	0	0	3	0
 0	0	0	1	0	1
 0	1	0	5	1	0
 0	4	1	0	0	0
 
 1	1	6	0	3	0
 5	0	0	1	0	1
 0	1	0	7	1	0
 0	4	1	0	0	0
 
 1	1	0	7	3	0
 5	8	0	1	0	1
 0	1	6	9	1	0
 0	4	1	0	0	0
 
 1	1	0	0	3	0
 5	8	0	1	0	1
 0	1	6	9	1	0
 7	4	1	0	0	0
 
*/

int a[100][100], n, m, x0, y0;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void citire() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            
            if (a[i][j] == 2) {
                x0 = i;
                y0 = j;
            }
            
        }
    }
    
    cout << endl;
}

bool valid(int x, int y) {
    return a[x][y] == 0;
}

bool interior(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool solutie(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int xn = x + dx[i];
        int yn = y + dy[i];
        
        if (a[xn][yn] == 3)
            return true;
    }
    
    return false;
}

void afis() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
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
            
            if (valid(xn, yn) && interior(xn, yn))
                bkt(xn, yn, k + 1);
        }
    }
    
    a[x][y] = 0;
}

int main() {
    citire();
    bkt(x0, y0, 4);
    return 0;
}
