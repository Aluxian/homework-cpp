//
//  main.cpp
//  Homew
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
using namespace std;

int s[100], n, k, a;
int bile[100];
char tags[100];

void citire() {
    cin >> n >> k >> a;
    cout << "1-alb 2-albastru" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> bile[i] >> tags[i];
    }
}

bool valid(int p) {
    for (int i = 1; i < p; i++)
        if (s[i] >= s[p])
            return false;
    
    if (p == k) {
        return a <= 0;
    } else {
        return true;
    }
}

bool solutie(int p) {
    return p == k;
}

void afis(int p) {
    for (int i = 1; i <= p; i++)
        cout << tags[s[i]];
    cout << endl;
}

void bkt(int p) {
    for (int i = 1; i <= n; i++) {
        s[p] = i;
        
        if (bile[i] == 1)
            a--;
        
        if (valid(p)) {
            if (solutie(p)) {
                afis(p);
            } else
                bkt(p + 1);
        }
        
        if (bile[s[p]] == 1)
            a++;
    }
}

int main() {
    citire();
    bkt(1);
    return 0;
}
