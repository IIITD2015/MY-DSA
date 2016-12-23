#include"stdio.h"
#include"stdlib.h"

typedef struct SinglyLL{
	int charac;
	struct SinglyLL *next;
}LL;

int init(int);
int display();

int main(){
	LL *head=NULL,*temp,*ttemp,*p;	
	int a,isExit=0,n;
	do{
		printf("press 1: insert\n\t"
		"2: exit\n\t"
		"3: display\n");
        	scanf("%d",&n);
		switch(n){	
			case 1:{
				printf("enter the character\n");
				scanf("%d",&a);
	

        			temp=(LL *)malloc(sizeof(LL));
        			temp->charac=a;
        			temp->next=NULL;
		
				if(head==NULL)
        				head=temp;
				else{
					ttemp=head;
					while(ttemp->next!=NULL)
						ttemp=ttemp->next;
					ttemp->next=temp;
				}
			}
			
			break;

		case 2:
			isExit=1;
			break;
		
		case 3:{
			p=head;
			while(p!=NULL){
				printf("%d\t",p->charac);
				p=p->next;
				
			}
		}

		break;
		case 4:
		
				
		}			
	}while(!isExit);

	return 0;
}

