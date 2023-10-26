#include <iostream>

using namespace std;

void selectionSort(int array[], int n)
{
    //Find min value
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(array[j] < array[min])
                min = j;
        }

        //Swap min with index of next min
        if(min != i){
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}

void printarray(int array[], int size)
{
    for(int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}
