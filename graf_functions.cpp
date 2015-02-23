//
//  main.cpp
//  Homework
//
//  Created by Alexandru Rosianu on 11/01/15.
//  Copyright (c) 2015 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void f1(int a[][100], int &n) {
    ifstream fin("matrice.in");
    fin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
        }
    }
    
    fin.close();
}

void f2(int a[][100], int &n, int &m) {
    ifstream fin("matrice.in");
    fin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        fin >> x >> y;
        a[x][y] = 1;
    }
    
    fin.close();
}

bool f3(int a[][100], int n) {
    for (int i = 1; i <= n; i++) {
        if (a[i][i] != 0) {
            return false;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && a[i][j] != a[j][i]) {
                return false;
            }
        }
    }
    
    return true;
}

// grad vf x
int f4(int a[][100], int x, int n) {
    int g = 0;
    
    for (int j = 1; j <= n; j++) {
        g += a[x][j];
    }
    
    return g;
}

void f5(int a[][100], int n) {
    for (int i = 1; i <= n; i++) {
        int g = 0;
        
        for (int j = 1; j <= n; j++) {
            g += a[i][j];
        }
        
        if (g == 0) {
            cout << i;
        }
    }
}

int f6(int a[][100], int n) {
    int noduri = 0;
    
    for (int i = 1; i <= n; i++) {
        int g = 0;
        
        for (int j = 1; j <= n; j++) {
            g += a[i][j];
        }
        
        if (g == 1) {
            noduri++;
        }
    }
    
    return noduri;
}

bool f7(int a[][100], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i][j] == 0) {
                return false;
            }
        }
    }
    
    return true;
}

int f8(int a[][100], int b[][100], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == b[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

bool f9(int a[][100], int V[], int k, int n) {
    for (int i = 1; i < k; i++) {
        if (a[V[k]][V[k+1]] == 0) {
            return false;
        }
    }
    
    return true;
}

bool f10(int a[][100], int V[], int k) {
    for (int i = 1; i < k; i++) {
        if (a[V[k]][V[k+1]] == 0) {
            return false;
        }
    }
    
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j < i; j++) {
            if (V[i] == V[j]) {
                return false;
            }
        }
    }
    
    return true;
}
