#include <iostream>
#include "LL.h"

//Default Constructor
LL::LL(){}

//Copy Constructor
LL::LL(const LL &lList){
   head = nullptr;

   if (lList.head != nullptr){
      Node *current = lList.head;
      while (current != nullptr){
         this->append(current->data); 
         current = current->next; 
      }
   }
}

//Destructor
LL::~LL(){
   Node * temp = nullptr;
   for (Node *toRemove = head; toRemove != nullptr; ) {
      temp = toRemove->next;
      delete toRemove;
      toRemove = temp;
   }
   head = nullptr;
}

//Prepend
//Standard push if head->top
void LL::prepend(int newElement){
   Node * curr = new Node(newElement);
   curr->next = head;
   head = curr;
   return;
}

//Insert
//Precondition: List is sorted
void LL::insert(int newElement){
    Node * newNode = new Node(newElement);
    //NEWNODE MUST ALLOCATE ELSE FAIL
    if(newNode != NULL){
        if(head==nullptr){
            head = newNode;
        }
        else{
            if(newElement < head->data){
                newNode->next = head;
                head = newNode;
                return;
            }
            Node * temp = head;
            //small to large ordered
            while(temp->next->data < newElement && temp->next != nullptr){
                temp = temp->next;
            }
            if(temp->next == nullptr){
                temp->next = newNode;
                newNode->next = nullptr;

            }
            else{
            newNode->next = temp->next;
            temp->next = newNode;
            }
        }
        return;
    }
}

//Append
//Standard enqueue if head->top
void LL::append(int newElement){
   Node * newNode = new Node(newElement);
   if(newNode != NULL){
      if(head==nullptr){
         head = newNode;
      }
      else{
        Node * curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
      }
      newNode->next = nullptr;
   }
   return;
}

//Reverse
void LL::reverse(const LL &lList){
    Node * prev = NULL; Node * current = head; Node * next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

//Remove
//Precondition: LL exists
//Remove last for dequeue and first for pop (if top = head)
//Code is portion end of fn
void LL::remove(int newElement){
    if(head == NULL){
        return;
    }
    Node * curr = head;
    if(head->data == newElement){
        head = head->next;
        delete curr;
        return;
    }
    else{
        while(curr->next->data != newElement && curr->next != nullptr){
            curr = curr->next;
        }
        if(curr->next != nullptr){
            Node * toRemove = curr->next;
            curr->next = toRemove->next;
            curr = toRemove->next;
            delete toRemove;
        }
        return; 
    }
    //Exception handle node not found
}