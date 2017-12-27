#include<stdio.h>
#include<math.h>

int seconds( int hour, int minutes, int seconds);

int main()
{
 int hours;//current time in hours
 int minutes;//current time in minutes
 int secs;//current time in seconds
 int first;//first time, in seconds
 int second;//second time, in seconds
 int difference;//difference of both the times

printf("%s", "Enter 3 intergers for first time: ");
scanf("%d, %d, %d", &hours, &minutes, &secs);

//calculate first time in seconds
first = seconds(hours, minutes, secs);

printf("%s", "Enter 3 integers for second time: ");
scanf("%d, %d, %d", &hours, &minutes, &secs);

//calculate second time in seconds
second = seconds(hours, minutes, secs);

//calculate difference 
difference = fabs(first - second);

printf("The difference between the time is %d seconds\n", difference);

}//end main

//function seconds return number of seconds since clock "struck 12"
//given input time as h is hours, m is minutes and s is seconds
int seconds(int h, int m, int s)
{
 return 3600*h + 60*m + s;
}
