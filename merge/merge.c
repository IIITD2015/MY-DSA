#include"stdio.h"
#include"stdlib.h"
#include"string.h"


#define MAX 100
int main(){
	int start,end,numTestCases,numStrings,i=0,j=0;	
	char line[50];
	const char *fileName="input.txt";	
	char *name[MAX][MAX];
	char *ch;
	FILE *file = fopen(fileName, "r");	
	while(fgets(line, sizeof line, file) != NULL ){
		//printf("Number of test cases are %d\n\n",atoi(line));
		numTestCases=atoi(line);	
		
		while(numTestCases--){
			fgets(line, sizeof line, file);
			//printf("Number of strings in %d test case are %d\n",i+1,atoi(line));	
			numStrings=atoi(line);
		
			fgets(line, sizeof line, file);
	
			//printf("The strings are as followed\t: %s",line);
			//printf("\nDividing the strings now\n");
			ch=strtok(line," ");	
			
			while(ch!=NULL){
				name[i][j]=ch;
				printf("[%d,%d] %s\t",i,j,name[i][j]);
				j=j+1;  
				ch=strtok(NULL," ");
			}
			j=0;
			i++;
		}
	}
	
	fclose(file);
	
	printf("\n");	
	printf("[0,0] => %s\n",name[0][0]);
	printf("[0,1] => %s\n",name[0][1]);
	printf("[1,0] => %s\n",name[1][0]);
	printf("[0,0] => %s\n",name[0][2]);
        printf("[0,1] => %s\n",name[1][2]);
        printf("[1,0] => %s\n",name[1][3]);

	return 0;
}

