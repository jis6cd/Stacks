/*
Jessica Shaughnessy
jis6cd
sept 14
stack.cpp
*/

#include <iostream>
#include "stack.h"
using namespace std;

stack::stack(){
  l = new List();

}

void stack:: push(int e){
  l->insertAtHead(e);

}

int stack::top(){
  return l->getFirstValue();

}

void stack::pop() {
  l->remove_first(); 

}

bool stack::empty() {
  return l->isEmpty();
}
