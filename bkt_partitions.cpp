#include <iostream>
using namespace std;

int s[100], n;

void citire() {
    cin >> n;
}

int max(int p) {
    int m = 0;
    for (int i = 1; i <= p; i++)
        if (s[i] > m)
            m = s[i];
    return m;
}

bool valid(int p) {
    return true;
}

bool solutie(int p) {
    return p == n;
}

void afis(int p) {
    for (int i = 1; i <= max(n); i++)
        for (int j = 1; j <= n; j++)
            if (s[j] == i)
                cout << j << " ";
    cout << "----------------" << endl;
}

void bkt(int p) {
    for (int i = 1; i <= max(p - 1) + 1; i++) {
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

