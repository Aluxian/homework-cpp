#include <iostream>
using namespace std;

/*
 
 8 1 9 2 8 3 7 4 5
 
 v: 19283745
 l: 51413121
 u: 30507080
 
 1 2 3 4 5

*/

int v[100], l[100], u[100], n;

void citire() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
}

void dino() {
    l[n] = 1;
    u[n] = 0;
    
    for (int i = n - 1; i >= 1; i--) {
        int pos = 0;
        int lMax = 0;
        
        for (int j = i + 1; j <= n; j++) {
            if (l[j] > lMax && v[j] > v[i]) {
                lMax = l[j];
                pos = j;
            }
        }
        
        l[i] = 1 + lMax;
        u[i] = pos;
    }
}

void debug() {
    cout << endl << "v: ";
    for (int i = 1; i <= n; cout << v[i], i++);
    cout << endl << "l: ";
    for (int i = 1; i <= n; cout << l[i], i++);
    cout << endl << "u: ";
    for (int i = 1; i <= n; cout << u[i], i++);
    cout << endl << endl;
}

void afisare() {
    int p = 0, m = 0;
    
    for (int i = 1; i <= n; i++) {
        if (l[i] > m) {
            m = l[i];
            p = i;
        }
    }
    
    while (p != 0) {
        cout << v[p] << " ";
        p = u[p];
    }
}

int main() {
    citire();
    dino();
//    debug();
    afisare();
    cout << endl << endl;
}
