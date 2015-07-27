#include"stdio.h"
#include"stdlib.h"

#define MAX 30

int infixToPost(char *expr){
	printf("%s\n",expr);

	return 0;
}

int main(int argc, char *argv[]){
	char *filename = argv[1], line[MAX], *infixToPostParam;
	int numTest;
	
	FILE *file = fopen(filename, "r");
	while(fgets(line, sizeof line, file)!=NULL){
		numTest=atoi(line);
		
		while(numTest--){
			fgets(line, sizeof line, file);
			infixToPostParam=line;
			infixToPost(infixToPostParam);
		}
	}

	return 0;
}
