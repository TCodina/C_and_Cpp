/*

Exercise 5.11 (Rounding Numbers):
Function floor may be used to round a number to a specific decimal place. The statement

y = floor(x * 10 + .5) / 10;

rounds x to the tenths position (the first position to the right of the decimal point).
The statement

y = floor(x * 100 + .5) / 100;

rounds x to the hundredths position (the second position to the right of the decimal point).
Write a program that defines four functions to round a number x in various ways

a) roundToInteger(number)
b) roundToTenths(number)
c) roundToHundreths(number)
d) roundToThousandths(number)

For each value read, your program should print the original value, the number rounded to the
nearest integer, the number rounded to the nearest tenth, the number rounded to the nearest hundredth,
and the number rounded to the nearest thousandth.

*/

#include <stdio.h>
#include <math.h>

int roundToInteger( double x );
double roundToTenths( double x );
double roundToHundreths( double x );
double roundToThousandths( double x );

int main( void )
{
    double x;

    // Read number to be rounded
    printf( "Insert a number to be rounded: " );
    scanf( "%lf", &x );

    // Print original number and its rounded values
    printf( "The original number is : %f\n", x );
    printf( "The number rounded to 0 decimal digits is : %d\n", roundToInteger(x));
    printf( "The number rounded to 1 decimal digit is : %f\n", roundToTenths(x));
    printf( "The number rounded to 2 decimal digits is : %f\n", roundToHundreths(x));
    printf( "The number rounded to 3 decimal digits is : %f\n", roundToThousandths(x));
}

int roundToInteger( double x )
{
    int y = floor( x + .5 );

    return y;
}

double roundToTenths( double x )
{
    double y = floor( 10 * x + .5 ) / 10;

    return y;
}

double roundToHundreths( double x )
{
    double y = floor( 100 * x + .5 ) / 100;

    return y;
}

double roundToThousandths( double x )
{
    double y = floor( 1000 * x + .5 ) / 1000;

    return y;
}
