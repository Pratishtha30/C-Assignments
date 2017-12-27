#include<stdio.h>

int even(int a);

int main()
{
int x; //current input

unsigned int i; //loop counter

for(i=1; i<=3; i++)
{
 printf("%s", "Enter an integer: ");
 scanf("%d", &x);

//determine if input is even
if(even(x)) {
  printf("%d is an even integer\n\n", x);
 
}

else {
printf("%d is not an even integer\n\n", x);
  }
 }//end for
}//end main

//even return true if a is even 
int even(int a)
{
 return !(a%2);
}


