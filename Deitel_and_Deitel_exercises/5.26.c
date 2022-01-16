/*
Exercise 5.26 (Perfect Numbers)
An integer number is said to be a perfect number if its factors, including 1 (but not the number itself),
sum to the number. For example, 6 is a perfect number because 6 = 1 + 2 + 3.
Write a function isPerfect that determines whether parameter number is a perfect number.
Use this function in a program that determines and prints all the perfect numbers between 1 and 1000.
Print the factors of each perfect number to confirm that the number is indeed perfect.
Challenge the power of your computer by testing numbers much larger than 1000.
*/

#include <stdio.h>
#define MAX_NUMBER 100000

int isPerfect( unsigned int );

int main( void )
{
    printf( "---- Perfect numbers between 1 and %d ----\n\n", MAX_NUMBER );

    for (unsigned int number = 1; number <= MAX_NUMBER; number++) {

        if ( isPerfect( number ) ) {
            printf( "%d\n", number );
        }
    }
}

int isPerfect( unsigned int x )
{
    unsigned int factorsSum = 0;

    for ( unsigned int num = 1; num < x; num++ ) {
        if ( x % num == 0) {
            factorsSum += num;
        }
    }

    return factorsSum ==  x ? 1 : 0;
}
