#include <iostream>

class Stack {
	
    private:
        int * elements;
        unsigned int capacity;       

        unsigned int elementCount = 0;
        unsigned int top = 0;                                       



    public:
        Stack();

        ~Stack();

        void push(int newElement);

        void pop();

        int peek() const;

        bool isEmpty() const;

        void printStack();
};