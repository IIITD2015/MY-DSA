#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	int data;
	struct _node*next;
	struct _node*prev;
}node;
node *head=NULL;
node *temp,*trav;

int a;
void sortlist(node*head);
int create(){
	if (head==NULL)
	{
	
	temp= (node *)malloc(sizeof(node));
	temp->prev=NULL;
	temp->next=NULL;
	scanf("%d",&a);
	temp->data=a;
	//shorting to b done of entered array
}
return 0;	
	
}
int insertbeg(){
	if(head==NULL)
	{
		create();
		head=temp;
		
	}
	else
	   {
	    create();
    	temp->next=head;
    	head->prev=temp;
    	head=temp;
    	sortlist(head);
    //	printf("hello");
}
	return 0;
}
int insertend(){
	if(head==NULL)
	{
	    create();
	    head=temp;

	}
	else
   {
        create();
        trav=head;
		while(trav->next!=NULL){
			trav=trav->next;
		}
	    
		temp->prev=trav;
    	trav->next=temp;
    	sortlist(head);
    }

    return 0;
}
int deletebeg(){
        if(head==NULL)
	  
	      printf("no element in the linklist");
	      
	  
	  else
	  {
	  	create();
	  	trav=head;
	  	head=head->next;
	  	free(trav);
	  	
	  }	
	return 0;
}
int deletelast(){
       if(head==NULL){
     	
     	printf("no element present");
    
     }
	
	else
	{
		trav=head;
		while(trav->next!=NULL)
		{    temp=trav;
			trav=trav->next;
		}
		
		temp->next=NULL;
		free(trav);
	}
	return 0;
} 
int terminate(){
	int ch;
	if(head==NULL){
		printf("NULL\n");	
		
	} 
	scanf("%d",&ch);
	 if(ch==0)
	{
		trav=head;
		while(trav->next!=NULL)
		{
			printf("%d/n",trav->data);
			trav=trav->next;
		}
    printf("%d/n",trav->data);
	
   }
   else
   {
   	temp=head;
   		while(temp->prev!=NULL){
       				printf("%d\n",temp->data);
      				temp=temp->prev;
			}
    		 	printf("%d\n",temp->data);
		} return 0;
   }
   void sortlist(node*head){
   	    
   	     node *current,*insertpointer;
   	     head=current;
   	     insertpointer=head;
   	     current=current->next;
   	     
			while(current!=NULL)
			{
			
   	            insertpointer=head;
   	              
					 while(insertpointer->next!=current)
					    {
					    
	                    if(temp->data>current->data)
	                  {
	                    	int temp1= current->data;
	  	                    current->data=temp->data;
	  	                     temp->data=temp1;
	                  }	
	                      else{
	  
	                           insertpointer=insertpointer->next;
                             }
                           current=current->next;
	  
                       }
           }         
}
					    
   int main(){
   		int userSelectedOption,isExit=0;
	
	
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
                        	       	insertbeg();
                        	}
			
                       	break;

                        case 2:{
                                        insertend();

                        }
		     	          break;

                        case 3:
                                deletebeg();
				          break;

                        case 4:
                                deletelast();
				        break;

                        case 5:{
				               sortlist(head);
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


