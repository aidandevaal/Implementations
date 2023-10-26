#include <iostream>
#include "LL.h"

//Constructor
Stack::Stack(){
    top = nullptr;
}

bool Stack::pop(){
    //if not empty
    if(top != nullptr){
        //if top next is null top is deleted
        if(top->next == nullptr){
            delete top;
            top = nullptr;
        }
        else{
            //make node for removal
            StackNode * nodeToRemove = top;
            //find node to remove
            while(nodeToRemove->next->next != nullptr){
                nodeToRemove = nodeToRemove->next;
            }
            //free data from node and point node to null
            delete nodeToRemove->next;
            nodeToRemove->next = nullptr;
        }
        return true;
    }
    //no node to remove
    return false;
}

int Stack::peek(){
    //if node exists
    if(top!=nullptr){
        //make node to track
        StackNode * seekNode = top;
        while(seekNode->next != nullptr){
            seekNode = seekNode->next;
        }
        //return data of seek node
        return seekNode->data;
    }
    //no node in stack
    return -1;
}

bool Stack::push(int newData){
    //if top is null create top and set values
    if(top == nullptr){
        top = new StackNode();
        top->data = newData;
        top->next = nullptr;
        return true;
    }
    else if(top != nullptr){
        //allocate memory for new node
        StackNode * nodeToAdd = new StackNode();
        //create tracker
        StackNode * curr = top;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        //add next to stack
        curr->next = nodeToAdd;
        //set its data to indicated value
        nodeToAdd->data = newData;
        nodeToAdd->next = nullptr;
        //set it as top
        return true;
    }
    return false;
}

bool Stack::isEmpty(){
    //if no top: not constructed
    if(top == nullptr){
        return true;
    }
    return false;
}