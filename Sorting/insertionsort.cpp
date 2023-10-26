#include <iostream>

using namespace std;

void insertionSort(int array[], int n)
{
    //Insert from arrayay 1 by 1
    for(int i=1; i<n; i++) {
        int next = array[i];
        int j = i - 1;
        //Compare values and swap if greater, else void auto-returns
        while(j>=0 && array[j]>next) {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = next;
    }
}

void printarray(int array[], int n)
{
    for(int i=0; i<n; i++)
        cout << array[i] << endl;
}