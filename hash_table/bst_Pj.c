#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init(char*);
struct bst* insert (struct bst*,char*);
void printit(struct bst*);
void find(struct bst*,char*);
int hight(struct bst*);

struct bst{
	struct bst *l;
	struct bst *r;
	char name[20];
};
struct bst *root=NULL;
int t=0;

int main(){
	char name[20],option[20]
	int itration,h=0,i;
	scanf("%d",&itration);
	for(i=0;i<itration;i++){
		scanf("%s",option);
		if(strcmp(option,insert)==0){
			scanf("%s",name);
			insert(root,name);
		
		}
		else if(strcmp(option,printit)==0){
			printit(root);
			
		}
		else if(strcmp(option,find)==0){
			scanf("%s",name);
			find(root,name);
			
		}
		else if(strcmp(option,hight)==0){
			hight(root);
		}
	
	}
}


void init(char* name){
	struct bst *temp;
	temp=(struct bst*)malloc(sizeof(struct bst*));
	strcpy(temp->name,name);
	temp->l=NULL;
	temp->r=NULL;
	root=temp;
}

struct bst* insert(struct bst* temp,char* name){
	  struct bst *p;
	  p=(struct bst*)malloc(sizeof(struct bst*));
      srtcpy(p->name,name);
	  p->l=NULL;
	  P->r=NULL;
	  
	if(temp==NUL;2L){
		temp=p;
	}
	else if(strcmp(p->name,temp->name)<0){
		temp->l=insert(temp->l,name);
	}
	else if(strcmp(p->name,temp->name)>0){
		temp->r=insert(temp->r,name);
	}	
	} 

void printit(struct bst* temp){
	if(temp!=NULL){
		printit(temp->l);
		printf("%s",temp->name);
		printit(temp->r);
	}
}

void find(struct bst* temp, char* name){
      if(temp!=NULL){
      	find(temp,name);
      	t=t+1;
      	if(strcmp(temp->name,name)==0)
      	printf("%d",t);
      }	
	
}

int height(struct bst* temp){
      int right,left;
      left=height(temp);
      right=height(temp);
      
     if(left>right){
     
	   left+=1;
	   return left;
    }
	if(right>left){
		
		right+=1;
		return right;
	} 
}

