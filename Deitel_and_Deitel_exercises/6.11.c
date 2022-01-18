/*
6.10 (Selection Sort)
A selection sort algorithm for a one-dimensional array has the following steps:
a) The smallest value in the array is found.
b) It is swapped with the value in the first position of the array.
c) The above steps are repeated for the rest of the array starting at the second position and advancing each time.
Eventually the entire array is divided into two parts: the sub-array of items already sorted which is built up from left to right
and is found at the beginning, and the sub-array of items remaining to be sorted, occupying the remainder of the array.
Write a program that sorts an array of 10 integers using this algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void printArray(int a[], int size);

int main(void)
{
    int array[SIZE];

    // initialize array with random numbers
    srand(time(NULL)); // random seed from current time
    for (size_t i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    printf("Original array:\n");
    printArray(array, SIZE);

    // each iteration begins the searching problem from a higher position in the array
    for (unsigned int first = 0; first < SIZE - 1; first++) {

        // find the position of the smallest number in the reduced array
        size_t smallestPosition = SIZE - 1;
        for ( size_t i = first; i < SIZE; i++ ) {
            if ( array[i] < array[smallestPosition] ) {
                smallestPosition = i;
            }
        }

        // swap the smallest number with the one in the first position of the reduced array
        int holder = array[first];
        array[first] = array[smallestPosition];
        array[smallestPosition] = holder;

    }

    printf("Sorted array in ascending order:\n");
    printArray(array, SIZE);
}

void printArray(int a[], int size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d  ", a[i]);
    }

    puts("");
}
