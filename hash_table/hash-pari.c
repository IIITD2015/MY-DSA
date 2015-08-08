#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define MAX 10

int hashSize;

/**
** Structure of a node
**/
struct myNode{
	char name[MAX];
	int key;
	struct myNode *next;
};

/**
** Structure of hashTable
**/   
struct myHashTable{
	struct myNode *first;
};

/**
** Function to create a node, with corresponding name & key
**/   
struct myNode* createNode(char *name, int key){

	struct myNode *newNode=(struct myNode*)malloc(sizeof(struct myNode));
	
	strcpy(newNode->name,name);
	newNode->key=key;
	newNode->next=NULL;
	
	return newNode;
}

/**
** HashFunction to calculate bucket to insert node
**/   
int myHashFunc(int key, int hashSize){
	
	return key%hashSize;
}

/**
** Function to insert node in the hashTable
**/   
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
		newNode->next=hashTable[hashBucket].first;
		hashTable[hashBucket].first=newNode;
	}

	printf("[%s,%d]-->",hashTable[hashBucket].first->name,hashTable[hashBucket].first->key);
	
	return 0;
}

/**
** Function to print the hashTable
**/   
int printHashFunc(struct myHashTable hashTable[], int hashSize){
	struct myNode *node;
	
	int myBucket=0;	
	
	printf("\tHash\n");
	while(hashSize){
	
		node=hashTable[myBucket].first;
	
		printf("\t[%d]-->",myBucket);	
		while(node!=NULL){
			printf("[%s,%d]-->",node->name,node->key);
			node=node->next;
		}
		
		printf("\n\n");
		myBucket+=1;
		hashSize-=1;
	}
		
	return 0;
}

/**
** Function to check the presence of a node
**/   
int isFound(struct myHashTable hashTable[], int key, int hashSize){

	int myBucket=myHashFunc(key, hashSize), isFound=0;
	
	struct myNode *node=hashTable[myBucket].first;

	if(!node)
		printf("\tElement not present in this hash table.\n");
	else{
		while(node != NULL){
			if(node->key == key)
				isFound=1;
			
			node=node->next;
		}	
	}
	
	return isFound;
}

/**
** Function to delete the requested node
**/   
int deleteFunc(struct myHashTable hashTable[], int key, int hashSize){
	
	if(isFound(hashTable, key, hashSize)){
		printf("\tFound the element, key: %d, going to delete the same. \n",key);

		int hashBucket=myHashFunc(key, hashSize);
		struct myNode *temp=hashTable[hashBucket].first, *trav=temp;

		while(temp->key != key){
			trav=temp;
			temp=temp->next;
		}	
		
		if(temp == trav)
			hashTable[hashBucket].first=hashTable[hashBucket].first->next;
		else
			trav->next=temp->next;
		
		printf("\tAbout to delete the node with key: %d and name: %s\n",temp->key,temp->name);		

		temp=NULL;
		free(temp);
		printf("\tDeleted successfully.\n \n");
	}
	else
		printf("\tElement not found\n \n");	

	return 0;
}

/**
** main function to start the execution 
**/   
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

	printf("\tFollowing elements are inserted with their corresponding bucket number.\n\tCalculated from the hashfunction:- Marks mod %d \n\n",hashSize);
	printf("\tHash\n\t");
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
		"1] Delete any element. \n\t"
		"2] Print the hashTable. \n\t"
		"3] Do you want to exit?? \n");
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
		
			case 2:{
				printHashFunc(hashTable,hashSize);
				printf("\n\n");
                        }
                        break;
	
			case 3:
				isExit=1;
				break;
			
			default:
				printf("Please choose a valid option!!!");
				break;		
		}
	}while(!isExit);
	return 0;
}

