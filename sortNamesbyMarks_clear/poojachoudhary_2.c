/* Program to read the input file and do the following operations:-
	1) sort names and marks in decending order of marks
	2) average score of class
	
	input: input file
	output: output file
*/

#include"stdio.h"
#include"string.h"
#include <stdlib.h>

#define MAX 100

/* Functions declearation */
int decendingSortMarks(const char*);

typedef struct student{
char name[MAX];
int marks;
}STUDENT;

int printStudents(STUDENT *students[],int count){
     
        for(int index=0;index<count;index++){
                printf("VALUES %d> %s %d\n",index,students[index]->name,students[index]->marks);
        }

        return 0;
}

int swap(STUDENT *node_one,STUDENT *node_two){

	STUDENT *temp=(STUDENT *)malloc(sizeof(STUDENT));

	strcpy(temp->name,node_one->name);
	temp->marks=node_one->marks;

	strcpy(node_one->name,node_two->name);
	node_one->marks=node_two->marks;

	strcpy(node_two->name,temp->name);
	node_two->marks=temp->marks;
	
	return 0;
}

int sortByMarks(STUDENT *students[],int count){
	
	for(int index=0;index<count;index++){
		for(int index2=0;index2<count-1;index2++){
			if(students[index2]->marks <= students[index2+1]->marks){
				swap(students[index2],students[index2+1]);
			}
		}		
	}
	
	return 0;
}

int avgScore(STUDENT *students[],int count){
	
	int sum=0;
	float avg=0.0;
	for(int index=0;index<count;index++){
		sum=sum+students[index]->marks;
	}

	avg=sum/count;

	return avg;
}

/* main function */
int main(int argc, char *argv[]){
	
	if(argc == 3)
		printf("\n\tInput file is: %s \n\tOutput file is: %s\n", argv[1], argv[2]);
	else if(argc > 3)
		printf("\n\tTo many arguments supplied.\n");
	else
		printf("\n\tPlease supply the arguments in follwing order:-\n\t./a.out <InputFileName> <OutputFileName>\n");	

	decendingSortMarks(argv[1]);
	
	return 0;	
}

/*
FunctionName: decendingSortMarks
InputParameter:
Output:
*/
int decendingSortMarks(const char* fileName){

	STUDENT *stud,*temp;
	int count=0,indexStud=0;
	char *ch,line[MAX];

	/* Just for counting the number of students */
	FILE *file1 = fopen(fileName, "r");
   	if ( file1 != NULL ){
		int arrayIndex=0;
		while(fgets(line, sizeof line, file1) != NULL ){
			count++;
		}
	}
	fclose(file1);
	
	/* Storing the data in structure and then in array of structures */
	STUDENT *students[count];	
	FILE *file = fopen(fileName, "r");
      	while(fgets(line, sizeof line, file) != NULL ){
		students[indexStud] = (struct student*)malloc(sizeof(STUDENT));
			
		ch = strtok(line, ":");
		strcpy(students[indexStud]->name,ch);
		
		ch = strtok(NULL, " ");
		students[indexStud]->marks=atoi(ch);
		
		ch = strtok(NULL, " ");
 		
		indexStud++;
	}
      	fclose(file);

	sortByMarks(students,indexStud);	
	printStudents(students,indexStud);
	
	float average=avgScore(students,indexStud);
	printf("Average marks are %2.2f\n",average);

	return 0;
}
