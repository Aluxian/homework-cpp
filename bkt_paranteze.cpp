//
//  main.cpp
//  Homework
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

// Sa se scrie un program BKT care construieste toate sirurile prin paranteze deschise si inchise corect.

#include <iostream>
using namespace std;

char par[] = ") (";
int s[100], n, S;

void citire() {
    cin >> n;
}

bool valid(int p) {
    if (S < 0)
        return false;
    
    if (p == n && S != 0)
        return false;
    
    return true;
}

bool solutie(int p) {
    return p == n;
}

void afis(int p) {
    for (int i = 1; i <= p; i++)
        cout << par[s[i] + 1];
    cout << endl;
}

void bkt(int p) {
    for (int i = -1; i <= 1; i += 2) {
        s[p] = i;
        
        S += i;
        
        if (valid(p)) {
            if (solutie(p)) {
                afis(p);
            } else
                bkt(p + 1);
        }
        
        S -= i;
    }
}

int main() {
    citire();
    bkt(1);
    return 0;
}
