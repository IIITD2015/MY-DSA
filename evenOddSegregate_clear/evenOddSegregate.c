/* Program to segregate even and odd numbers
	input: input array
	output: output array
*/

#include"stdio.h"
#include"stdlib.h"

#define maxArraySize 100

/* Function declearations */
int* inputFunc();
int outputFunc(int*);
int evenOddSegregator(int*);

/* Global variables */
int arraySize,isExit=0,userSelectedOption,arrayToInput[maxArraySize];

int main(){
	
	int *tempArray;
	
	system("clear");	
	printf("\n\t"
	"********************************************* \n\t"
	"Program to segregate even and odd number. \n\t"
	"********************************************* \n \n");
	do{
		printf("\t"
		"Please choose anyone of the options below:- \n\t"
		"1] Input values in array. \n\t"
		"2] Print values of array. \n\t"
		"3] Run segregate function. \n\t"
		"4] Clear the screen!!! \n\t"
		"5] Do you want to exit?? \n");
		printf("\n\tYour option number: ");
		scanf("%d",&userSelectedOption);
		printf("\n");
	
		switch(userSelectedOption){
			case 1:
				tempArray=inputFunc();
				break;
			
			case 2:
				outputFunc(tempArray);
				break;
		
			case 3:
				evenOddSegregator(tempArray);
				break;
			
			case 4:
				system("clear");
				break;

			case 5:
				isExit=1;
				break;
			
			default:
				printf("Please choose a valid option!!!");
				break;		
		}
	}while(!isExit);
	return 0;
}

/*
FunctionName: inputFunc
InputParameters:
Output:
*/
int* inputFunc(){
	
	printf("\tPlease enter the size of the array: ");
	scanf("%d",&arraySize);
	
	printf("\n\tPlease enter the values for the array:- \n");
	printf("\t[\n");
	for(int index=0;index<arraySize;index++){
		printf("\t");
		scanf("\t%d",&arrayToInput[index]);
	}
	printf("\t]\n\n");
	return arrayToInput;
}

/*
FunctionName: outputFunc
InputParameters:
Output:
*/
int outputFunc(int *arrayToPrint){
	
	printf("\tPrinting values of array :- \n");
	printf("\t[");
	for(int index=0;index<arraySize;index++){
		printf("\t");
		printf("%d ",arrayToPrint[index]);
	}
	printf("\t]\n\n");
	return 0;
}

/*
FunctionName: evenOddSegregator
InputParameters:
Output:
*/
int evenOddSegregator(int *arrayToSegregate){
	
	int tempEven[maxArraySize],tempOdd[maxArraySize],indexTwo=0,indexThree=0;
	printf("\tArray Segregation is in progress ... \n");
	
	/* Breaking array into two arrays of even and odd numbers separatly */
	for(int index=0;index<arraySize;){
		if(arrayToSegregate[index]%2)
			/* Elements here are odd number */
			tempOdd[indexTwo++]=arrayToSegregate[index++];
		else
			/* Elements here are even */
			tempEven[indexThree++]=arrayToSegregate[index++];
	}
	
	/* Copying numbers from odd elements array to even elements array */
	for(indexTwo=0;indexThree<arraySize;){
		tempEven[indexThree++]=tempOdd[indexTwo++];
	}	
	
	/* Restoring the segregated array into original array */
	for(int index=0;index<arraySize;index++){
		arrayToSegregate[index]=tempEven[index];
	}
	
	printf("\tArray segregation has completed. Please choose print option to see the values.\n\n");
	return 0;
}



