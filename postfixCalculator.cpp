/*
Jessica Shaughnessy
jis6cd
postfixCalculator.cpp
september 11
*/

#include <iostream>
#include "postfixCalculator.h"
#include <cstdlib>
using namespace std;

postfixCalculator::postfixCalculator() {
  p = new stack();
  
}

void postfixCalculator:: add() {
  if (p->empty()){
    cout << "There is nothing in the stack" << endl;
    exit(-1);
  }
  int a = p->top();
  p->pop();
  int b = p->top();
  p->pop();
  int final = b+a;
  p->push(final);
}

void postfixCalculator::subtract(){
  if (p->empty()){
    cout << "There is nothing in the stack" << endl;
    exit(-1);
  }
  int a = p->top();
  p->pop();
  int b = p->top();
  p->pop();
  int final = b-a;
  p->push(final);
}

void postfixCalculator::multiply(){
  if (p->empty()){
    cout << "There is nothing in the stack" << endl;
    exit(-1);
  }
  int a = p->top();
  p->pop();
  int b = p->top();
  p->pop();
  int final = b*a;
  p->push(final);
}

void postfixCalculator::divide(){
  if (p->empty()){
    cout << "There is nothing in the stack" << endl;
    exit(-1);
  }
  int a = p->top();
  p -> pop();
  int b = p->top();
  p->pop();
  int final = b/a;
  p->push(final);
}

void postfixCalculator::negate(){
  if (p->empty()){
    cout << "There is nothing in the stack" << endl;
    exit(-1);
  }
  int a = p->top();
  p->pop();
  int final = -1*a;
  p->push(final);

}

void postfixCalculator::insert(int x){
  p->push(x);
}

int postfixCalculator::getTopValue(){
  if (p->empty()){
    cout << "There is nothing in the stack" << endl;
    exit(-1);
  }
  int a = p->top();
  return a;
}

bool postfixCalculator::isNotEmpty(){
  if (p->empty()){
    return false;
  }
  return true;
}
