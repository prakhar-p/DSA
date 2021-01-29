#include<stdio.h>
//Done by Prakhar 196032

#include<conio.h>
#include<math.h>
void selection_sort(int arr[],int n){
	for(int i=0;i<n;){
		int min=arr[i];
		for(int j=i;j<n;){
			if(arr[j]<min){
				min=arr[j];
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
			j++;
		}
	
		i++;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	selection_sort(arr,n);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("\n");
	printf("------------------------------------\n");
	printf("Done By PRAKHAR 196032");

}
