//
//  main.cpp
//  Homew
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
using namespace std;

int s[100], n, v;

void citire() {
    cin >> n >> v;
}

bool valid(int p) {
    if (p > 1 && abs(s[p] - s[p-1]) < v) return false;
    for (int i = 1; i < p; i++)
        if (s[i] == s[p])
            return false;
    return true;
}

bool solutie(int p) {
    return p == n;
}

void afis(int p) {
    for (int i = 1; i <= p; i++) {
        cout << s[i] << " ";
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
                bkt(p + 1);
        }
    }
}

int main() {
    citire();
    bkt(1);
    return 0;
}
