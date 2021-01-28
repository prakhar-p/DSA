//Done by Prakhar 196032

#include<stdio.h>
#include<conio.h>

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				//swap(arr[i],arr[j]);
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
		for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("\n");
	printf("------------------------------------\n");
	printf("Done By PRAKHAR 196032");
}

