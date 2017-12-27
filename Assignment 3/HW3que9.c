#include<stdio.h>

int main(int argc, const char argv[])
{
 float fNums1;
 float fNums2;

printf("Please enter two float numbers separated by space and press enter:\n");

/*
scanf returns number of successful translation. 
If user inputs characters instead of numbers it will not return 2.
*/

while((scanf("%f %f", &fNums1,&fNums2)) != 2)
{

/*
If wrong input from user and there may be garbage characters inputted by the user,
delete each character until buffer is clear indicated by a newline
*/

 while(getchar()!='\n')
 continue;
 
printf("\n Error reading your input. Please try again.");
}
/*
you come here only when user enters two correct numbers (floats).
*/
printf("\nYou have entered %5.2f and %5.2f successfully\n", fNums1, fNums2);
return 0;
}

 


