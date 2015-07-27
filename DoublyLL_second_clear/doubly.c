#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"

#define MAX 50

typedef struct _point{
	int x; 
}point;

typedef struct _node{ 
	point a;
	struct _node* next;
	struct _node* prev; 
}node;

/* Global variable */
node *head=NULL;

int initialized(){
	head=(node *)malloc(sizeof(node));	
	head=NULL;
	
	return 0;
}

int insertbegFunc(int x){
	node *new;
	new=(node *)malloc(sizeof(node));
	new->a.x=x;
	new->prev=NULL;

	if(head==NULL){
		new->next=NULL;
	}
	else{
		new->next=head;
                head->prev=new;
	}
	head=new;

	return 0;
}

int insertendFunc(int x){
        node *new,*trav;
	
        new=(node *)malloc(sizeof(node));
        new->a.x=x;
	new->next=NULL;

	if(head==NULL){
		new->prev=NULL;
		head=new;
	}
	else{
		trav=(node *)malloc(sizeof(node));
		trav=head;
		while(trav->next!=NULL){
			trav=trav->next;
		}
		trav->next=new;
		new->prev=trav;
        }
	
	return 0;
}

int deletebegFunc(){
	if(head==NULL){
        	return 0;
        }
	else{
		node *temp;
		temp=(node *)malloc(sizeof(node));
		temp=head;

		head=head->next;
		head->prev=NULL;
		free(temp);
	}

	return 0;
}

int deletelastFunc(){
	if(head==NULL){
           	return 0;
        }
        else{
		node *trav,*temp;
		temp=(node *)malloc(sizeof(node));
		trav=(node *)malloc(sizeof(node));

		trav=head;
	
		while(trav->next!=NULL){
			temp=trav;
			trav=trav->next;
		}
		temp->next=NULL;
                free(trav);
        }

	return 0;
}

int swap(node *a,node *b){
        int temp = a->a.x;
        a->a.x = b->a.x;
        b->a.x = temp;

        return 0;
}

int bubbleSort(node *start){
    	int swapped,i;
    	node *ptr1;
    	node *lptr=NULL;
 
    	if(ptr1==NULL)
        	return 0;
 
    	do{
        	swapped=0;
        	ptr1=start;
 
        	while(ptr1->next != lptr){
            		if(ptr1->a.x > ptr1->next->a.x){ 
                		swap(ptr1,ptr1->next);
                		swapped=1;
            		}
            	ptr1=ptr1->next;
       		}
        	lptr=ptr1;
    	}while(swapped);

	return 0;
}
 
int sortlistFunc(int a){
	if(head==NULL){
		printf("NULL\n");	
		return 0;
	}
	else{
		bubbleSort(head);

		if(a==0){
			node *trav;
			trav=(node *)malloc(sizeof(node));
			trav=head;

			while(trav->next!=NULL){
				printf("\t%d\n",trav->a.x);
				trav=trav->next;
			}
                	printf("\t%d\n",trav->a.x);
        	}
		else{
			node *temp;
			temp=(node *)malloc(sizeof(node));
			temp=head;
		
    			while(temp->next!=NULL){
				temp=temp->next;
  			}
			
			while(temp->prev!=NULL){
       				printf("\t%d\n",temp->a.x);
      				temp=temp->prev;
			}
    		 	printf("\t%d\n",temp->a.x);
		}
	}
	
	return 0;	
}

int trim(char *s){
    	char *p=s;
    	int l=strlen(p);

    	while(isspace(p[l-1])) 
		p[--l]=0;
    	
	while(*p && isspace(*p))
		 ++p, --l;

    	memmove(s,p,l+1);

	return 0;
}

int main(){
		
	int userSelectedOption,isExit=0;
	
	system("clear");
	printf("\n\t"
        "********************************************* \n\t"
        "Program to sort doubly linked list. \n\t"
        "********************************************* \n \n");
    	do{
                printf("\t"
                "Please choose anyone of the options below:- \n\t"
                "1] insertbeg(after selecting this plz enter the element to be inserted). \n\t"
                "2] insertend(after selecting this plz enter the element to be inserted). \n\t"
                "3] deletebeg. \n\t"
                "4] deletelast. \n\t"
                "5] stop(after selecting this plz enter your choice either 0 or 1). \n");
                printf("\n\tYour option number: ");
                scanf("%d",&userSelectedOption);
                printf("\n");

                switch(userSelectedOption){
                        case 1:{
				int elem;
				scanf("%d",&elem);
	
				if(head==NULL){
                                	initialized();
                        	       	insertbegFunc(elem);
                        	}
                       		else{
                        	       	insertbegFunc(elem);
                        	}
			}
                       	break;

                        case 2:{
				int elem;
                                scanf("%d",&elem);
                                if(head==NULL){
                                        initialized();
                                        insertendFunc(elem);
                                }
                                else{
                                        insertendFunc(elem);
                                }
                        }
			break;

                        case 3:
                                deletebegFunc();
				break;

                        case 4:
                                deletelastFunc();
				break;

                        case 5:{
				int choice;
                                scanf("%d",&choice);
				sortlistFunc(choice);
				isExit=1;
			}
                        break;

                        default:
                                printf("Please choose a valid option!!!");
                                break;
                }
    	}while(!isExit);

	return 0;
}
