//done by prakhar 196032
#include<stdio.h>
#include<conio.h>
bool linear_search(int arr[100],int n,int key){
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			return true;		
		}
	}
	return false;
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	
	}
	int key;
	scanf("%d",&key);
	if(linear_search(arr,n,key)){
		printf("\nThe Element %d is found \n\n",key);
	}else{
		printf("\nThe Element is Not Found\n\n");
	}
	printf("\n---------------------------------\n");
	printf("Done By Prakhar 196032\n");
}
