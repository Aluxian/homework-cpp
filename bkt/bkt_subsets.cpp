#include <iostream>
using namespace std;

int s[100], M[100], n, k;

void citire() {
    cin >> n;
    for (int i = 1; i <= n; cin >> M[i], i++);
}

bool valid(int p) {
    for (int i = 1; i < p; i++)
        if (s[i] == s[p])
            return false;
    return true;
}

bool solutie(int p) {
    return p == k;
}

void afis(int p) {
    for (int i = 1; i <= p; i++)
        cout << M[s[i]] << " ";
    cout << endl;
}

void bkt(int p) {
    for (int i = 1; i <= n; i++) {
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
    for (k = 1; k <= n; bkt(1), k++);
    return 0;
}

