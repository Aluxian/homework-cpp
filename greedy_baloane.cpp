/*
 * Intr-o incapere se afla o tija gradata de care sunt legate n baloane.
 * Pentru fiecare balon se cunoaste coordonata punctului in care este legat de sfoara si raza acestuia.
 * Stiind ca o sfoara dezlegata determina ridicarea balonului pe tavan pastrand coordonata initiala,
 * determinati un nr maxim de baloane ce pot fi dezlegate astfel incat ajunse pe tavan acestea sa fie cel mult
 * tangente.
 */

#include <iostream>
using namespace std;

typedef struct { int x, r; } BALLOON;

BALLOON *balloons[100];
int n;

void read() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    BALLOON *b = new BALLOON;
    cin >> b->x >> b->r;
    balloons[i] = b;
  }
}

void sort() {
  for (int i = 0; i < n; i++) {
    if (balloons[i]->x + balloons[i]->r > balloons[i+1]->x + balloons[i+1]->r) {
      BALLOON *b = balloons[i];
      balloons[i] = balloons[i+1];
      balloons[i+1] = b;
    }

    if (i > 0) i -= 2;
  }
}

void greedy() {
  int no, previous;

  cout << balloons[0]->x << endl;
  previous = 0;

  for (int i = 1; i < n; i++) {
    if (balloons[i]->x - balloons[i]->r >= balloons[previous]->x - balloons[previous]->r) {
      cout << balloons[i]->x << endl;
      no++;
    }
  }

  cout << no;
}

int main() {
  read();
  sort();
  greedy();
  return 0;
}

