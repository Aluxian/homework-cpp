#include <iostream>
using namespace std;

int dt[] = {1, 2, 1, 0, 0};
int dz[] = {0, 0, 1, 2, 1};

int ti, zi, moves[100];
char mv[][3] = {"t", "tt", "tz", "zz", "z"};

void citire() {
    cin >> ti >> zi;
}

bool valid(int t, int z) {
    return (t <= z || z == 0) && t >= 0 && z >= 0 && (ti - t <= zi - z || zi - z == 0);
}

bool solutie(int t, int z) {
    return t == 0 && z == 0;
}

void afis(int k) {
    for (int i = 1; i < k; i++)
        cout << mv[moves[i]] << " ";
    cout << endl;
}

void bkt(int t, int z, int k) {
    if (solutie(t, z)) {
        afis(k);
    } else {
        for (int i = 0; i <= 3; i++) {
            int tn = t - dt[i];
            int zn = z - dz[i];
            
            if (valid(tn, zn)) {
                moves[k] = i;
                bkt(tn, zn, k + 1);
            }
        }
    }
}

int main() {
    citire();
    bkt(ti, zi, 1);
    return 0;
}
