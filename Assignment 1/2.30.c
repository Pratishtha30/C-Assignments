/***********************************************************************/
/* University of California Extension, Santa Cruz */
/* */
/* C Programming For Beginners*/
/* */
/* Instructor: Bineet Sharma */
/* */
/* Author: Pratishtha Deep */
/* */
/* Assignment Number: 1-2.30 */
/**/
/* Objective:
Write a program that inputs one five-digit number separates the number into its individual digits
and prints the digits separated from one another by three spaces each.
*/
/****************************************************/

#include<stdio.h>

int main()
{

int number;
int temp;

//prompt user
printf("%s", "Enter a 5 digit number: ");

//read number
scanf("%d", &number);

//print leftmost digit
printf("%d ", number/10000);
temp = number % 10000;

printf(" %d ", temp/1000);
temp = temp % 1000;

printf(" %d ", temp/100);
temp = temp % 100;

printf(" %d ", temp/10);
temp = temp % 10;

//print rightmost digit
printf(" %d\n", temp );

}//end main
