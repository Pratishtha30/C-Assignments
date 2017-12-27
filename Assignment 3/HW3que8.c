#include<stdio.h>

int main(int argc, const char*argv[])
{
/*
Function: main
Description: Displays the menu choice and goes in a loop to ask the user their choice. If they enter wrong choice gives
appropriate error message and asks the user to re-enter Once right choice is given, it returns that value to calling
function
input: not used
return: not used
*/

int nChoice=6;////initiatlize with an invalid choice

printf("Sorting Menu:\n\n\t1.Rank\n\t2.Title\n\t3.Date\n\t4.Stars\n\t5.Likes\n\n");

/*scanf returns number of successful translation. If user inputs characters instead of numbers it will not
return 1 as you are scanning one value.
*/

while(nChoice<1||nChoice>5)
{
 printf("Enter your choice b/w 1 and 5 only: ");

/*
there is wrong input from user and there may be garbage characters inputted by
user, eat it up until //input buffer is clear indicated by newline
*/

 while((scanf("%d", &nChoice)!=1))
 {
  while(getchar() != '\n')
  continue;
  printf("\nYou have entered an invalid choice");
 }
if(nChoice < 1 || nChoice > 5)
 {
 printf("You have not entered a number between 1 and 5. Try Again.\n");
 }
}
/*
if you come here, that means the choice given was correct.
*/
printf("\nYou entered a valid choice %d\n", nChoice);
printf("Thankyou for giving your choice\n");
}


 
