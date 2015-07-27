
#include"stdio.h"
#include"stdlib.h"

#define MAX 100
int 

/* function defination */
int push(int arr[],int item){
	if(top==MAX-1)
		printf("Queue is Full, an not insert");
	else{
		arr[++top]=item;
	}
	return 0;
}

int pop( int arr[ ]){
	if(top==-1)
		printf("Queue is Empty, can not DEQUEUE");
	else{
		item=arr[top--];
	}
	
	return item;
}

int main(){
	int arr1[MAX],arr2[MAX],selectedoption,item;
	do{
  		printf("/t"
       		" please enter any one of the following-/n/t"
       		" 1.ENQUEUE/n/t"
       		" 2.DEQUENE/n/t"
       		" 3.ISEMPTY/n/t"
       		" 4.ISEXIT/n/t");
  		printf("your option is/n/t");
  		scanf("%d",&selectedoption);

		switch(selectedoption){
       			case 1:{
       				printf("enter the quene element/n");
      	 			scanf("%d",&item);
       				push(arr1[ ],item);
			}
       			break;
      
       			case 2:{
       				printf("/tDEQUENE OPERATION");
       				while(!isEmpty(arr1)){
       					item=pop(arr1[ ]);
       					push(arr2[ ],item);
				}
				
				while(!isEmpty(aar2)){
   					item=pop(arr2[ ]);
      					printf("/t/n/ the element dequene is %d",item);
				}
			}
			break;
      
			case 3:{
      				if(top==-1)
      					printf("/t/n/quene is empty");
 			}break;
		}
	} 
}
