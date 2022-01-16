/*
Exercise 5.25 (Find the Maximum)
Write a function that returns the largest of four floating-point numbers.
*/

#include <stdio.h>

float maxNumber( float, float, float, float );

int main( void )
{
    float a, b, c, d;

    printf( "Enter 4 float numbers: " );
    scanf( "%f %f %f %f", &a, &b, &c, &d );

    printf( "The maximum number among them is: %f", maxNumber( a, b, c, d ) );

}

float maxNumber( float a, float b, float c, float d )
{
    // check if a is the biggest
    if ( a >= b && a >= c && a >= d ) {
        return a;
    }

    // check if b is the biggest
    else if ( b >= a && b >= c && b >= d ) {
        return b;
    }

    // check if c is the biggest
    else if ( c >= a && c >= b && c >= d ) {
        return c;
    }

    // if non of the above, then the biggest is d
    else {
        return d;
    }
}
