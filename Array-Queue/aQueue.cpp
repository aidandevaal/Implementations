#include <iostream>
#include "aQueue.h"

using std::cout;
using std::endl;

//Constructor
Queue::Queue() {
    elements = new int[capacity];
    front = 0;
    back = 0;
    elementCount = 0;
    capacity = capacity;
}

//Destructor
Queue::~Queue() {
    delete[] elements;
}

//Enqueue
void Queue::enqueue(int newElement) {
    //If new overflows
    if(elementCount >= capacity){
        //Double capacity
        int newCapacity = capacity*2;
        int * newElements = new int[newCapacity];
        //Copy elements
        for(int i=0;i<elementCount;i++){
            newElements[i] = elements[(front + i) % capacity];
        }
        //Delete old array and point elements to new array
        delete[] elements;
        elements = newElements;
        //Update capacity, front and back
        capacity = newCapacity;
        front = 0;
        back = elementCount;
    }
    elements[back] =  newElement;
    back = (back + 1) % capacity; 
    elementCount++;   
    return;
} 

//Dequeue
void Queue::dequeue() {
    if(elementCount>0)
        //Update elementCount and front
        elementCount--;
        front = (front + 1) % capacity;
        //Condition to satisfy requested dequeue params (i.e. elemCount < 1/4 capacity & capacity can't be less than 6 (Initial))
        if(elementCount < capacity/4 && capacity >= capacity*2){
            //Halve capacity
            int newCapacity = capacity/2;
            int * newElements = new int[newCapacity];
            //Move elements
            for(int i=0;i<elementCount;i++){
                newElements[i] = elements[(front + i) % capacity];
            }
            //Delete old array and point elements to new array
            delete[] elements;
            elements = newElements;
            //Update capacity
            capacity = newCapacity;
            //Update front of new array
            front = 0;
        }
    return;
} 

//Peek
int Queue::peek() const {
    return elements[front];    
} 

//isEmpty
bool Queue::isEmpty() const {
    return elementCount == 0;
}

//Print
void Queue::printQueue(){
    for(int i = 0; i < elementCount; i++){
        cout << elements[i] << endl;
    }
}