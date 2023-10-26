#include <iostream>

class Stack {

    private:
        class StackNode {
            public:
                int data;
                StackNode * next;
        };

        StackNode * top;    
        
    public:
        Stack();
    
        bool pop();

        int peek();

        bool push(int newData);

        bool isEmpty(); 

};