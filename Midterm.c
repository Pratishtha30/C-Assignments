//computing for Pratishtha handy calculator
#include<stdio.h>
#include<stdlib.h>

void flush();//fucntion to clean buffer
void add (float, float);//function for addition
void sub (float, float);//function for subtraction
void mul (float, float);//function for multiplication
void divi (float, float);//function for divison
void invalid();//function for invalid entries
//function main begin program execution
int main(int argc, const char*argv[])
{

int choice=6;//initiatlize with an invalid choice
while(1)
{
printf("Welcome to Pratishtha Handy Caluclator\n");
printf("1. Addition\n");
printf("2. Subtraction\n");
printf("3. Multiplication\n");
printf("4. Division\n");
printf("5. Exit\n\n");

float x,y;//variables for two numbers given by user for calculation
int flag;//assigning for scanf 
char garb;//for garbage input check

printf("What would you like to do\n");//Input by user for menu choice
flag = scanf("%d%c", &choice, &garb);
//scanf returns number of successful translation. If user
//inputs characters instead of numbers it will not return 1
//as you are scanning one value. This is the way to trap
//wrong user input

while (flag!=2 || garb!='\n')
{
printf("\n");
flush();
//you come here when there is wrong input from user
//and there may be garbage characters inputted by
//user, eat it up until
//input buffer is clear indicated by newline
printf("This is not a valid choice please re-enter: ");
flag = scanf("%d%c", &choice, &garb);
}

while(choice>5||choice<1)
{
printf("You have not entered a number between 1 and 5. re-enter: ");
flag = scanf("%d%c", &choice, &garb);
}


 switch(choice) {

        case 1://when you choose the option 1
        printf("Enter two valid number to add separated by space :");
        flag=scanf("%f %f", &x,&y);
        while(flag!=2){
        invalid();//for invalid entry
        flag=scanf("%f %f", &x,&y);
        }
        add(x,y);
        flush();//clear the buffer
        break;
      
        case 2://when you choose the option 2
        printf("Enter two valid number to subtract separated by space :");
        flag=scanf("%f %f", &x,&y);
        while(flag!=2){
        invalid();//for invalid entry
        flag=scanf("%f %f", &x,&y);
        }
        sub(x,y);
        flush();//clear the buffer
        break;
  
        case 3://when you choose the option 3
        printf("Enter two valid number to multiply separated by space :");
        flag=scanf("%f %f", &x,&y);
        while(flag!=2){
        invalid();//for invalid entry
        flag=scanf("%f %f", &x,&y);
        }
        mul(x,y);
        flush();//clear the buffer
        break;

        case 4://when you choose the option 4
        printf("Enter two valid number to divide separated by space :");
        flag=scanf("%f %f", &x,&y);
        while(flag!=2 || y==0){//for invalid entry
        while(flag!=2){
        invalid();
        flag=scanf("%f %f", &x,&y);
        }        
        if(y==0){
        printf("You can't divide by zero, please re-enter both numbers: ");
        flag=scanf("%f %f", &x,&y);
        }
        } 
        divi(x,y);
        flush();//clear the buffer
        break; 

        case 5 ://when you choose the option 5
        printf("\nThank you for using Pratishtha Handy Calculator\n");
        exit(0);
        }//end for switch

char enter;//At the end of the result, it gives a prompt
printf("\nPlease enter key to continue..\n");
scanf("%c",&enter);//displays menu again
}//end for while(1)

return 0;
}//end for main
void invalid( )
      {
      printf("\n");
      flush();
      printf("Error reading your numbers, please re-enter both numbers: ");
      }
void flush()
      {
      while (getchar()!='\n')
      continue;
      }

void add(float x,float y)
      {
      float result = x + y;
      printf("Result of adding %.2f and %.2f is %.2f\n",x,y,result);
      }

void sub(float x,float y)
      {
      float result = x - y;
      printf("Result of subtracting %.2f by %.2f is %.2f\n",x,y,result);
      }

void mul(float x,float y)
      {
      float result = x*y;
      printf("Result of multiplying %.2f and %.2f is %.2f\n",x,y,result);
      }

void divi(float x, float y)
      {
      float result = x/y;
      printf("Result of dividing %.2f by %.2f is %.2f\n",x,y,result);
      }



