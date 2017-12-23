/***********************************************************************/
/* University of California Extension, Santa Cruz */
/* */
/* C Programming For Beginners*/
/* */
/* Instructor: Bineet Sharma */
/* */
/* Author: Pratishtha Deep */
/* */
/* Assignment Number: 2-3.26 */
/**/
/* Objective:
Using an approach similar to Exercise 3.23, find
the two largest values of the 10 numbers.
*/
/****************************************************/

#include<stdio.h>

int main()
{

int largest;// largets number from user inputs
int second_largest=0;// second largest number from the user inputs
int number;//current number from user input
int count;// counter for 9 times

printf("Enter the first number\n");
scanf("%d", &largest);

count = 2;

//loop for 9 times
while(count<=9)
{
  printf("Enter the next number\n");
  scanf("%d", &number);

//if current number is greater than largest

  if(number > largest)
    {
     second_largest = largest;
     largest = number;
    }
  else{
//if current number is in between largest and second largest
    if(number > second_largest)
      {
       second_largest = number;
      }
  }//end else
++count;
}//end while
printf("The Largest number is %d.\n", largest);
printf("The Second Largest number is %d.\n", second_largest);

}//end main
