#include<stdio.h>

int ReverseDigits(int n);

int main()
{
 int number;
 printf("%s", "Enter a number between 1 and 9999: ");
 scanf("%d", &number);

//find numbers with its digit reversed
 printf("The number with its digit reversed is: %d\n", ReverseDigits(number));
}

//Function ReverseDigits returns number obtain by reversing digit of n
int ReverseDigits(int n)
{
 int reverse =0;//reversed number
 int part =0;//temp variable for storing reverse digits
 while(n >= 1) {
 part = n % 10;
 reverse = reverse*10 + part;
 n /= 10;
 }
return reverse;
}
 
