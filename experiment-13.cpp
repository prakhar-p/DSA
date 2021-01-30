//done by prakhar 196032
//INSERTION SORT
#include<stdio.h>
#include<conio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	printf("\n");
	for(int i=1;i<n;i++){
		int hand=arr[i];
		int j=i-1;
		while(j>=0 and hand<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=hand;
	}
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("---------------------------\n");
	printf("Done By Prakhar 196032");	
}
