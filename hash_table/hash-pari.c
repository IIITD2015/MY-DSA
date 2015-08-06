#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define MAX 10

int hashSize;

struct myNode{
	char *name;
	int key;
	struct node *next;
};

struct myHashTable{
	struct myNode *first;
};

struct myNode* createNode(char *name, int key){

	struct myNode *newNode=(struct myNode*)malloc(sizeof(struct myNode));
	
	newNode->name=name;
	newNode->key=key;
	newNode->next=NULL;
	
	return newNode;
}

int myHashFunc(int key, int hashSize){
	
	return key%hashSize;
}

int insertFunc(struct myHashTable hashTable[], char *name, int key){

	/* Calculating the bucketNumber, using the easiest hashFunction */
	int hashBucket=myHashFunc(key,hashSize);

	/* Creating the node to be inserted */
	struct myNode *newNode=createNode(name,key);

	if(!hashTable[hashBucket].first){
		
		/* Bucket is NULL, means this is the first element in the chain */
		hashTable[hashBucket].first=newNode;	
	}
	else{
		
		/* Bucket is not NULL, so inserting it to beginnning and updating the head value */
		newNode->next=hashTable[hashBucket].first->next;
		hashTable[hashBucket].first=newNode;			
	}

	printf("\tName:  %s\t key: %d\t hashBucket: %d\n",hashTable[hashBucket].first->name,hashTable[hashBucket].first->key,hashBucket);
	
	return 0;
}

int isFound(struct myHashTable hashTable[], int key, int hashSize){

	printf("Inside found function\n");
	int myBucket=myHashFunc(key, hashSize);
	
	struct myNode *node=(struct myNode*)malloc(sizeof(struct myNode));
	node=hashTable[myBucket].first;

	if(!node)
		printf("Element not present in this hash table\n");
	else{
		while(node->key != key && node != NULL)
			//Problem is there in this line 
			node->next=node->next;
		
		if(node->key == key){
			printf("Found the element\n");
			return 1;
		}
		else
			printf("Elem not found\n");
	}
	return 0;
}

int deleteFunc(struct myHashTable hashTable[], int key, int hashSize){
	
	if(isFound(hashTable, key, hashSize))
		printf("Found the element %d\n",key);
	else
		printf("Element not found\n");	

	return 0;
}

int main(int argc, char *argv[]){

	printf("\n\t"
        "*********************************************** \n\t"
        "      Program to implement a hast-table.  \n\t"
        "(Values inserted from the mentioned input file) \n\t"
        "*********************************************** \n \n");
		
	char *filename=argv[1], line[MAX], *tok, *name;
	int foundHashSize=0, key, userSelectedOption, isExit=0, searchKey;

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

	printf("\tFowllowing elements are inserted with their corresponding bucket number.\n\tCalculated from the hashfunction:- Marks mod %d \n\n",hashSize);
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
			key=atoi(tok);
			tok=strtok(NULL, " ");

			/* inserting the tokenized values i.e name and key of the student */
			insertFunc(hashTable, name, key);	
		}
	}
	fclose(fileRem);	
	printf("\n\n");

	do{
		printf("\t"
		"Please choose anyone of the options below:- \n\t"
		"1] Delete. \n\t"
		"2] Do you want to exit?? \n");
		printf("\n\tYour option number: ");
		scanf("%d",&userSelectedOption);
		printf("\n");
	
		switch(userSelectedOption){
			case 1:{
				printf("\tPlease enter the key to search: ");
				scanf("%d",&searchKey);
				deleteFunc(hashTable,searchKey,hashSize);
			}
			break;
		
			case 2:
				isExit=1;
				break;
			
			default:
				printf("Please choose a valid option!!!");
				break;		
		}
	}while(!isExit);
	return 0;
}

