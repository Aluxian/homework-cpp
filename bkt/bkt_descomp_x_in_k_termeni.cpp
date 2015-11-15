//
//  main.cpp
//  Homework
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
using namespace std;

int s[100], x, k;

void citire() {
    cin >> x >> k;
}

bool valid(int p) {
    if (p > 1) {
        int sum = 0;
        
        if (s[p] < s[p-1])
            return false;
        
        for (int i = 1; i <= p; i++)
            sum += s[i];
        
        if (p == k && sum != x)
            return false;
    }
    
    return true;
}

bool solutie(int p) {
    return p == k;
}

void afis(int p) {
    for (int i = 1; i <= p; i++)
        cout << s[i] << " ";
    cout << endl;
}

void bkt(int p) {
    for (int i = 1; i <= x; i++) {
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
