/*
Jessica Shaughnessy
jis6cd
postfixCalculator.h
sept 11
*/

#include <iostream>
#include "stack.h"
using namespace std;

class postfixCalculator {
 public:
  postfixCalculator();
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  void insert(int x);
  int getTopValue();
  bool isNotEmpty();
 private:
  stack *p;
};
  
