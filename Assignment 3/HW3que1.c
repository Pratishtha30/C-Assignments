#include<stdio.h>
#include<math.h>

//function prototype
double calculateCharges( double hours);

void main ()
{
//number of hours for current car
double h;
//parking charge for current car
double current_charge;
//total charge for all cars
double total_charge = 0;
//total numbers of hours for all cars
double total_hours = 0.0;
//loop counter
unsigned int i;
//flag for printing table headers
int first = 1;

printf("%s", "Enter the hours parked for 3 hours: ");

//loop 3 times for 3 cars
for(i=1; i<=3; i++)
{
scanf("%lf", &h);

//add current hours to total hours
total_hours += h;

//if first time through loops display headers
if(first) {
  printf("%5s%15s%15s\n", "Car", "Hours", "Charge");
//set flag to false to prevent printing again
  first = 0;
}

//calcuate current car charge and update total
total_charge += ( current_charge = calculateCharges(h));

//display row data for current car
printf("%5d%15.1f%15.2f\n", i,h,current_charge);
}//end for

//display row data for total
printf("%5s%15.1f%15.2f\n", "TOTAL", total_hours, total_charge);
}//end main

//calculateCharges return charge according to number of hours
double calculateCharges( double hours)
{
//calculate charge
 double charge;
//for 3 hour charge is $2
 if(hours<3.0){
 charge = 2.00;
}
//$05. for each extra hour exceeding 3 hour limit
else if (hours<19.0)
{
 charge = 2.00 + 0.50*ceil(hours-3.0);
}
else { //maximum charge $10
  charge = 10.0;
 }
return charge;//return charge
}//end of function


