#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int key,rollno;
	int marks;
	struct node*next;
	};

struct hashTable{
	struct node*head;
	
	};
struct hasTable* hash[];

int eleCount,hashIndex;
struct node* createNode(int key,int rollno,int marks){
		         
				hashIndex=key%eleCount; 
	    		struct hashTable* newHash=(struct hashTable*)malloc(eleCount*sizeof(struct hashTable));
      			struct node* newnode=(struct node*)malloc(sizeof(struct node));
        		newnode->rollno=rollno;
        		newnode->marks=marks;
        		newnode->next=NULL;
        		return newnode;
    
}
	 

void insertFucn(int key,int rollno,int marks,int eleCount){
				struct node* newnode;
		
		       if(!hash[hashIndex]){
		       	    
		       		newnode=createNode(key,rollno,marks);
		       		hash[hashIndex].head=newnode;
		       		printf("hash table does nt exist");
		       }

	else{ struct node *temp;     //insertion at d end
			temp=hash[hashIndex].head;
		    while(temp!=NULL){
		    temp=temp->next;
		}
			
			temp->next=newnode;
			newnode->next=NULL;
	
	}
}

	
	

int main(){
       int roll_no,marks,key;
	int option;
	scanf("%d",eleCount);
        printf("Select any one of the following options\n");
	printf("*******************************\n");
	printf("1.write insert for insertion");
	printf("2.write delete for deletion");
	printf("3.write search for searching");
        scanf("%d",option);
	switch(option)
		case 1:
			{
			
               	if(option=1){
					scanf("%d",key);
               		scanf("%d",roll_no);
                	scanf("%d",marks);
                	insertFucn(key,roll_no,marks,eleCount);
                	
			}
	        break;

}
 			return 0;
 		}
