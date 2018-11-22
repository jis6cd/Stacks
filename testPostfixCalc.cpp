/*
Jessica Shaughnessy
jis6cd
testPostfixCalc.cpp
sept 11
*/

#include <iostream>
#include "postfixCalculator.h"
#include <string>
#include <cstdlib>
using namespace std;

int main(){
  postfixCalculator *u = new postfixCalculator();
  string s;
  cout << "Please enter a postfix expression. End input by striking the enter key and hitting Ctrl D" << endl;
  while (cin>> s){
    cout << s << endl;
    const char *s_char = s.c_str();
    if (isdigit(*s_char)){
      int int_s = atoi(s_char);
      u->insert(int_s);
    }
    if (1<s.length() && s.at(0)=='-'){
      string sub_s = s.substr(1);
      const char *sub_s_char = sub_s.c_str();
      if (isdigit(*sub_s_char)){
	int int_sub_s = atoi(sub_s_char);
	u->insert(int_sub_s);
	u->negate();
      }
    }
    else {
      if( s == "+"){
	u->add();
      }
      if (s == "-"){
	u->subtract();
      }
      if (s =="*"){
	u->multiply();
      }
      if (s == "/"){
	u->divide();
      }
      if (s == "~"){
	u->negate();
      }
    }
  }
  if (u->isNotEmpty()){
  cout << "the expression evaluates to: " << u->getTopValue() <<endl;
  }
  return 0;
}
