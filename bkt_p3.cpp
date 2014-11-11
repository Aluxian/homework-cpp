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

int s[100], n;
char word[100];

void citire() {
    cin >> word;
    n = (int) strlen(word);
}

bool valid(int p) {
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
        cout << word[s[i]-1];
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
