#include <iostream>
using namespace std;

// 0 liber
// 1 ocupat
// 2 florarie
// 3 bar
// 4 Romeo
// 5 Julieta

/*

5
1 0 1 0 0
4 0 3 1 5
0 0 1 0 0
1 0 2 0 0
0 0 0 0 0

 1	0	1	0	0
 6	7	3	1	14
 0	8	1	12	13
 1	9	10	11	0
 0	0	0	0	0
 
*/

int a[100][100], n, F;
int b[100][100], minim = 10000;
int xJ, yJ, xR, yR;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void citire() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            
            if (a[i][j] == 4) {
                xR = i;
                yR = j;
            }
            
            if (a[i][j] == 5) {
                xJ = i;
                yJ = j;
            }
        }
    }
}

bool interior(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool valid(int x, int y) {
    return a[x][y] == 2 || a[x][y] == 0 || a[x][y] == 5;
}

bool solutie(int x, int y) {
    return x == xJ && y == yJ;
}

void checkMin(int x, int y, int k) {
    if (k < minim) {
        minim = k;
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                b[i][j] = a[i][j];
    }
}

void bkt(int x, int y, int k) {
    int z = a[x][y];
    
    if (a[x][y] == 2) F++;
    a[x][y] = k;
    
    if (solutie(x, y)) {
        checkMin(x, y, k);
    } else {
        for (int i = 0; i < 4; i++) {
            int xn = x + dx[i];
            int yn = y + dy[i];
            
            if (valid(xn, yn) && interior(xn, yn))
                bkt(xn, yn, k + 1);
        }
    }
    
    a[x][y] = z;
    if (a[x][y] == 2) F--;
}

int main() {
    citire();
    bkt(xR, yR, 6);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << b[i][j] << "\t";
        cout << endl;
    }
    
    return 0;
}
