//
//  main.cpp
//  Homework
//
//  Created by Alexandru Rosianu on 11/01/15.
//  Copyright (c) 2015 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

char a[100], b[100];
int arr[100][100], m, n;

void prepend(char *str, char prefix) {
    char *temp = new char[strlen(str) + 2];
    temp[0] = prefix;
    strcpy(temp + 1, str);
    strcpy(str, temp);
}

void citire() {
    cin >> a >> b;
    
    m = (int) strlen(a);
    n = (int) strlen(b);
    
    prepend(a, ' ');
    prepend(b, ' ');
}

void printm() {
    cout << endl << " \t \t";
    
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \t";
    }
    
    cout << endl;
    
    for (int i = 0; i <= m; i++) {
        cout << a[i] << "\t";
        for (int j = 0; j <= n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << endl;
}

void dino() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                arr[i][j] = arr[i-1][j-1] + 1;
            } else {
                arr[i][j] = arr[i-1][j] > arr[i][j-1] ? arr[i-1][j] : arr[i][j-1];
            }
        }
    }
    
    printm();
}

void afis() {
    char common[100];
    int k = arr[m][n] - 1;
    
    for (int i = m, j = n; arr[i][j] > 0; i--, j--) {
        while (arr[i][j-1] == arr[i][j]) {
            j--;
        }
        
        while (arr[i-1][j] == arr[i][j]) {
            i--;
        }
        
        common[k--] = a[i];
    }
    
    common[arr[m][n]] = NULL;
    cout << common;
}

int main() {
    citire();
    dino();
    afis();
    return 0;
}
