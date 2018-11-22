/*
 *Jessica Shaughnessy
 *jis6cd
 *List.cpp
 *September 3
*/

#include "List.h"
using namespace std;

//Default constructor
List::List(){
  //Dynamically allocate ListNodes ("new")
  //need a pointer to the head and tail
  //need to creat  a head node and tail node (where value = NULL)
  //need to know how many elements are in the list (count variable)
  head = new ListNode();
  head->value = 0;
  head->previous = NULL;
  tail = new ListNode();
  tail->value = 0;
  tail->next = NULL;
  head->next = tail;
  tail->previous = head;
  count = 0;
}

//copy constructor
List::List(const List& source){
   head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

//destructor
List::~List(){
  //call makeEmpty
  //delete head
  //delete tail
  count = 0;
  while (head->next->next != NULL){
    delete head-> next;
}
  delete head;
  delete tail;
}
//equals operator
List& List::operator = (const List& source){
  if (this == &source){
        return *this;
  }
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}
//looks to see if there are any ListNodes in the list by looking at the variable count
//dont count head or tail
bool List::isEmpty() const{
  if (count == 0)
    return true;
  else
    return false;
}
//removes all ListNodes in the list except for the head and tail
void List::makeEmpty(){
  ListItr *empty_itr = new ListItr(head->next);
  while (!empty_itr->isPastEnd()){
    empty_itr->moveForward();
   delete  empty_itr->current->previous;
  }
  head->next = tail;
  tail->previous = head;
  count = 0;
}

int List::getFirstValue(){
  ListItr *first_Itr = new ListItr(head->next);
  return first_Itr->current->value;
}

//returns an iterator that points to the ListNode in the first position
ListItr List::first(){
  ListItr *first_Itr = new  ListItr(head->next);
  return *first_Itr;
}

//returns an iterator that points to the listnode in the first position
ListItr List::last(){
  ListItr *last_Itr= new ListItr();
  last_Itr->current = tail->previous;
  return *last_Itr; 
}
// inserts x after the current iterator p
void List::insertAfter(int x, ListItr position){
  ListNode* afterNode = new ListNode();
  afterNode->value = x;
  afterNode->previous = position.current;
  afterNode->next = position.current->next;
  position.current->next->previous = afterNode;
  position.current ->next = afterNode;
  count++;
}

// inserts x before the current iterator p
void List::insertBefore(int x, ListItr position){
  ListNode* beforeNode = new ListNode();
  beforeNode -> value = x;
  beforeNode->next = position.current;
  beforeNode ->previous = position.current->previous;
  position.current->previous->next = beforeNode;
  position.current -> previous = beforeNode;
  count ++;
}

// inserts x at the end of the list, before the tail
void List::insertAtTail(int x){
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->previous = tail->previous;
  newNode->next = tail;
  tail->previous->next = newNode;
  tail->previous = newNode;
  count ++;

}

void List::insertAtHead(int x){
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->next = head->next;
  newNode->previous = head;
  head->next->previous = newNode;
  head->next = newNode;
  count++;
}

void List:: remove_first(){
  ListItr *remove_first = new ListItr(head->next);
  remove_first->current ->next->previous = head;
  head ->next = remove_first->current->next;
  delete remove_first->current;
  count --;
}

//removes  the first occurance of x
void List::remove(int x){
  ListItr *remove_int = new ListItr(head);
  while (remove_int->current->value != x || remove_int->isPastEnd()){
    remove_int->moveForward();
  }
  if (remove_int->current->value == x){
    delete remove_int->current;
    count --;
  }
  }

//returns an iterator tothe first occurance of x, else returns a iterator to the dummy tail
ListItr List::find(int x){
  ListItr *found_int= new ListItr(head);
  while (!found_int->isPastEnd()){
    if (found_int -> current->value == x){
      return *found_int;
    }
    found_int->moveForward();
  }
  return *found_int; 
}
// returns the number of elements in the list
int List::size()const{
  return count;
}


//printList: non-member function prototype; prints list forwards when direction is true or backwards when direction is false
void printList(List& source, bool direction){
  int itr_count = 0;
  if (direction == true){
    ListItr *print_forward = new ListItr(source.first());
    while (!print_forward->isPastEnd()){
      itr_count ++;
      cout<<"This is the " << itr_count << " node out of " << source.size() << " nodes. The value for this node is: " << print_forward->retrieve()<< endl;
      print_forward->moveForward();
    }
  }
  else if(direction == false){
      ListItr *print_backwards  = new ListItr(source.last());
      while (!print_backwards->isPastBeginning()){
	int count_diff = source.size() - itr_count;
	cout << "This is the "<< count_diff << " node out of " << source.size() << "nodes. The value for this node is: " << print_backwards->retrieve() << endl;
	print_backwards->moveBackward();
	itr_count ++;
      }
    }     

}
