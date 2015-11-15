//
//  main.cpp
//  Homew
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
using namespace std;

int s[100], n, k;

void citire() {
    cin >> n >> k;
}

bool valid(int p) {
    return s[p] % k == 0;
}

bool solutie(int p) {
    return p == n;
}

void afis(int p) {
    for (int i = 1; i <= p; i++)
        cout << s[i] << " ";
    cout << endl;
}

void bkt(int p) {
    for (int i = 1; i <= 9; i++) {
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
