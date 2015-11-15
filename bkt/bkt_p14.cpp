//
//  main.cpp
//  Homew
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
using namespace std;

int s[100], nr, n, k;
int maxx[100];
int nos[100];

void citire() {
    cin >> nr >> k;
    
    // Find nr of digits
    int c = nr;
    while (c) {
        c /= 10;
        n++;
    }
    
    // Move digits into nos
    c = nr;
    for (int i = 0; i < n; i++) {
        nos[n - i] = c%10;
        c /= 10;
    }
}

bool valid(int p) {
    if (p > 1 && s[p] < s[p-1])
        return false;
    
    for (int i = 1; i < p; i++)
        if (s[i] == s[p])
            return false;
    
    return true;
}

bool solutie(int p) {
    return p == n - k;
}

void afis(int p) {
    for (int i = 1; i <= p; i++)
        if (nos[s[i]] < maxx[i])
            return;
    for (int i = 1; i <= p; i++)
        maxx[i] = nos[s[i]];
}

void afis3(int p) {
    for (int i = 1; i <= p; i++) {
        cout << nos[s[i]] << " ";
    }
    cout << endl;
}

void afis2() {
    for (int i = 1; i <= n - k; i++) {
        cout << maxx[i] << " ";
    }
    cout << endl;
}

void bkt(int p) {
    for (int i = 1; i <= n; i++) {
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
    afis2();
    return 0;
}
