/***********************************************************************/
/* University of California Extension, Santa Cruz */
/* */
/* C Programming For Beginners*/
/* */
/* Instructor: Bineet Sharma */
/* */
/* Author: Pratishtha Deep */
/* */
/* Assignment Number: 2-4.14 */
/**/
/* Objective:
Factorials: The factorial function is used frequently in probability problems. The
factorial of a positive integer n (written n! and pronounced n factorial) is equal to the
product of the positive integers from 1 to n. Write a program that evaluates the factorials
of the integers from 1 to 5. Print the results in tabular format. What difficulty might
prevent you from calculating the factorial of 20?
*/
/****************************************************/

#include<stdio.h>

void main()
{
unsigned int i, j;
unsigned int factorial;

//Display the table
puts("X\tFactorial of X");

for(i=1; i<=5; i++){
 
 factorial = 1;

for(j=1; j<=i; j++){
 
factorial *=j;

}//end inner for

printf("%u\t%u\n", i, factorial);

}//end outer for

}//end main

