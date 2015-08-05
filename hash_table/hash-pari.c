#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define MAX 10

int hashSize;

typedef struct _node{
	char *name;
	int marks;
	struct node *next;
}node;

typedef struct _hashtable{
	node *first;
}hash;

hash** createHashTable(int hashTableSize){
	
	printf("hashtable size is %d\n",hashTableSize);
	hash **hashTable = (hash **)malloc(hashTableSize * sizeof(hash*));
	
	return hashTable;
}

hash* createNode(char *name, int marks){

	hash *node=(hash *)malloc(sizof(hash));
	
	
	return node;
}
int insert(hash **hashTable, char *name, int marks){
	
	int hashBucket;
	hash *node;

	hashBucket=marks%hashSize;
	node=createNode(name,marks);
	
	printf("name is %s > marks is %d and hashBucket is %d\n",name,marks,hashBucket);
	
	return 0;
}

int main(int argc, char *argv[]){
		
	char *filename=argv[1], line[MAX], *tok, *name;
	int foundHashSize=0, marks;
	hash **hashTable;
	
	FILE *file=fopen(filename, "r");
	while(fgets(line, sizeof line, file) != NULL){
		if(!foundHashSize){
			hashSize=atoi(line);
			
			hashTable=createHashTable(hashSize);
			
			foundHashSize=1;
			continue;
		}
		else{
			tok=strtok(line, ":");
			name=tok;
			tok=strtok(NULL, " ");
			marks=atoi(tok);
			tok=strtok(NULL, " ");
			insert(hashTable, name, marks);	
		}
	}
	
	return 0;
}
