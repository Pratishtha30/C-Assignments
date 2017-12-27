/***********************************************************************/
/* University of California Extension, Santa Cruz */
/* */
/* C Programming For Beginners*/
/* */
/* Instructor: Bineet Sharma */
/* */
/* Author: Pratishtha Deep */
/* */
/* Assignment Number: 1-2.31 */
/**/
/* Objective:
Research several car-pooling websites. Create an application that calculates your daily driving cost, 
so that you can estimate how much money could be saved by car pooling, which also has other advantages 
such as reducing carbon emissions and reducing traffic congestion. The application should input the 
following information and display the users cost per day of driving to work:
a) Total miles driven per day.
b) Cost per gallon of gasoline.
c) Average miles per gallon.
d) Parking fees per day.
e) Tolls per day
*/
/****************************************************/

#include<stdio.h>

int main()
{

int total_miles; //total miles driven per day
int cost_gasoline;//cost per gallon of gasoline
int average_miles;//average miles per gallon
int parking_fees;//parking fees per day
int tolls_per_day;//tolls per day

printf("Enter the total miles driven per day\n");
scanf("%d", &total_miles);

printf("Enter the cost per gallon of gasoline\n");
scanf("%d", &cost_gasoline);

printf("Enter the average miles\n");
scanf("%d", &average_miles);

printf("Enter the parking fees\n");
scanf("%d", &parking_fees);

printf("Enter the tolls per day\n");
scanf("%d", &tolls_per_day);


int total_cost = tolls_per_day + parking_fees + (total_miles/average_miles)*cost_gasoline;

printf("Your daily cost of driving to work is %d\n", total_cost);


}//end main
