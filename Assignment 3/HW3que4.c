#include<stdio.h>
#include<math.h>

int prime(int n);

int main()
{
 int j;//loop counter
 int count =0;// total number of prime found

 puts("The prime number from 1 to 10000 are:");

 for(j=1; j<=10000; j++)
 {
 if(prime(j)){

 ++count;

 printf("%5d", j);

   if(count%10==0){
   puts("");
   }//end inner if
  }//end outer if
 }//end for 
}//end main

//function prime return 1 if n is prime
int prime(int n)
{
 int i;

 for(i=2; i<=(int)sqrt(n); i++){
  if(n % i == 0){
  return 0;
  }
}
return 1;
}

