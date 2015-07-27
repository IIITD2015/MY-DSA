#include"stdio.h"

int main(){
	//char *arr[50][10]={{"pari","pooja"},{"abc","xyz"}};
	char *arr[50][10];

	arr[0][1]="pari";
	arr[0][0]="pooja";
	
	printf("[0,0] => %s\n",arr[0][0]);
	printf("[0,1] => %s\n",arr[0][1]);	
	printf("[1,0] => %s\n",arr[1][0]);
	printf("[1,1] => %s\n",arr[1][1]);

}
