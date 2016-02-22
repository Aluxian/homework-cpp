#include <iostream>
using namespace std;

struct NOD {
  long val;
  NOD *next;
};

long elim2(NOD *p) {
  long val = -1;
  
  if (p != NULL && p->next != NULL) {
    val = p->next->val;
    p->next = p->next->next;
  }
  
  return val;
}

int main() {
  NOD *p = new NOD();
  NOD *n = new NOD();
  NOD *c = new NOD();
  
  p->val = 20;
  n->val = 50;
  c->val = 100;
  
  p->next = n;
  n->next = c;
  
  cout << elim2(p) << endl;
  cout << p->next->val;
}
