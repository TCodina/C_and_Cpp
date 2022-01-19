/*
6.19 (Dice Rolling)
Write a program that simulates the rolling of two dice. The program should
use rand twice to roll the first die and second die, respectively. The sum of the two values should
then be calculated. [Note: Because each die can show an integer value from 1 to 6, then the sum of
the two values will vary from 2 to 12, with 7 being the most frequent sum and 2 and 12 the least
frequent sums.] Your program should roll the two dice 36,000 times. Use a one-dimensional array to tally the numbers of times
each possible sum appears. Print the results in a tabular format. Also, determine if the totals are reasonable;
i.e., there are six ways to roll a 7, so approximately one-sixth of all the rolls should be 7.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11
#define ROLLS 3600

int main( void )
{
    int sumsCounter[SIZE] = {0};
    // expected values according to probabilities of getting the number.
    // For instance,  number seven should appear a 1 / 6 of the times we roll the dice
    int expectedValues[SIZE] = {ROLLS * 1.0 / 36, ROLLS * 2.0 / 36, ROLLS * 3.0 / 36,
                                ROLLS * 4.0 / 36, ROLLS * 5.0 / 36, ROLLS * 6.0 / 36,
                                ROLLS * 5.0 / 36, ROLLS * 4.0 / 36, ROLLS * 3.0 / 36,
                                ROLLS * 2.0 / 36, ROLLS * 1.0 / 36 };

    // dice rolling and count
    srand(time(NULL));
    for (unsigned int roll = 0; roll < ROLLS; roll++) {
        unsigned int sum =  (1 + rand() % 6) + (1 + rand() % 6); // this would be equivalent to the simpler form sum = 2 + rand() % 12
        sumsCounter[sum - 2]++;
    }

    // display result
    printf("%s%8s%20s\n", "Sum", "Count", "Expected Value");
    for (size_t i = 0; i < SIZE; i++) {
        printf("%3lu%8d%20d\n", i + 2, sumsCounter[i], expectedValues[i]);
    }
}
