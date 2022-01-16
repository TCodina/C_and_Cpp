/*
Exercise 5.22 (Separating Digits):
Write program segments that accomplish each of the following:
a) Calculate the integer part of the quotient when integer a is divided by integer b.
b) Calculate the integer remainder when integer a is divided by integer b.
c) Use the program pieces developed in a) and b) to write a function that inputs an integer
between 1 and 32767 and prints it as a series of digits,with two spaces between each digit.
For example, the integer 4562 should be printed as: 4  5  6  2
*/

#include <stdio.h>

void splitDigits( unsigned int );

int main( void )
{
    unsigned int number;

    printf( "Insert a positive integer: " );
    scanf( "%d", &number );

    printf( "Your number split in digits is:\n " );
    splitDigits( number );
}

void splitDigits( unsigned int x )
{
    // each iteration in while removes a digit from x
    while ( x > 10) {

        int multiplier = 10;

        while ( x / multiplier > 10) {
            multiplier *= 10;
        }

        printf( "%d  ", x / multiplier ); // this quotient gives the leftmost digit of x

        x %= multiplier; // updates x removing its leftmost digit
    }

    printf( "%d  ", x % 10 ); // the last digit is printed appart
}

