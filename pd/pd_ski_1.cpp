#include <iostream>
using namespace std;

/*
 
 5
 3
 2 7
 4 3 7
 4 7 1 4
 2 7 8 3 1
 
 */

int a[100][100], b[100][100], n;

void citire() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
}

void printB() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << b[i][j] << "\t";
        }
        
        cout << endl;
    }
}

int dino() {
    b[1][1] = a[1][1];
    
    for (int i = 2; i <= n; i++) {
        b[i][1] = a[i][1] + b[i-1][1];
        b[i][i] = a[i][i] + b[i-1][i-1];
        
        for (int j = 2; j < i; j++) {
            b[i][j] = a[i][j] + (b[i-1][j] > b[i-1][j-1] ? b[i-1][j] : b[i-1][j-1]);
        }
    }
    
    printB();
    
    // Find col
    int col = 0, colMaxValue = 0;
    
    for (int i = 1; i <= n; i++) {
        if (b[n][i] > colMaxValue) {
            colMaxValue = b[n][i];
            col = i;
        }
    }
    
    return col;
}

void afisare(int line, int col) {
    if (line > 0) {
        if (col == 1) {
            afisare(line - 1, 1);
        } else if (col == line) {
            afisare(line - 1, line - 1);
        } else {
            afisare(line - 1, b[line][col] - a[line][col] == b[line-1][col] ? col : col - 1);
        }
        
        cout << col << endl;
    }
}

int main() {
    citire();
    afisare(n, dino());
    return 0;
}
