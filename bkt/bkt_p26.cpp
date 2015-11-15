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

bool valid(int p, bool hasVowel) {
    for (int i = 1; i < p; i++)
        if (s[i] >= s[p])
            return false;
    
    if (p == k) {
        return hasVowel && a <= 0;
    } else {
        return hasVowel;
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

void bkt(int p, bool hasVowel) {
    for (int i = 1; i <= n; i++) {
        s[p] = i;
        bool hasVowelNow = hasVowel;
        
        if (bile[i] == 1) {
            a--;
            
            if (!hasVowelNow)
                hasVowelNow = strchr("aeiou", tags[i]) != NULL;
        }
        
        if (valid(p, hasVowelNow)) {
            if (solutie(p)) {
                afis(p);
            } else
                bkt(p + 1, hasVowelNow);
        }
    }
}

int main() {
    citire();
    bkt(1, false);
    return 0;
}
