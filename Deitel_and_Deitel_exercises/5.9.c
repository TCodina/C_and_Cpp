/* 

Exercise 5.9 (Car Rental Services):

A car rental service charges a minimum fee of $25.00 to rent a car for 8 hours, and charges an additional $5 per hour after 8 hours. 
The maximum charge per day is $50 exclusive of service tax. The company charges an additional $0.50 per hour as service tax. 
Assume that no car is rented for more than 72 hours at a time. If a car is rented for more than 24 hours, 
then rental is calculated on a daily basis. Write a program that calculates and prints the rental charges 
for each of three customers who rented cars from this agency yesterday. You should enter the hours for which the car has been rented for each customer. 
Your program should print the results in a neat tabular format and should calculate and print the total of yesterday’s receipts. 
The program should use the function calculateCharges to determine the charges for each customer. 
Your outputs should appear in the following format:

Car 	Hours 	Charge
1 	12 	56.00
2 	34 	117.00
3 	48 	124.00
TOTAL 	94 	297.00

*/

#include <stdio.h>
#define CUSTOMERS 6

double calculateCharges(int hours);

int main( void )
{
    int hourCars[CUSTOMERS] = {2, 8, 9, 24, 50, 58};
    int totalHours = 0;
    double totalCharge = 0.00;

    printf( "%3s\t\t%s\t\t%s\n", "Car", "Hours", "Charge" );

    for (unsigned int car = 1; car <= CUSTOMERS; car++) {

        printf( "%-3u\t\t%3d\t\t%6.2f\n", car, hourCars[car - 1], calculateCharges(hourCars[car - 1]) );
        totalHours += hourCars[car - 1];
        totalCharge += calculateCharges(hourCars[car - 1]);
    }
    printf( "--------------------------------------\n" );
    printf( "%3s\t\t%d\t\t%.2f\n", "TOTAL", totalHours, totalCharge );

}

double calculateCharges(int hours)
{
    int days = hours / 24;
    double charge = 50 * days; // 50 for each day
    int effectiveHours = hours - (24 * days); // hours of the last day

    if ( (effectiveHours > 0) && (effectiveHours <= 8) ) {

        charge += 25; // just the initial fee
    }

    if ( effectiveHours > 8 ){

        double LastDayCharge = 5 * effectiveHours;

        (LastDayCharge < 50)? (charge += LastDayCharge) : (charge += 50);

    }

    charge += hours * .5; // add taxes

    return charge;

}
