/***********************************************************************/
/* University of California Extension, Santa Cruz */
/* */
/* C Programming For Beginners*/
/* */
/* Instructor: Bineet Sharma */
/* */
/* Author: Pratishtha Deep */
/* */
/* Assignment Number: 2-4.11 */
/**/
/* Objective:
Write a program that finds the smallest of several integers.
Assume that the first value read specifies the number of values remaining.
*/
/****************************************************/

#include<stdio.h>

void main()
{
int total_num;//total number of integers to be processed
int first_integer;//first integer given by user
int next_integer;// next integer provided by user
unsigned int i;
int smallest =0;

//propt user to enter the total number of values to be processed
printf("Enter the total number of integer to be processed:\n");
scanf("%d", &total_num);

//prompt user to enter the first value
printf("Enter the first integer:\n");
scanf("%d", &first_integer);

//considering first value as the smallest value
smallest = first_integer;

//for loop to check the smallest value from the total number of values given by the user
for(i=2; i<=total_num; i++){

//prompt user to give next value
printf("Enter the next integer:\n");
scanf("%d", &next_integer);

//condition to check the smallest value
if(next_integer < first_integer){

smallest = next_integer;

}

}

//Display results
printf("The smallest integer is %d \n", smallest);

}//end main

