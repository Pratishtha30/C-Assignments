/***********************************************************************/
/* University of California Extension, Santa Cruz */
/* */
/* C Programming For Beginners*/
/* */
/* Instructor: Bineet Sharma */
/* */
/* Author: Pratishtha Deep */
/* */
/* Assignment Number: 2-4.23 */
/**/
/* Objective:
Calculating the Compound Interest with Integers.
*/
/****************************************************/

#include<stdio.h>
#include<math.h>
void main()
{

unsigned int year;//counter for year
unsigned int amount;//amount on deposit, in pennies
unsigned int dollars;//amount in dollars
unsigned int cents;//cents in amount
unsigned int principal = 100000;//principal in pennies
double rate =0.05;//interest rate

//display headers for table
printf("%s%21s\n", "Year", "Amount on Deposit");

//loop 10 times
for(year=1; year<=10; year++){
   
//determine new amount in pennies
amount = principal*pow(1.0+rate, year);
//determine cents portion of amount(last two digit)
cents = amount%100;
//determine dollar portion of amount
dollars = amount/100;

//display year, dollar portion followed by period
printf("%4u%18u.", year, dollars);

//display cents portion
//if cents is one digit inser zero
if(cents<10){
  printf("0%u\n", cents);
}
else {
printf("%u\n", cents); 
  }//end if
 }//end for
}//end main

