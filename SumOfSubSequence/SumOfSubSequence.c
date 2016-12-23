#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define MAX 50

int sumElem(int *array,int arraySize,int desiredSum){
	int first=0,last=arraySize,mySum,foundSum=0;

	while(last!=first){
		mySum=array[first]+array[last];
		if(mySum==desiredSum){
			printf("%d %d %d %d\n",first,last,array[first],array[last]);
			foundSum=1;
			break;
		}
		else if(mySum>desiredSum)
			last--;
		else
			first++;
	}
	
	if(foundSum==0)
		printf("NO\n");
	
	free(array);
	
	return 0;
}

int main(int argc,char *argv[]){
	
	char line[MAX],*filename=argv[1];
	
	int index=0,i=0,readFirstLine=0,arraySize,*array,desiredSum,temp[MAX];
	FILE *file=fopen(filename,"r");	
	
	fgets(line,sizeof line,file);
	char *token=strtok(line," ");
	while(token!=NULL){
		temp[index++]=atoi(token);
		token=strtok(NULL," ");
	}
	arraySize=temp[0];
	desiredSum=temp[1];

	array=(int *)malloc(arraySize*sizeof(int));

	while(fgets(line,sizeof line,file)!=NULL){
		array[i]=atoi(line);
		i++;
	}

	arraySize=i-1;
	sumElem(array,arraySize,desiredSum);	
	fclose(file);	
	
	return 0;
}	
