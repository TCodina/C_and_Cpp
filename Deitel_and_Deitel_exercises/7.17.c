/*
7.17 (Simulation: The Tortoise and the Hare)
In this problem, you’ll recreate one of the truly great moments in history, namely the classic race of the tortoise and the hare.
You’ll use random number generation to develop a simulation of this memorable event.
Our contenders begin the race at “square 1” of 70 squares. Each square represents a possible position along the race course.
The finish line is at square 70. The first contender to reach or pass square 70 is rewarded with a pail of fresh carrots and lettuce.
The course weaves its way up the side of a slippery mountain, so occasionally the contenders lose ground.
There’s a clock that ticks once per second. With each tick of the clock, your program should adjust the position of the animals
according to the rules of Fig. 7.31. Use variables to keep track of the positions of the animals (i.e., position numbers are 1–70).
Start each animal at position 1 (i.e., the “starting gate”). If an animal slips left before square 1, move the animal back to square 1.
Generate the percentages in the preceding table by producing a random integer, i, in the range 1 ≤ i ≤ 10.
For the tortoise, perform a “fast plod” when 1 ≤ i ≤ 5, a “slip” when 6 ≤ i ≤ 7, or a “slow plod” when 8 ≤ i ≤ 10.
Use a similar technique to move the hare.
Begin the race by printing
BANG !!!!!
AND THEY'RE OFF !!!!!
Then, for each tick of the clock (i.e., each iteration of a loop), print a 70-position line showing the
letter T in the position of the tortoise and the letter H in the position of the hare. Occasionally, the
contenders will land on the same square. In this case, the tortoise bites the hare and your program
should print OUCH!!! beginning at that position. All print positions other than the T, the H, or the
OUCH!!! (in case of a tie) should be blank.
After each line is printed, test whether either animal has reached or passed square 70. If so,
then print the winner and terminate the simulation. If the tortoise wins, print TORTOISE WINS!!!
YAY!!! If the hare wins, print Hare wins. Yuch. If both animals win on the same tick of the clock,
you may want to favor the turtle (the “underdog”), or you may want to print It's a tie. If neither
animal wins, perform the loop again to simulate the next tick of the clock. When you’re ready to
run your program, assemble a group of fans to watch the race. You’ll be amazed at how involved
your audience gets!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // needed to use sleep

#define SIZE 50

void printTrack(size_t size, int posT, int posH);
void updatePositions(int *posTPtr, int *posHPtr);

int main(void)
{
    // initialize tortoise and hare position
    int positionT = 0, positionH = 0;

    // update the position of the animals and print the updated track after each second
    while (positionT <= SIZE - 1 && positionH <= SIZE - 1 ) {


        printTrack(SIZE, positionT, positionH);

        updatePositions(&positionT, &positionH);

        fflush(stdout); // these two lines make the program wait for 1 second befor continuing
        sleep(1);
    }

    // check winner
    if (positionT >= SIZE) {
        puts("TORTOISE WINS!!!, YAY!!!");
    }

    else {
        puts("Hare wins. Yuch.");
    }

}

// print the current status of the track taking into accoung tortise and hare positions
void printTrack(size_t size, int posT, int posH)
{
    // clear the current console
    system("clear");

    puts("BANG!!!!!\nAND THEY'RE OFF !!!!!\n");

    // print track with positions
    for (size_t i = 0; i < size; i++) {

        if ( i == posT && i == posH) {
            // the tortoise bites the hare
            printf("%21s\n", "OUCH!");
        }

        else if (i == posT) {

            printf("%19c\n", 'T');;
        }

        else if (i == posH) {

            printf("%19c\n", 'H');;
        }

        else {
            printf("%20s\n", "---");
        }
    }
}

// update positions of the tortoise and hare by randomly choosing differnet actions like fast plod, slip, small hop, etc
void updatePositions(int *posTPtr, int *posHPtr)
{
    // updates tortoise position
    srand(time(NULL));
    int randomT = 1 + rand() % 10;

    if (1 <= randomT && randomT <= 5) {
        // fast plod
        *posTPtr += 3;
    }

    else if (6 <= randomT && randomT <= 7) {
        // slip
        *posTPtr -= 6;
    }

    else {
        // slow plod
        *posTPtr += 1;
    }

    // updates hare position
    srand(2 * time(NULL));
    int randomH = 1 + rand() % 10;

    if ( 1 <= randomH && randomH <= 2) {
        // sleep
    }

    else if ( 3 <= randomH && randomH <= 4) {
        // big hop
        *posHPtr += 9;
    }

    else if ( randomH == 5) {
        // big slip
        *posHPtr -= 12;
    }

    else if ( 6 <= randomH && randomH <= 8) {
        // small hop
        *posHPtr += 1;
    }

    else {
        // small slip
        *posHPtr -= 2;
    }

    // if they slip off the track, we put them at the beginning again
    if (*posTPtr < 0) {
        *posTPtr = 0;
    }

    if (*posHPtr < 0) {
        *posHPtr = 0;
    }

}
