#include <iostream>
#include "aStack.h"

using std::cout;
using std::endl;

//Constructor
Stack::Stack() {
    elements = new int[capacity];
    top = 0;
    elementCount = 0;
    capacity = 6;
}

//Destructor
Stack::~Stack() {
    delete[] elements;
}

//Push
void Stack::push(int newElement) {
    //If new overflows
    if(elementCount >= capacity){
        //Double capacity
        int newCapacity = capacity*2;
        int * newElements = new int[newCapacity];
        //Copy elements
        for(int i=0;i<elementCount;i++){
            newElements[i] = elements[i];
        }
        //Delete old array and point elements to new array
        delete[] elements;
        elements = newElements;
        //Update capacity, front and back
        capacity = newCapacity;
        top = elementCount;
    }
    elements[top] =  newElement;
    top = (top + 1) % capacity; 
    elementCount++;   
    return;
} 

//Pop
void Stack::pop() {
    if(elementCount>0)
        //Update elementCount and front
        elementCount--;
        top = (top + 1) % capacity;
        //Condition to satisfy requested dequeue params (i.e. elemCount < 1/4 capacity & capacity can't be less than 6 (Initial))
        if(elementCount < capacity/4 && capacity >= capacity*2){
            //Halve capacity
            int newCapacity = capacity/2;
            int * newElements = new int[newCapacity];
            //Move elements
            for(int i=0;i<elementCount;i++){
                newElements[i] = elements[(top + i) % capacity];
            }
            //Delete old array and point elements to new array
            delete[] elements;
            elements = newElements;
            //Update capacity
            capacity = newCapacity;
            top = elementCount;
        }
    return;
} 

//Peek
int Stack::peek() const {
    return elements[top];    
} 

//isEmpty
bool Stack::isEmpty() const {
    return elementCount == 0;
}

//Print
void Stack::printStack(){
    for(int i = 0; i < elementCount; i++){
        cout << elements[i] << endl;
    }
}