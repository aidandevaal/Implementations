#include <iostream>

class LL {

    private:
        class Node {
            public:
                int data;
                Node * next = nullptr;
                Node(int newData): data(newData) {}
        };
        
        Node * head = nullptr;

   public:

      LL();

      LL(const LL &lList);

      ~LL();

      void prepend(int newElement);

      void insert(int newElement);
      
      void append(int newElement);

      void reverse(const LL &lList);

      void remove(int newElement);

};

/*
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
*/


