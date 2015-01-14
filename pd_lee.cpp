//
//  main.cpp
//  Homework
//
//  Created by Alexandru Rosianu on 11/01/15.
//  Copyright (c) 2015 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 
 6 10
 1 1 1 1 1 1 1 1 1 1
 0 0 1 1 1 1 0 1 1 0
 0 1 0 0 0 0 0 1 1 0
 0 1 0 1 1 1 1 1 1 1
 0 0 0 0 0 0 1 1 1 1
 1 1 1 1 1 1 1 1 1 1
 4 3 2 2
 
 1 1 1 1 1 1 1 1 1 1
 8 9 1 1 1 1 8 1 1 0
 7 1 3 4 5 6 7 1 1 0
 6 1 2 1 1 1 1 1 1 1
 5 4 3 4 5 6 1 1 1 1
 1 1 1 1 1 1 1 1 1 1
 
 7
 5x3 5x2 5x1 4x1 3x1 2x1 2x2 
 
*/

struct Point {
    int x;
    int y;
};

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int a[100][100], m, n;
Point v[100], A, B;

void citire() {
    cin >> m >> n;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    cin >> A.x >> A.y >> B.x >> B.y;
}

bool interior(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n;
}

void print() {
    cout << endl;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        
        cout << endl;
    }
}

void dino() {
    int k = 0, u = 0;
    int x = A.x, y = A.y;
    
    a[x][y] = 2;
    v[k] = A;
    
    while (k <= u && !(x == B.x && y == B.y)) {
        x = v[k].x;
        y = v[k].y;
        
        for (int i = 0; i < 4; i++) {
            int xn = x + dx[i];
            int yn = y + dy[i];
            
            if (a[xn][yn] == 0 && interior(xn, yn)) {
                a[xn][yn] = a[x][y] + 1;
                
                u++;
                v[u].x = xn;
                v[u].y = yn;
            }
        }
        
        k++;
    }
}

void afis() {
    cout << endl;
    
    if (a[B.x][B.y] <= 2) {
        cout << "bad luck :(";
    } else {
        int nr = a[B.x][B.y] - 2;
        cout << nr << endl;
        
        int xs[100], ys[100];
        int pos = nr;
        
        int x = B.x;
        int y = B.y;
        
        while (a[x][y] > 2) {
            pos--;
            xs[pos] = x;
            ys[pos] = y;
            
            for (int i = 0; i < 4; i++) {
                int xn = x + dx[i];
                int yn = y + dy[i];
                
                if (a[x][y] == a[xn][yn] + 1 && interior(xn, yn)) {
                    x = xn;
                    y = yn;
                    break;
                }
            }
        }
        
        for (int i = 0; i < nr; i++) {
            cout << xs[i] << "x" << ys[i] << " ";
        }
    }
}

int main() {
    citire();
    dino();
    print();
    afis();
    cout << endl << endl;
    return 0;
}
