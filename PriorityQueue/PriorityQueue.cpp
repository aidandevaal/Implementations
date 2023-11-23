

#include <iostream> 
#include "PriorityQueue.h"  // Header file


using std::cout;
using std::endl;

  
// Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() : elements(new BinaryHeap<ElementType>) { }

// Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {

   delete elements;

   // cout << "PriorityQueue destructor" << endl; // For learning purposes!
}  

// Description: Returns "true" if this Priority Queue is empty, otherwise "false".
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
   return ( elements->getElementCount() == 0 );
} 


// Description: Inserts newElement in this Priority Queue and 
//              returns "true" if successful, otherwise "false".   
template <class ElementType>     
bool PriorityQueue<ElementType>::enqueue(ElementType& newElement) {

   // cout << "PriorityQueue::enqueue" << endl;

   return elements->insert(newElement);

} 

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
template <class ElementType>
void PriorityQueue<ElementType>::dequeue() {
   
   // This version of dequeue does not peek.
	// Enforce precondition
   try {
      elements->remove();
   }
   catch( EmptyDataCollectionException& anException ) {
      // cout << "Problem dequeue'ing from Binary heap!" << endl;
      throw EmptyDataCollectionException("dequeue() called with an empty PriorityQueue!");
   }
   return;

} 


// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const {
   try {
      return elements->retrieve();
   }
   catch( EmptyDataCollectionException& anException ) {
     // cout << "Problem peek'ing from Binary heap!" << endl;
      throw EmptyDataCollectionException("peek() called with an empty PriorityQueue!") ;
   }

}  


// For Testing Purposes.
// Description: Prints the content of "this". 
template <class ElementType>
void PriorityQueue<ElementType>::print( ) const {
   //cout << "In print()" << endl;
   elements->print();
      
}  // end printPriorityQueue