#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"

#define MAX 50

typedef struct _point{
	int x, y; 
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

int insertbegFunc(int x,int y){
	node *new;
	new=(node *)malloc(sizeof(node));
	new->a.x=x;
	new->a.y=y;
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

int insertendFunc(int x,int y){
        node *new,*trav;
	
        new=(node *)malloc(sizeof(node));
        new->a.x=x;
        new->a.y=y;
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

int deletelistFunc(){
	if(head==NULL){
		return 0;
        }
        else{
		node *temp;
		temp=(node *)malloc(sizeof(node));

		while(head->next!=NULL){
			temp=head;
			head=head->next;
			free(temp);
		}
		free(head);
                head=NULL;	
	}

	return 0;
}

int printlistFunc(int a){
	if(head==NULL){
		printf("NULL\n");	
		return 0;
	}
	else{
		if(a==0){
			node *trav;
			trav=(node *)malloc(sizeof(node));
			trav=head;

			while(trav->next!=NULL){
				printf("%d %d\n",trav->a.x,trav->a.y);
				trav=trav->next;
			}
                	printf("%d %d\n",trav->a.x,trav->a.y);
        	}
		else{
			node *temp;
			temp=(node *)malloc(sizeof(node));
			temp=head;
		
    			while(temp->next!=NULL){
				temp=temp->next;
  			}
			
			while(temp->prev!=NULL){
       				printf("%d %d\n",temp->a.x,temp->a.y);
      				temp=temp->prev;
			}
    		 	printf("%d %d\n",temp->a.x,temp->a.y);
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



int main(int argc,char *argv[]){
	char *ch,line[MAX],*filename=argv[1],*insertend="insertend",*deletelist="deletelist",*printlist="printlist",*deletebeg="deletebeg",*deletelast="deletelast",*createlist="createlist",*insertbeg="insertbeg";
	FILE *file=fopen(filename,"r");	
	int i = 0 ;
	while(fgets(line,sizeof line,file)!=NULL){
       		trim(line);
		ch=strtok(line," ");
                
		if(strcmp(line,createlist)==0){
			initialized();
			}
		
		else if(strcmp(line,insertbeg)==0){
			int a=0,b=0;
			int flagFirst[4],i=0,index=4;	
			while(index--){
				if(i==0){
					ch=strtok(NULL," ");
				}
				else if(i==3){
					ch=strtok(NULL," ");
				}
				else{
					flagFirst[i]=atoi(ch);
					ch=strtok(NULL," ");
   				}
				i++;
			}	
			a=flagFirst[1];
			b=flagFirst[2];

			if(head==NULL){
                                initialized();
                                insertbegFunc(a,b);
			}
			else{
                                insertbegFunc(a,b);
			}
		}	
		
		else if(strcmp(line,insertend)==0){
			int a=0,b=0;
			int flagFirst[4],i=0,index=4;
                        while(index--){
                                if(i==0){
                                        ch=strtok(NULL," ");
                                }
                                else if(i==3){
                                        ch=strtok(NULL," ");
                                }
                                else{
                                        flagFirst[i]=atoi(ch);
                                        ch=strtok(NULL," ");
                                }
                                i++;
                        }
                        a=flagFirst[1];
                        b=flagFirst[2];

                        if(head==NULL){
                                initialized();
                                insertendFunc(a,b);
                        }
                        else{
                                insertendFunc(a,b);
                        }
                }

		else if(strcmp(line,printlist)==0){
                        int a=0;
                        ch=strtok(NULL," ");
			a=atoi(ch);
                        ch=strtok(NULL," ");
			printlistFunc(a);
               		printf("\n");
		}

		else if(strcmp(line,deletebeg)==0){
                        deletebegFunc();
                }

		else if(strcmp(line,deletelast)==0){
			deletelastFunc();
                }
		
		else if(strcmp(line,deletelist)==0){
                        deletelistFunc();
                }

		else{
			exit(1);
                        return 0;
                }
	}
	fclose(file);

	return 0;
}
