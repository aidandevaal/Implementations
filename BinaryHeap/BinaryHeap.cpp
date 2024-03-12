#include <iostream>
#include "BinaryHeap.h"  // Header file

using std::cout;
using std::endl;
  
// Default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {} 

// Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap(){
   if ( elements ) {
      delete [] elements;
      elements = nullptr;
   }
}
   
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
   return elementCount;
}  

template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement) {
   bool ableToInsert = false;

   // If Binary Heap does not exist
   if (elements == nullptr) {
      elements = new ElementType[capacity];
      if (elements == nullptr) 
         return ableToInsert;
   }
     
   // Binary Heap full
   if (elementCount == capacity){
      ElementType * elements2 = new ElementType[capacity * 2];
      if (elements2 == nullptr){                               
         return ableToInsert ;
      }
      for (unsigned int i = 0; i < elementCount ; i++) {      
         elements2[i] = elements[i]; 
      }
      capacity = 2 * capacity;
      delete [] elements;
      elements = elements2;   
   }
   unsigned int indexOfBottom = elementCount;
   ableToInsert = true;
   elements[indexOfBottom] = newElement;
   elementCount++;
   reHeapUp(indexOfBottom);
   return ableToInsert;
} 


// Utility method - Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUpMin(unsigned int indexOfBottom) {
   unsigned int indexOfRoot = 0;
   ElementType temp;
   unsigned int indexOfParent;
   if(indexOfBottom > indexOfRoot){
      indexOfParent = (indexOfBottom - 1) / 2;
      if(!(elements[indexOfParent] <= elements[indexOfBottom])){
      temp = elements[indexOfParent];
      elements[indexOfParent] = elements[indexOfBottom];
      elements[indexOfBottom] = temp;
      reHeapUp(indexOfParent);
      }
   }
   return;
} 

template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
    
   if ( elementCount > 0 ) 
      reHeapDown(0);
   
   return;   
}


// Utility method
// Description: Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDownMin(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;   

   // If we need to swap, select the smallest child
   if ((elements[indexOfRoot] > elements[indexOfLeftChild]))
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      if ((elements[indexOfMinChild] > elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
}

// Sort the heap again from bottom up for Max Heap
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUpMax(unsigned int indexOfRoot) {
    unsigned int parent = (indexOfRoot - 1) / 2;

    while (indexOfRoot > 0 && elements[indexOfRoot] > elements[parent]) {
        ElementType temp = elements[indexOfRoot];
        elements[indexOfRoot] = elements[parent];
        elements[parent] = temp;
        indexOfRoot = parent(indexOfRoot);
    }

}

// Sort the heap again from top down for Max Heap
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDownMax(unsigned int indexOfRoot) {

    unsigned int maxIndex = indexOfRoot;
    unsigned int left = 2 * indexOfRoot + 1;
    unsigned int right = 2 * indexOfRoot + 2;

    if (left > elementCount - 1) { return; }

    if(left < elementCount && elements[left] > elements[maxIndex]){
        maxIndex = left;
    }
    if (right < elementCount && elements[right] > elements[maxIndex]) {
        maxIndex = right;
    }
    if (indexOfRoot != maxIndex) {
        swap(elements[indexOfRoot], elements[maxIndex]);
        reHeapDownMax(maxIndex);
    }
}

template <class ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() const {
    // Enforce precondition
    if ( elementCount == 0 )
        throw EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.");
    else
        return elements[0]; 
}

// For Testing Purposes
// Description: Prints the content of "this".
template <class ElementType>
void BinaryHeap<ElementType>::print() const {

   cout << "{";
   for (unsigned int i= 0; i < elementCount; i++) {
      elements[i].print();
      if (i + 1 < elementCount) {
        cout << ", " ;
      }
   }
   cout << "}" << endl;
   return;
} 