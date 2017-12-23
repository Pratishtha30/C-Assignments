/***********************************************************************/
/* University of California Extension, Santa Cruz */
/* */
/* C Programming For Beginners*/
/* */
/* Instructor: Bineet Sharma */
/* */
/* Author: Pratishtha Deep */
/* */
/* Assignment Number: 2-3.32 */
/**/
/* Objective:
Write a program that reads in the side of a square and then prints that square out of
aster-isks. Your program should work for squares of all side sizes between 1 and 20.
*/
/****************************************************/

#include<stdio.h>

void main()
{

int square_side;
int row_number=1;
int asterisk;

//prompt user to give side of the square
printf("Enter the number of sides of square\n");
scanf("%d", &square_side);

//loop for row of the square
while(row_number < square_side){
  asterisk = square_side;

//loop for coloumn of the square
 while(asterisk > 0){
   printf("%s", "*");
   --asterisk;
   }//end inner while
puts("");
++row_number;
}//end outer while

}//end main

