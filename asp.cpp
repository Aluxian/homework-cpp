#include <iostream>
#include <limits.h>
using namespace std;

typedef struct {
  int start;
  int finish;
  string name;
} ACTIVITY;

void read(ACTIVITY activities[], int &n);
void sort(ACTIVITY activities[], int n);
void greedy(ACTIVITY activities[], int n);

int main() {
  int n;
  ACTIVITY activities[100];

  read(activities, n);
  sort(activities, n);
  greedy(activities, n);

  return 0;
}

void read(ACTIVITY activities[], int &n) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    ACTIVITY *activity = new ACTIVITY;
    cin >> activity->start >> activity->finish >> activity->name;
    activities[i] = activity;
  }
}

void sort(ACTIVITY activities[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (activities[i].start > activities[i+1].start) {
      ACTIVITY *temp = activities[i];
      activities[i] = activities[i+1];
      activities[i+1] = temp;

      if (i > 0) i -= 2;
    }
  }
}

void greedy(ACTIVITY activities[], int n) {
  int p, u[100];
  cin >> p;

  for (int i = 0; i < p; i++) {
    cout << i << " = " << activities[i]->name << endl;
    u[i] = i;
  }

  for (int i = p; i < n; i++) {
    int poz = -1, min = INT_MAX;

    for (int j = 0; j < p; j++)
      if (activities[i].start > activities[u[j]].finish)
        if (activities[i].start - activities[u[j]].finish < min)
          min = activities[i].start - activities[u[j]].finish;
      else break;

    if (poz > -1) {
      cout << poz << " = " << activities[i]->name << endl;
      u[poz] = i;
    }
  }
}

