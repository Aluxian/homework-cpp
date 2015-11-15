//
//  main.cpp
//  Homew
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int s[100], n, A[100][100], maximum = -1;

void citire() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
}

bool valid(int p) {
    for (int i = 2 - (p % 2); i < p; i += 2)
        if (s[i] == s[p])
            return false;
    return true;
}

bool solutie(int p) {
    return p == 2*n;
}

void afis(int p) {
    int sum = 0;
    for (int i = 1; i <= p; i += 2)
        sum += A[s[i]][s[i+1]];
    
    if (sum > maximum)
        maximum = sum;
}

void bkt(int p) {
    for (int i = 1; i <= n; i++) {
        s[p] = i;
        
        if (valid(p)) {
            if (solutie(p)) {
                afis(p);
            } else
                bkt(p + 1);
        }
    }
}

int main() {
    citire();
    bkt(1);
    cout << maximum;
    return 0;
}
