#include <iostream>

class Queue {
	
    private:
        int * elements;

        unsigned int elementCount = 0;
        unsigned int capacity = 6;       
        unsigned int front = 0;                   
        unsigned int back = 0;                    



    public:
        Queue();

        ~Queue();

        void enqueue(int newElement);

        void dequeue();

        int peek() const;

        bool isEmpty() const;

        void printQueue();
};