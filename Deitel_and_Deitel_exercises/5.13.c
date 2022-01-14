/*

Exercise 5.13
Write statements that assign random integers to the variable n in the following ranges:
a) 1 ≤ n ≤ 6
b) 100 ≤ n ≤ 1000
c) 0 ≤ n ≤ 19
d) 1000 ≤ n ≤ 2222
e) –1 ≤ n ≤ 1
f) –3 ≤ n ≤ 11

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomInInterval( int, int );

int main( void )
{
    // random numbers between different intervals
    puts( "Random numbers between different intervals" );

    printf( "a) 1 <= n <= 6: %d\n", randomInInterval(1, 6));
    printf( "b) 100 <= n <= 1000: %d\n", randomInInterval(100, 1000));
    printf( "c) 0 <= n <= 19: %d\n", randomInInterval(0, 19));
    printf( "d) 1000 <= n <= 2222: %d\n", randomInInterval(1000, 2222));
    printf( "e) -1 <= n <= 1: %d\n", randomInInterval(-1, 1));
    printf( "f) -3 <= n <= 11: %d\n", randomInInterval(-3, 11));
}

// generate random integer between a and b
int randomInInterval( int a, int b )
{
    srand(time(NULL)); // seed taken from current time

    return a + rand() % ( b - a + 1);
}
