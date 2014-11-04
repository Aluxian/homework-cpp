/*
 * Fie n ob de greutate si val data si un rucsac ce poate suporta o greutate G,
 * alegeti obiecte astfel incat valoarea aleasa sa fie maxima.
 */

#include <iostream>
using namespace std;

typedef struct { float weight, val; } OBJECT;

OBJECT *objects[100];
int n, G;

void read() {
  cin >> G >> n;
  for (int i = 0; i < n; i++) {
    OBJECT *o = new OBJECT;
    cin >> o->weight;
    cin >> o->val;
    objects[i] = o;
  }
}

void sort() {
  for (int i = 0; i < n - 1; i++) {
    if (objects[i]->val / objects[i]->weight < objects[i+1]->val / objects[i+1]->weight) {
      OBJECT *temp = objects[i];
      objects[i] = objects[i+1];
      objects[i+1] = temp;

      if (i > 0) i -= 2;
    }
  }
}

void greedy() {
  int sum = 0;

  for (int i = 0; i < n && G > 0; i++) {
    if (objects[i]->weight <= G) {
      cout << objects[i]->weight << "-" << objects[i]->val << " ";
      G -= objects[i]->weight;
      sum += objects[i]->val;
    }
  }

  cout << endl << "sum=" << sum;
}

int main() {
  read();
  sort();
  greedy();

  return 0;
}

