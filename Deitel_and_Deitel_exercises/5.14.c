/*
Exercise 5.14
For each of the following sets of integers, write a single statement that will print a number at random from the set.
a) 3, 6, 9, 12, 15, 18, 21, 24, 27, 30.
b) 3, 5, 7, 9, 11, 13, 15, 17, 19.
c) 3, 8, 13, 18, 23, 28, 33
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
    srand(time(NULL));  // seed taken from current time

    printf( "Random number in the set {3, 6, 9, 12, 15, 18, 21, 24, 27, 30}: %d\n", (1 + rand() % 10 ) * 3 );
    printf( "Random number in the set {3, 5, 7, 9, 11, 13, 15, 17, 19}: %d\n", (1 + rand() % 9 ) * 2 + 1 );
    printf( "Random number in the set {3, 8, 13, 18, 23, 28, 33}: %d\n", (1 + rand() % 7 ) * 5 - 2 );
}
