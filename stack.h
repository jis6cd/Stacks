/*
Jessica Shaughnessy
jis6cd
september 14
stack.h
*/

#include <iostream>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
using namespace std;

class stack {
 public:
  stack();
  void push(int e);
  int top();
  void pop();
  bool empty();
 private:
  List *l;
};
