#include"stdio.h"
#include"string.h"
#include"ctype.h"
#include"stdlib.h"
#include"BST.h"

#define MAX 20

int main(int argc,char *argv[]){
	char *tok,line[MAX],*filename=argv[1],*initTree="InitTree",*insert="Insert",*delete="Delete",*find="Find",*height="Height",*printTree="PrintTree";	
	BST **T=(BST**)malloc(sizeof(BST*));
	int numOper=2,numLines=0;

	//FILE *fileCountLines=fopen(filename,"r");
	//while(fgets(line,sizeof line,fileCountLines)!=NULL){
	//	numLines++;
	//}
	//fclose(fileCountLines);

	numOper=numLines-1;
	
	FILE *file=fopen(filename,"r");
	while(fgets(line,sizeof line,file)!=NULL){
		
		trim(line);
		tok=strtok(line," ");

		if(strcmp(line,initTree)==0){
			char *initTreeParam;

                        tok=strtok(NULL," ");
			initTreeParam=tok;
                        *T=initTreeFunc(initTreeParam);
			tok=strtok(NULL," ");
		}
		
		else if(strcmp(line,insert)==0){
			char *insertParam;
			tok=strtok(NULL," ");
			insertParam=tok;
			insertFunc(insertParam,T);
			tok=strtok(NULL," ");
		}
		
		else if(strcmp(line,delete)==0){
			char *deleteParam;
			tok=strtok(NULL," ");
			deleteParam=tok;
			deleteFunc(deleteParam,T);
			tok=strtok(NULL," ");
		}
			
		else if(strcmp(line,find)==0){
			char *findParam;
			tok=strtok(NULL," ");
			findParam=tok;
			findFunc(findParam,(*T));
			tok=strtok(NULL," ");
		}
		
		else if(strcmp(line,height)==0){
           		int height=heightFunc(*T);
			printf("%d\n",height);
                        tok=strtok(NULL," ");
                }
		
		else if(strcmp(line,printTree)==0){
                        int printTreeParam;
                        tok=strtok(NULL," ");
                        printTreeParam=atoi(tok);
                        printTreeFunc(*T,printTreeParam);
                        tok=strtok(NULL," ");
			printf("\n");
                }
	}
	
	fclose(file);
	return 0;
}
