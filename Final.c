#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#include<ctype.h>


#define Max_Students 100
#define Max_Components 7 
#define String_Size 255
#define Max_NameSize 30

// Boolean value type.
typedef int bool;
#define true 1
#define false 0

// Structure representing one student.
typedef struct {
  char name[Max_NameSize];  
  char letterGrade;
  int score[Max_Components];
} Student;


int LoadStudents(FILE *iFilePointer, Student student_record[Max_Students]);
void CalculateGrades(Student student_record[Max_Students],int numstudent);
void CalculateAverages(Student student_record[Max_Students], int numstudent);
void CalculateMinimums(Student student_record[Max_Students], int numstudent);
void CalculateMaximums(Student student_record[Max_Students], int numstudent);
void Sort(Student student_record[Max_Students],int numstudent);
void WriteGrades(Student student_record[Max_Students],int numstudent,FILE *oFilePointer);

/*
 * Description:
 * In the main function, input and output file are taken using command line arguments. 
 * Functions are called for each calculation, sorting student by name and finally writing output file.
*/

int main(int argc, char *argv[])//main function with command line arguments
{
//file pointers for input & output files
FILE *iFilePointer, *oFilePointer;

// Array with each element for one student.
Student student_record[Max_Students];

if (argc != 3) // Validate that argument count is equal to 3.
{
printf("Usage: %s inputFileName outputFileName\n", argv[0]);
exit(1);
}
else
{
printf("%s: %s \n%s: %s\n","Input will be read from",argv[1],"Output will be written into",argv[2]);
}
printf("\n\n");

// Open the file.
if ((iFilePointer = fopen(argv[1], "r")) == NULL) {
printf("An error has been generated while attempting to open the input file %s\n", argv[1]);
exit(1);
}

// Validate that output file can be opened in 'write' mode
else if ((oFilePointer = fopen(argv[2], "w")) == NULL) {
printf("An error has been generated while attempting to open the output file %s\n", argv[2]);
//Make sure to close the previously opened file before exitting.
fclose(iFilePointer);
exit(1);
}

int numstudent= LoadStudents(iFilePointer, student_record);// read file line by line and divide into tokens 
CalculateGrades(student_record, numstudent);//calcuating the grades of each student
CalculateAverages(student_record, numstudent);//calculating avergae of each quiz, mideterm and final
CalculateMinimums(student_record,  numstudent);//calculating minimum of each quiz, mideterm and final
CalculateMaximums(student_record,  numstudent);//calculating maximum of each quiz, mideterm and final
Sort(student_record, numstudent);// sorting student by their names
WriteGrades(student_record, numstudent, oFilePointer);//writing grade in output file

// Close files.
fclose(iFilePointer);
fclose(oFilePointer);

char enter_unused;
printf("\nPlease enter key to continue..\n");
scanf("%c",&enter_unused);
return 0;
}// end of main


/*
 * Description:
 * Input file is read line by line and divided into tokens by using strtok.
 * Name and scores of students, Score of students is stored in 'name' and 'score' fields of each element in array.
 * Checking invalid input conditions 
 * It returns current count of students.
*/

int LoadStudents(FILE *iFilePointer, Student student_record[Max_Students])
{
  char line[100];  
  char *token;  
  int i,j, student_index=0;
  while (fgets(line, sizeof(line), iFilePointer) != NULL)
    {
     int len = strlen(line);
     if (len <(2*Max_Components+1))//Min characters possible in a line.In this problem, Max_Components separated by comma therefore twice of Max_Components and one for the Student name.  
        {
	printf("Skipping unformated line %s\n",line);
	continue;
         }

     token = strtok(line, ",");  
     if(strlen(token)>30)
	 {
         printf("Skipping the  name %s as its size is  more than buffer[Max_NameSize]\n", token);
	 continue;
	 }
     
     strcpy(student_record[student_index].name, token);
     bool skipthisStudent=true;
     for (i = 0; i < Max_Components; i++)     
        { 
         token = strtok(NULL, ",");   
	 if(token==NULL)
         {
         //for the case where less components are provided for a student in input file
         printf("Skipping student %s as its components are less than the required components[Max_Components]\n",student_record[student_index].name);
         skipthisStudent=false;
	 break;
	 }
	 student_record[student_index].score[i] = atoi(token);
	}

     if (!skipthisStudent) continue;

     // Check if any token is still left unprocessed.
    //for the case where more components are provided for a student in input file
    //Not skipping student just skipping extra tokens

     while ((token = strtok(NULL, ",")) != NULL)
         {
          printf("Extra token found for %s : %s, skipping this extra token.\n", student_record[student_index].name, token);
         }

     student_index++;
    }
fclose(iFilePointer);
printf("total no student %d\n", student_index);
return student_index; // = current count of students
}

/*
 * Description:
 * Takes in array of structure student (with score[] array filled) and count of students.
 * Grade is calculated by using finalscore weighted formula given in problem statement, and
*/

void CalculateGrades(Student student_record[Max_Students], int numstudent) {
  int student_index=0, component_index=0;
  float FinalScore;
  for (student_index=0; student_index<numstudent;student_index++) {
    FinalScore =student_record[student_index].score[0]*.10 +student_record[student_index].score[1]*.10 + student_record[student_index].score[2]*.10 + student_record[student_index].score[3]*.10 + student_record[student_index].score[4]*.20 + student_record[student_index].score[5]*.15 + student_record[student_index].score[6]*.25;
    if(FinalScore>=90) student_record[student_index].letterGrade = 'A';
    else if(FinalScore>=80 && FinalScore <90) student_record[student_index].letterGrade ='B';
    else if(FinalScore>=70 && FinalScore <80) student_record[student_index].letterGrade='C';
    else if(FinalScore>=60 && FinalScore <70) student_record[student_index].letterGrade='D';
    else if(FinalScore>=0  && FinalScore <60) student_record[student_index].letterGrade='F';
  }
}

/*
 * Description:
 * Takes in array of structure student (with score[] array filled) and count of students.
 * Average for each component (four quizzes, two midterm and one final) is calculated by dividing total by number of students, and printed on stdout.
*/
void CalculateAverages(Student student_record[Max_Students], int numstudent)
{
int Q1, Q2, Q3, Q4, MidI, MidII, Final, j, student_index;
double total=0;
float Avg;
printf("Here is the class averages: \n");
printf("\t\tQ1\tQ2\tQ3\tQ4\tMidI\tMidII\tFinal\n");
printf("Average:");
for (j=0;j<Max_Components;j++)
{
  for(student_index=0;student_index<numstudent;student_index++)
     {
      total+=student_record[student_index].score[j];       
     }
  Avg=total/numstudent;
  printf("\t%.2f",Avg );
  total=0;
}
printf("\n");
}

/*
 * Description:
 * Takes in array of structure student (with score[] array filled) and count of students.
 * Minimum for each component (four quizzes, two midterm and one final) is calculated and printed on stdout.
 */
void CalculateMinimums(Student student_record[Max_Students], int numstudent){
float min=-1;
int j, student_index=0;
printf("MIN:\t");
for (j=0;j<Max_Components;j++)
  {
   for (student_index=0;student_index<numstudent;student_index++)
     {
      if (min == -1 ||student_record[student_index].score[j] < min)
	 min =student_record[student_index].score[j];
     }
   printf("\t%.2f",min );
   min=-1; // reset min for next component.
  }
printf("\n");
}

/*
 * Description:
 * Takes in array of structure student (with score[] array filled) and count of students.
 * Maximum for each component (four quizzes, two midterm and one final) is calculated and printed on stdout.
 */
void CalculateMaximums(Student student_record[Max_Students], int numstudent){
float max=-1;
int j, student_index=0;
printf("MAX:\t");
for (j=0;j<Max_Components;j++)
   {
    for(student_index=0;student_index<numstudent;student_index++)
       {
        if (max == -1 ||student_record[student_index].score[j] > max)
	            max =student_record[student_index].score[j];
       }
    printf("\t%.2f",max );     
    max=-1;
   }
printf("\n");
}

/*
 * Description:
 * Takes in array of structure student and count of students, and sorts the elements by using 'name' field lexographically using bubble sort.
 */
void Sort(Student student_record[Max_Students],int numstudent)
{
  int student_index = 0,j = 0;
  Student temp;	    
  for (student_index = 0; student_index <= numstudent - 1; student_index++)
      {
        for (j = student_index + 1; j < numstudent; j++)                					
  	{ 
	  if (strcmp(student_record[student_index].name,student_record[j].name) > 0)	
	  {						                
           temp = student_record[student_index];	
	   student_record[student_index] = student_record[j];	
	   student_record[j] = temp;		
	  }      
    	}	 
      }
}	    

/*
 * Description:
 * Takes in array of structure student and count of students.
 * Writes name and letter grades of students in outputfile in their order of appearance in array.
 */
void WriteGrades(Student student_record[Max_Students],int numstudent, FILE *oFilePointer)
{
  int student_index=0;
  for(student_index=0;student_index<numstudent;student_index++)
  {
   fprintf(oFilePointer, "%-10s:\t%5c\n", student_record[student_index].name, student_record[student_index].letterGrade);	
  }
}
