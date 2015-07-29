/**
 * Header file for Binary search tree
pari is  a bed guy */
#include"stdio.h"
#include"string.h"
#include"ctype.h"
#include"stdlib.h"

int count=0;

/**
 * Structure for Binary search tree
 */

typedef struct _BST{
        char name[100];
        struct _BST* left;
        struct _BST* right;
}BST;

int inorder(BST *);

/**
 * Creates a tree, and returns the pointer to the tree
 */
BST* initTreeFunc(char *name){
	BST *tree=(BST*)malloc(sizeof(BST));
	
	tree->left=NULL;
	tree->right=NULL;
	strcpy(tree->name,name);

	return tree;
}

/**
 * Inserts a node in the tree T. If the tree is empty (T is NULL, 
 * this might happen on enough deletions), then your function should 
 * internally call InitTree(name).
 */
int insertFunc(char *name,BST** T){
	if(T==NULL){
		initTreeFunc(name);
	}
	else{
		BST *trav=*T,*newNode=(BST*)malloc(sizeof(BST));
		int diff,isInserted=0,count=0;
		
		newNode->left=NULL;
		newNode->right=NULL;
		strcpy(newNode->name,name);

		while(isInserted==0){
			diff=strcmp(trav->name,name);
			
			/* If the coming charactor is smaller than the current one */
			if(diff>=0){
				if(trav->left!=NULL)
					trav=trav->left;
				else{
					trav->left=newNode;
					isInserted=1;
				}
			}

			/* If the coming charactor is bigger than the current one */
			else{
				if(trav->right!=NULL)
					trav=trav->right;
				else{
					trav->right=newNode;
					isInserted=1;
				}	
			}
		}
	}
	
	return 0;
}

/**
 * Deletes the node with the given name if it is present, or
 * prints “Not Found” if tree is empty or if node is not present
 */
int deleteFunc(char* name,BST **T){
	if(T==NULL){
		printf("Not Found\n");	
	}		
	else{
		BST *trav=*T,*temp=*T;
		int diff,isFound=0,isDeleted=0,isNotFound=0;
			
		while(!isFound && !isDeleted && !isNotFound){
			diff=strcmp(trav->name,name);

			/* Found the elemet, going to delete the same */
			if(!diff){			
				isFound=1;
				
				if(trav->left!=NULL && trav->right!=NULL){
					printf("Very complecated case of deletion\n");
				}
				else if(trav->left==NULL){
					printf("Normal case of deletion\n");
					
					if(temp->left==trav)
						temp->left=trav->right;
					else
						temp->right=trav->right;
					trav=NULL;
                                        free(trav);
				}
				else if(trav->right==NULL){
					printf("Normal case of deletion\n");
					
					if(temp->right==trav)
						temp->right=trav->left;
					else
						temp->left=trav->right;
					trav=NULL;
                                        free(trav);
				}
				else{
					printf("It leaf elem, very simple case, delete directly\n");
					trav=NULL;
					free(trav);
				}
			}
			
			/* If the coming charactor is smaller than the current one */
			else if(diff>0){
				if(trav->left!=NULL){
					temp=trav;
					trav=trav->left;
				}
				else{
					isNotFound=1;
					printf("Not Found\n");
				}
			}

			/* If the coming charactor is bigger than the current one */
			else{
				if(trav->right!=NULL){
                                	temp=trav; 
				       	trav=trav->right;
				}
                                else{
                                        isNotFound=1;
					printf("Not Found\n");
				}
			}
		}
	}	

	return 0;
}

/**
 * Returns whether a node with the given name is present in T or
 * not. Print it’s InOrder position if present, or print ‘Not Found’ otherwise
 */
int findFunc(char *name,BST *T){
	BST *trav=T;
	
	int isFound=0,isNotFound=0,diff,count=0;
	while(!isFound && !isNotFound){
      	       diff=strcmp(trav->name,name);

               /* Found the elemet, going to Print is Inorder position */
               if(!diff){
     	                isFound=1;
			count++;
			printf("%d\n",count);
  	 	}

                /* If the coming charactor is smaller than the current one */
                else if(diff>0){
			count++;
         	      	if(trav->left!=NULL){
            	     		trav=trav->left;
                      	}
			else{
                        	isNotFound=1;
                                printf("Not Found\n");
                        }
                }
			
		/* If the coming charactor is bigger than the current one */
               	else{
			count++;
                  	if(trav->right!=NULL){
                                trav=trav->right;
                        }
                        else{
                           	isNotFound=1;
                                printf("Not Found\n");
                        }
              	}
	}

	return 0;
}

/**
 * Computes the height of T
 */
int heightFunc(BST* T){

	if (T==NULL){ 
		return 0;
	}
   	else{
       		/* compute the depth of each subtree */
       		int lDepth = heightFunc(T->left);
       		int rDepth = heightFunc(T->right);
 
       		/* use the larger one */
       		if (lDepth > rDepth) 
           		return(lDepth+1);
       		else return(rDepth+1);
   	}
	
	return 0;
}

/**
 * This function displays the tree in inorder fashion
 */
int inorder(BST *temp) {
   	if(temp!=NULL) {
      		inorder(temp->left);
      		printf("%s ",temp->name);
      		inorder(temp->right);
   	}

	return 0;
}

/**
 * This function displays the tree in preorder fashion
 */
int preorder(BST *temp) {
   	if(temp!=NULL) {
      		printf("%s ",temp->name);
      		preorder(temp->left);
      		preorder(temp->right);
   	}

	return 0;
}
 
/**
 * This function displays the tree in postorder fashion
 */
int postorder(BST *temp) {
   	if(temp!=NULL) {
      		postorder(temp->left);
      		postorder(temp->right);
      		printf("%s ",temp->name);
   	}
		
	return 0;
}

/**
 * Prints the nodes in the tree in in-order manner if order = 0,
 * pre-order manner if order = -1, and post-order(1) otherwise (Strings of nodes to be printed space-separated)
 */
int printTreeFunc(BST* T,int order){
	BST *trav=T;

	if(trav==NULL)
      		return 0;
        else{
		if(order==0)
            		inorder(trav);
            	else if(order==-1)
			preorder(trav);
            	else
			postorder(trav);
         }	
	return 0;
}

/**
 * Trims the white-space characters
 */
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
