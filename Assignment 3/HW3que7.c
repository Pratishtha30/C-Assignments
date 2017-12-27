#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int flip();

int main()
{

 unsigned int i; //loop counter
 int headCount=0;//total head count
 int tailCount=0;//total tail count

srand(time(NULL));

for(i=1; i<=100; i++) {

 if(flip()==0){
   ++tailCount;//update tail count
 }
else{
 ++headCount;//u[date head count
 }
if(i%10==0){
  puts("");
 }//end if
}//end for
//display result of totals
printf("\nTotal number of head was %d\n", headCount);

printf("\nTotal number of tail was %d\n", tailCount);
}//end main

//flip use random number to simulate coin toss
int flip()
{
 int HorT = rand()%2;//scale by 2 for binary result

//display result of flip
if(0==HorT)
{
 printf("%s", "Tails  ");
}//end if
else{
 printf("%s", "Heads  ");
 }//end else
return HorT;//return result of coin toss
}

 
