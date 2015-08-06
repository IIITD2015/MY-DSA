#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define MAX 10

int hashSize;

struct myNode{
	char *name;
	int marks;
	struct node *next;
};

struct myHashTable{
	struct myNode *first;
};

struct myNode* createNode(char *name, int marks){

	struct myNode *newNode=(struct myNode*)malloc(sizeof(struct myNode));
	
	newNode->name=name;
	newNode->marks=marks;
	newNode->next=NULL;
	
	return newNode;
}

int insert(struct myHashTable hashTable[], char *name, int marks){

	/* Calculating the bucketNumber, using the easiest hashFunction */
	int hashBucket=marks%hashSize;

	printf("name is %s > marks is %d and hashBucket is %d\n",name,marks,hashBucket);	
	
	/* Creating the node to be inserted */
	struct myNode *newNode=createNode(name,marks),*temp;

	if(!hashTable[hashBucket].first){
		printf("Bucket is NULL, means this is the first element in the chaining.\n");
		hashTable[hashBucket].first=newNode;	
	}
	else{
		printf("Bucket is not Null, so inserting it to beginnning and updating the head value\n");
		newNode->next=hashTable[hashBucket].first;	
		
	}

	printf("name is %s > marks is %d and hashBucket is %d\n",hashTable[hashBucket].first->name,hashTable[hashBucket].first->marks,hashBucket);
	
	return 0;
}

int main(int argc, char *argv[]){
		
	char *filename=argv[1], line[MAX], *tok, *name;
	int foundHashSize=0, marks;

	/* Just to calculate the size of HashTable */	
	FILE *file=fopen(filename, "r");
	while(fgets(line, sizeof line, file) != NULL){
		
		/* fetching the size of hashTable and breaking */
		if(!foundHashSize){
                        hashSize=atoi(line);
                        foundHashSize=1;
                        break;
                }
	}
	fclose(file);

	/* Creating the hashTable with the userDefined Size */
	foundHashSize=0;
	struct myHashTable hashTable[hashSize];	
	
	/* Initializing the Bucket with NULL */
	for(int index=0;index<hashSize;index++)
		hashTable[index].first=NULL;

	/* Insert operation of hashtable, is a mandatory operation */
	FILE *fileRem=fopen(filename, "r");
	while(fgets(line, sizeof line, file) != NULL){
		
		/* Skipping the very first line, sice this is just the size of hashTable */
		if(!foundHashSize){
			foundHashSize=1;
			continue;
		}
		else{
			/* tokenizing the line with colon (:) */
			tok=strtok(line, ":");
			name=tok;
			tok=strtok(NULL, " ");
			marks=atoi(tok);
			tok=strtok(NULL, " ");

			/* inserting the tokenized values i.e name and marks of the student */
			insert(hashTable, name, marks);	
		}
	}
	fclose(fileRem);	

	return 0;
}
