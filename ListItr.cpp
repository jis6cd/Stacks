/*
 *Jessica Shaughnessy
 *jis6cd
 *ListItr.cpp
 *September 3
*/

#include "ListItr.h"
using namespace std;

//Default constructor
ListItr::ListItr(){
  //retrieves address of current ListNode that the ListItr is pointing to
  current = NULL;
}
//Constructor
ListItr::ListItr(ListNode* theNode):
  //assigns the value of the pointer variable theNode to the variable current
  current(theNode) {
}

//function isPastEnd; checks to see if the ListItr is past the end position
bool ListItr::isPastEnd() const{
  //looks at the current ListNode, dereferences the pointer "next" and sees if the object that the pointer points to is equal to NULL.
  if (current->value == 0){
    if (current->next==NULL){
      return true;
    }
    else{
    return false;
    }
  }
  return false;
}

//function isPastBeginning; checks to see if the ListItr is past the beginning position
bool ListItr::isPastBeginning() const{
  //looks at the current ListNode, dereferences the pointer "previous" and sees if the object that the pointer points to is equal to NULL.
  if (current->value == 0){
    if (current->previous ==NULL){
      return true;
    }
    else{
    return false;
    }
  }
  return false;
}
//function moveForward;moves current pointer forward one, if there is a forward position.
void ListItr::moveForward(){
  // checks to make sure the object is not equal to NULL
  if (current->next != NULL)
    //sets the pointer current to the address of this object, not the object itself (ex: not this.*next)
   current = current->next;
}

//function moveBackward(); moves current pointer backwards one, if there is a backwards position.
void ListItr::moveBackward(){
  //checks to make sure the object is not equal to NULL
  if (current->previous != NULL)
    // sets current equal to the address of the object, not the object itself (ex: not this.*previous)
    current = current -> previous;
}
//retrieves value of the currentListNode
int ListItr::retrieve() const{
  return current->value;
}
