/***********************************************************************/
/* University of California Extension, Santa Cruz */
/* */
/* C Programming For Beginners*/
/* */
/* Instructor: Bineet Sharma */
/* */
/* Author: Pratishtha Deep */
/* */
/* Assignment Number: 2-4.9 */
/**/
/* Objective:
Write a program that sums a sequence of integers.
Assume that the first integer read with scanf specifies the number of values remaining to
be entered. Your program should read only one value each time scanf is executed.
*/
/****************************************************/

#include<stdio.h>

void main()
{

int num_of_value;// number of values given by user
int value, i;
int total = 0;// current sum of nubers

printf("Enter the number of values to be processed\n");
scanf("%d", &num_of_value);

for(i=0; i< num_of_value; i++){
printf("Enter the value\n");
scanf("%d", &value);

total += value;
}

printf("Sum of %d value is %d\n", num_of_value, total);

}//end main

