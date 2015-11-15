//
//  main.cpp
//  Homework
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
using namespace std;

int s[100], n;

void citire() {
    cin >> n;
    cout << endl;
}

int maximPanaLa(int p) {
    int m = 0;
    
    for (int i = 1; i <= p; i++)
        if (s[i] > m)
            m = s[i];
    
    return m;
}

bool valid(int p) {
    return true;
}

bool solutie(int p) {
    return p == n;
}

void afis(int p) {
    cout << "> ";
    for (int i = 1; i <= p; i++)
        cout << s[i] << " ";
    cout << endl;
    
    int m = maximPanaLa(p);
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++)
            if (s[j] == i)
                cout << j << " ";
        cout << endl;
    }
    
    cout << endl;
}

void bkt(int p) {
    for (int i = 1; i <= maximPanaLa(p - 1) + 1; i++) {
        s[p] = i;
        
        if (valid(p)) {
            if (solutie(p))
                afis(p);
            else
                bkt(p+1);
        }
    }
}

int main() {
    citire();
    bkt(1);
    return 0;
}
