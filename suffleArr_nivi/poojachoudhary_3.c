#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printarr(int a[],int n);
void shuffle_merge(int a1[],int n1,int a2[],int n2,int a3[]);
void merge(int a1[],int n1,int a2[],int n2,int a3[]);
int getIndex(int i, int limit);

int main()
{
    int n1=0,n2=0;
    int i;
    printf("Enter size of first array\n");
    scanf("%d",&n1);
    int arr1[n1];
    printf("Enter the elements now \n");
    for(i=0;i<n1;i++){
       scanf("%d",(arr1+i));
    }  
    

    printf("Enter size of second array\n");
    scanf("%d",&n2);
    int arr2[n2];
    printf("Enter the elements now \n");
    for(i=0;i<n2;i++){
       scanf("%d",(arr2+i));
    }


    int n3 = n1+n2;   
    int arr3[n3];
    shuffle_merge(arr1,n1,arr2,n2,arr3);
   
    printf("Third array after shuffle and merge operations\n");
    printarr(arr3,n3);
    return 0;
}
/* Function to print array */

void printarr(int arr[],int n) {
 int i; 
 for(i=0;i<n;i++)
{
  printf("%d\n",arr[i]);
}
    
}




void shuffle_merge( int a1[],int n1,int a2[],int n2,int a3[]) {

   if ( n1 >= n2 )
   { 
      merge(a1,n1,a2,n2,a3);
   }

   else 
   {  merge(a2,n2,a1,n1,a3);

   }
}


void merge( int arr1[],int size1, int arr2[], int size2, int arr3[]) {

      int i,j,limit,flag,increment,mid,left,right;
      j=1;
     for(i=0;i<size2;i++){
        arr3[j]=arr2[i];
        j=j+2;
      }

     limit=j-2;
     printf("%d\n",limit);
     flag=1;
     j=0;
     left=0,right=0;
     increment=1;
     mid=size1/2;
    printf("value of mid :%d\n",mid);
     for(i=0;i<size1;i++){
        if(flag==1){
        right=(mid+increment);
        if(right < (size1-1)){
        arr3[j]=arr1[right];
        j=getIndex(j,limit);
        }
        if(right==(size1-1)){
        arr3[j]=arr1[right];
        j=getIndex(j,limit); 
        flag=-1;
        continue;
        }
        if(right > (size1-1)){
        flag=-1;
        continue;
        }
        flag=0;
        continue;
        }

       else if ( flag ==0){
        left=(mid-increment);
        arr3[j]=arr1[left];
        increment++;
        j=getIndex(j,limit);
        flag=1;
        continue;
        }
    
       else if ((flag==-1) && (size1==2)){
       
       arr3[j]=arr1[mid-1];
       j=getIndex(j,limit);
       arr3[j]=arr1[mid];
       break;
      
       }
    
       else if ((flag==-1) && (size1%2==0)){
       arr3[j]=arr1[1];
       j=getIndex(j,limit);
       arr3[j]=arr1[mid];
       j=getIndex(j,limit);
       arr3[j]=arr1[0];
       break;
       }
       else if ((flag==-1) && (size1%2!=0)) {
       arr3[j]=arr1[0];
       j=getIndex(j,limit);
       arr3[j]=arr1[mid];
    
       break;
       }
       
     
    }





}

  int getIndex(int i,int limit) {
  if(i<limit)
         i=i+2;
        else
         i=i+1;
  return i;
}
