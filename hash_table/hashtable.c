
#include stdio.h
#include stdlib.h
#include string.h

struct node{
	int key,rollno;
	int marks;
	struct node*next;
	};

struct hashTable{
	struct node*head;
	
	};
struct hasTable*hash;

int eleCount;
struct node* createNode(int rollno,int marks){

void insertFucn(int key,int rollno,int marks,eleCount){
	int hashIndex=key%eleCount; 
	struct hashTable*newHash=(struct hashTable*)malloc(eleCount*sizeof(struct hashTable));
        if(!hashTable[hashIndex]){
		struct node*newnode=(struct node*)malloc(sizeof(sturct node));
        	hashTable[hashIndex].head=newnode;
        	newnode->rollno=rollno;
        	newnode->marks=marks;
	}
	else{
		hashTable[hashIndex].head=newnode;
	}
}

void insertFucn(int key,int rollno,int marks){
	
	

int main(){
       int roll_no,marks,eleCount,key;
	char option[10];
	scanf("%d",eleCount);
        printf("Select any one of the following options\n");
	printf("*******************************\n");
	printf("1.write insert for insertion");
	printf("2.write delete for deletion");
	printf("3.write search for searching");
        scanf("%s",option);
	switch(option)
		case 1:
               	if(strcmp(option,insert)==0){
		scanf("%d",key);
                scanf("%d",roll_no);
                scanf("%d",marks);
                insertFucn(key,roll_no,marks,eleCount);
	}
	


