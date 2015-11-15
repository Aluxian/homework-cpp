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
        for (int j = 1; j <= i; j++) {
            int maximum = 0;
            
            for (int k = j-1; k <= j+1; k++) {
                if (k > 0 && k <= n && b[i-1][k] > maximum) {
                    maximum = b[i-1][k];
                }
            }
            
            b[i][j] = a[i][j] + maximum;
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
        for (int k = col-1; k <= col+1; k++) {
            if (k > 0 && k <= n && b[line][col] - a[line][col] == b[line-1][k]) {
                afisare(line - 1, k);
                break;
            }
        }
        
        cout << col << endl;
    }
}

int main() {
    citire();
    afisare(n, dino());
    return 0;
}
