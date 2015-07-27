#include"stdio.h"

int numVer=4,count=0;
int k=2,source=0,dest=3,flag=1;


int graph(int adj[numVer][numVer],int source,int dest,int k){
		if(k==1 && source==dest)
			return 1;
		
		if(k==0 && source==dest){
			printf("%d\t",source);
			printf("\n");
			return 1;
		}
		else{
			if(flag==1){
				flag=0;
			}
			else
				printf("%d\t",source);
		}
		for(int j=source+1;j<numVer;j++){
			if(adj[source][j]){
				graph(adj,j,dest,k-1);
			}
			
		}
		
		return 0;
}

int main(){
	int adj[4][4]=  {{0,1,1,1},
			 {0,0,0,1},
			 {0,0,0,1},
			 {0,0,0,0}};
	
	graph(adj,source,dest,k);	

	return 0;
}
