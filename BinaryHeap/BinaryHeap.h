#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "BinaryHeap.h"

template <class ElementType>
class BinaryHeap {

private:
   
   constexpr static unsigned int INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
   ElementType * elements = nullptr;                   // The Binary Heap

   unsigned int elementCount = 0;                      // Number of elements in the Binary Heap - if you need it!
   unsigned int capacity = INITIAL_CAPACITY;           // Actual capacity of the data structure (number of cells in the array)
 
   // Utility method - Recursively put the array back into a Minimum Binary Heap.
   void reHeapUpMin(unsigned int indexOfBottom);

   // Utility method - Recursively put the array back into a Minimum Binary Heap.
   void reHeapDownMin(unsigned int indexOfRoot);  

   void reHeapUpMax(unsigned int indexOfBottom);

   void reHeapDownMax(unsigned int indexOfRoot);
   
public:

   // Default Constructor
   BinaryHeap(); 
   
   // Destructor
   ~BinaryHeap();
   
   // Description: Returns the number of elements in the Binary Heap.
   // Postcondition: The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   unsigned int getElementCount() const;

   // Description: Inserts newElement into the Binary Heap. 
   //              It returns true if successful, otherwise false.      
   // Time Efficiency: O(log2 n)
   bool insert(ElementType & newElement);
      
   // Description: Removes (but does not return) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(log2 n)
   void remove();

   // Description: Retrieves (but does not remove) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Postcondition: This Binary Heap is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(1) 
   ElementType & retrieve() const;

   // For Testing Purposes.
   // Description: Prints the content of "this". 
   void print( ) const;
   
}; 
#include "BinaryHeap.cpp" 
#endif