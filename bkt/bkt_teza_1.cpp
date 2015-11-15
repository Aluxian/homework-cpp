#include <iostream>
#include <string.h>
using namespace std;

int s[100], n, anagrameNr;
char sir[100], anagrame[100][100];

void citire() {
    cin >> sir;
    n = (int) strlen(sir);
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

void afis() {
    for (int i = 1; i <= anagrameNr; i++) {
        bool matches = true;
        
        for (int j = 1; j <= n; j++) {
            if (sir[s[j] - 1] != sir[anagrame[i][j] - 1]) {
                matches = false;
                break;
            }
        }
    
        if (matches)
            return;
    }
    
    anagrameNr++;
    
    for (int i = 1; i <= n; i++)
        anagrame[anagrameNr][i] = s[i];
}

void bkt(int p) {
    for (int i = 1; i <= n; i++) {
        s[p] = i;
        
        if (valid(p)) {
            if (solutie(p))
                afis();
            else
                bkt(p + 1);
        }
    }
}

int main() {
    citire();
    bkt(1);
    
    for (int i = 1; i <= anagrameNr; i++) {
        for (int j = 1; j <= n; j++)
            cout << sir[anagrame[i][j] - 1];
        cout << endl;
    }
    
    return 0;
}
