#include <iostream>

using namespace std;

void print_mat(int a[][100], int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

void print_mat(int a[][100], int n) {
    print_mat(a, n, n);
}
