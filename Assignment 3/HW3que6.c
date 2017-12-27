#include<stdio.h>
int QualityPoints(int average);

int main()
{
 int average;//current average
 int i;//loop counter
 
//loop for 5 inputs
for(i=0; i<5; i++){

 printf("%s", "\nEnter the students average: ");

 scanf("%d", &average);
//deterine and display corresponding quality points
 printf("%d on a 4 point scale is %d\n", average, QualityPoints(average));
 }//end for
}//end main

//Function QualityPoints take averge in range from 0 to 100
//return corresponding quality points on a scale of 0 to 4
int QualityPoints(int average)
{
 if (average >= 90){
 return 4;
 }
 if(average >=80){
 return 3;
 }
 if(average >=70){
 return 2;
 }
 if(average >=60){
 return 1;
 }
else
 return 0;
}
