#include <iostream>

using namespace std;

//Hoare Partition
int partition(int array[], int start, int end) 
{ 
    bool notFound = true;
    int pivot = array[start], i = start - 1, j = end + 1; 
  
    while(notFound) { 
        //Search leftmost greater than or equal to pivot
        do{i++;} 
        while(array[i] < pivot); 
  
        //Search rightmost smaller than or equal to pivot
        do{j--;}
        while(array[j] > pivot); 
  
        //Returns index of last element on smaller side if everything searched
        if(i >= j){
            notFound = false;
            return j; 
        }
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    } 
}

void quickSort(int array[], int start, int end) 
{ 
    if(start < end) {
        //Find pivot index
        int pivotIndex = partition(array, start, end); 
        //Sort left and right
        quickSort(array, start, pivotIndex); 
        quickSort(array, pivotIndex + 1, end); 
    } 
} 

int getSize(int array[]){
    int n = sizeof(array)/sizeof(array[0]);
    return n;
}
