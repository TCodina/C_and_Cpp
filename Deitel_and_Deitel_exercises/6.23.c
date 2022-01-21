/*
6.23 (Turtle Graphics)
The Logo language made the concept of turtle graphics famous. Imagine a mechanical turtle that walks around the room
under the control of a C program. The turtle holds a pen in one of two positions, up or down. While the pen is down,
the turtle traces out shapes as it moves; while the pen is up, the turtle moves about freely without writing anything.
In this problem you’ll simulate the operation of the turtle and create a computerized sketchpad as well.
Use a 50-by-50 array floor which is initialized to zeros. Read commands from an array that contains them.
Keep track of the current turtle position at all times and whether the pen is currently up or down.
Assume that the turtle always starts at position 0, 0 of the floor with its pen up.
As the turtle moves with the pen down, set the appropriate elements of array floor to 1s. When the 6 command (print) is given,
wherever there’s a 1 in the array, display an asterisk, or some other character you choose. Wherever there’s a zero, display a blank.
Write a program to implement the turtle graphics capabilities discussed here. Write several turtle graphics programs to draw interesting shapes.
Add other commands to increase the power of your turtle graphics language.
*/

#include <stdio.h>
#define BOARD_SIZE 50

void printBoard(unsigned int a[][BOARD_SIZE]);
char changeOrientation(char orientation, int change);

int main( void )
{
    // intilize board with zeros everywhere
    unsigned int floor[BOARD_SIZE][BOARD_SIZE] = {{0}};

    // commands:
    //  1: pen up
    //  2: pen down
    //  3: turn right
    //  4: turn left
    //  5xx: move forward xx steps
    //  6: print board
    //  9: end of data (sentinel)
    unsigned int commands[] = {1, 535, 3, 515, 2, 510, 3, 520, 3, 510, 3, 520, 1, 6, 9}; // these commands draw a saquare in (almost) the middle of the board!

    size_t position[2] = {0}; // position (x,y) as a 2 dimensional array (initial position at (0,0))
    unsigned int penDown = 0; // 1 for Pen down and 0 for Pen up
    char currentOrientation = 'R'; // initial orientation set to right (also possible left (L), up (U) and down (D))
    unsigned int command = commands[0];

    // loop over the commands
    for (size_t i = 1; command != 9; i++) {

        // implement the movement
        if (command == 1) {
            // pen up
            penDown = 0;
        }

        else if (command == 2) {
            // pen down
            penDown = 1;
        }

        else if (command == 3) {
            // turn right
            currentOrientation = changeOrientation(currentOrientation, 1);
        }

        else if (command == 4) {
            // turn left
            currentOrientation = changeOrientation(currentOrientation, 0);
        }

        else if (command == 6) {
            // print current board
            printBoard(floor);
        }

        else if (command / 10 == 5 || command / 100 == 5) {
            // move straightforward the amount given by movement, the amount of steps calculated with
            // % 10 if it moves a single digit, % 100 if it moves two digits
            unsigned int movement = command / 10 == 5 ? command % 10 : command % 100;

            // move in different directions depending on orientation and draw if pen is down
            switch (currentOrientation) {

                case 'R':

                    if (penDown) {
                        for (size_t step = 0; step <= movement; step++) {
                            floor[position[0]][position[1] + step] = 1;
                        }
                    }
                    position[1] += movement;
                    break;

                case 'D':

                    if (penDown) {
                        for (size_t step = 0; step <= movement; step++) {
                            floor[position[0] + step][position[1]] = 1;
                        }
                    }
                    position[0] += movement;
                    break;

                case 'L':

                    if (penDown) {
                        for (size_t step = 0; step <= movement; step++) {
                            floor[position[0]][position[1] - step] = 1;
                        }
                    }
                    position[1] -= movement;
                    break;

                case 'U':
                    if (penDown) {
                        for (size_t step = 0; step <= movement; step++) {
                            floor[position[0] - step][position[1]] = 1;
                        }
                    }
                    position[0] -= movement;
                    break;
            }
        }

        else {
            printf("Invalid command! Program terminated.\n");
            break; // automatically terminates loop
        }

        // check that the agent is among the boundaries of the board
        if ( 0 <= position[0] && position[0] <= BOARD_SIZE && 0 <= position[1] && position[1] <= BOARD_SIZE) {
            command = commands[i]; // change to next command
        }
        else {
            printf("Out of board! Program terminated.\n");
            break; // automatically terminates loop
        }
    }
}

// Loops over the whole board printing a "*" if there is a 1 and an empty space otherwiese
void printBoard(unsigned int a[][BOARD_SIZE])
{
    // just a pretty line on top of the board
    printf(" ");
    for (size_t i = 0; i < BOARD_SIZE + 2; i++) {
        printf("-");
    }
    puts("");

    for (size_t i = 0; i < BOARD_SIZE; i++) {

        printf("| "); // left border

        for (size_t j = 0; j < BOARD_SIZE; j++) {
            a[i][j] == 1 ? printf("*") : printf(" ");
        }

        printf(" |\n"); // right border and new line after each row
    }

    // the same pretty line on the bottom
    printf(" ");
    for (size_t i = 0; i < BOARD_SIZE + 2; i++) {
        printf("-");
    }
}

// Change orientation of the agent (change = 1 for turn right, otherwise turn left)
char changeOrientation(char orientation, int change)
{
    char newOrientation;
    // if turn right
    if (change) {
        switch (orientation) {
            case 'R':
                newOrientation = 'D';
                break;
            case 'D':
                newOrientation = 'L';
                break;
            case 'L':
                newOrientation = 'U';
                break;
            case 'U':
                newOrientation = 'R';
                break;
        }
    }
    // if turn left
    else {
        switch (orientation) {
            case 'R':
                newOrientation = 'U';
                break;
            case 'U':
                newOrientation = 'L';
                break;
            case 'L':
                newOrientation = 'D';
                break;
            case 'D':
                newOrientation = 'R';
                break;
        }
    }

    return newOrientation;
}
