#include <iostream>
using namespace std;

/*

9
0 0 0 0 0 0 6 8 0
0 0 0 0 7 3 0 0 9
3 0 9 0 0 0 0 4 5
4 9 0 0 0 0 0 0 0
8 0 3 0 5 0 9 0 2
0 0 0 0 0 0 0 3 6
9 6 0 0 0 0 3 0 8
7 0 0 6 8 0 0 0 0
0 2 8 0 0 0 0 0 0

1 7 2 5 4 9 6 8 3
6 4 5 8 7 3 2 1 9
3 8 9 2 6 1 7 4 5
4 9 6 3 2 7 8 5 1
8 1 3 4 5 6 9 7 2
2 5 7 1 9 8 4 3 6
9 6 4 7 1 5 3 2 8
7 3 1 6 8 2 5 9 4
5 2 8 9 3 4 1 6 7

*/

int a[100][100], n;

void bktFirstEmptyCell(int prevNum);

void citire() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
}

bool valid(int x, int y) {
    // a[x][y] sa fie 0
    if (a[x][y] != 0) {
        return false;
    }

    // a[x][y] sa nu existe deja pe aceeasi linie/coloana
    for (int i = 1; i <= n; i++)
        if ((a[i][y] == a[x][y] && i != x) || (a[x][i] == a[x][y] && i != y))
            return false;

    // a[x][y] sa nu existe deja in patratul 3x3
    int xSection = (x - 1) / 3 + 1;
    int ySection = (y - 1) / 3 + 1;

    for (int i = 3 * xSection - 2; i <= 3 * xSection; i++)
        for (int j = 3 * ySection - 2; j <= 3 * ySection; j++)
            if (a[i][j] == a[x][y] && i != x && j != y)
                return false;

    return true;
}

bool solutie() {
    // sa nu existe valori 0
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 0)
                return false;
    return true;
}

void afis() {
    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

/**
 * @return urmatorul numar din intervalul [1, 9] && >= min ce poate fi pus in pozitia (x, y)
 */
int nextNumber(int x, int y, int min) {
    // daca min exista deja pe (x, y), atunci returneaza urmatorul numar >= min+1 ce poate fi pus pe pozitia aia
    for (int i = 1; i <= n; i++)
        if (a[i][y] == min || a[x][i] == min)
            return nextNumber(x, y, min + 1);

    // la fel daca min deja exista in patratul 3x3 in care se afla
    int xSection = (x - 1) / 3 + 1;
    int ySection = (y - 1) / 3 + 1;

    for (int i = 3 * xSection - 2; i <= 3 * xSection; i++)
        for (int j = 3 * ySection - 2; j <= 3 * ySection; j++)
            if (a[i][j] == min)
                return nextNumber(x, y, min + 1);

    return min;
}

void bkt(int x, int y, int num) {
    int prev = -1;

    while (true) {
        num = nextNumber(x, y, num + (num == prev)); // daca num este egal cu prev atunci apeleaza cu num+1 in loc de num

        if (num > 9) {
            return;
        }

        prev = num;
        a[x][y] = num;

        if (solutie())
            afis();
        else {
            bktFirstEmptyCell(1);
        }

        a[x][y] = 0;
    }
}

/**
 * Ruleaza bkt cu num pe prima pozitie libera gasita in matrice.
 */
void bktFirstEmptyCell(int num) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) {
                bkt(i, j, num);
                return;
            }
        }

    }
}

int main() {
    citire();
    bktFirstEmptyCell(1);
    return 0;
}
