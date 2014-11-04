#include <iostream>
using namespace std;

typedef struct { int val, line, col; } ELEMENT;

ELEMENT *elements[100][100];
int lines, cols;
bool col_chosen[100];

void read() {
  cin >> lines >> cols;

  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < cols; j++) {
      elements[i][j] = new ELEMENT;
      cin >> elements[i][j]->val;
      elements[i][j]->line = i;
      elements[i][j]->col = j;
    }
  }
}

void write() {
  cout << endl;
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < cols; j++)
      cout << elements[i][j]->val << "\t";
    cout << endl;
  }
}

void sortLines() {
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < cols - 1; j++) {
      if (elements[i][j]->val < elements[i][j+1]->val) {
        ELEMENT *temp = elements[i][j];
        elements[i][j] = elements[i][j+1];
        elements[i][j+1] = temp;

        if (j > 0) j -= 2;
      }
    }
  }
}

void sortFirstCol() {
  for (int i = 0; i < lines - 1; i++) {
    if (elements[i][0] < elements[i+1][0]) {
      for (int j = 0; j < cols; j++) {
        ELEMENT *temp = elements[i][j];
        elements[i][j] = elements[i+1][j];
        elements[i+1][j] = temp;
      }

      if (i > 0) i -= 2;
    }
  }
}

void greedy() {
  cout << endl;
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < cols; j++) {
      if (col_chosen[j]) continue;
      cout << elements[i][j]->val << " + ";
      col_chosen[j] = true;
      break;
    }
  }
}

int main() {
  read();
  write();
  sortLines();
  write();
  sortFirstCol();
  write();
  greedy();

  return 0;
}

