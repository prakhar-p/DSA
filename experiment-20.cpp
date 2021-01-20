//done by prakhar 196032

#include<stdio.h>
#include<conio.h>
int binary_search(int arr[], int start, int end, int x) { 
    if (end>=start) { 
        int mid = (start+end)  / 2; 
        if(arr[mid] == x){
            return mid; 
  		}
        if(arr[mid] > x){
            return binary_search(arr,start, mid - 1, x); 
   		}
        return binary_search(arr, mid + 1, end, x); 
    } 
   
    return -1; 
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter The Sorted Array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int search;
	scanf("%d",&search);
	int d=binary_search(arr,0,n-1,search);
	printf("Found at index %d",d);
	printf("\n----------------------------------\n");
	printf("Done by prakhar 196032\n");
}
