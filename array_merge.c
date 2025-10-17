#include<stdio.h>


void merge_array(int arr1[], int arr2[], int arr3[], int m, int n){

	for(int i = 0; i < m; i++){
		arr3[i] = arr1[i];
	}
	
	
	for(int i = 0; i < n; i++){
		arr3[i+m] = arr2[i];
	}

}

void sort_array(int arr[], int  size){
	int temp;

	for(int i = 0; i < size; i++){
		for(int j = i + 1; j < size; j++){
			if(arr[i] > arr[j]){
		 		temp = arr[i];
		 		arr[i] = arr[j];
		 		arr[j] = temp;
			}
		}
	}
}


void display_array(int arr[], int size){
	
	printf(" Elements are: \n");
	for(int i = 0; i<size; i++){
		printf("%d\n",arr[i]);
	}
	
}


int main(){

	int arr1[50], arr2[50], arr3[50], i, j, m, n, temp;
	
	
	printf("Enter the limit of the First array: ");
	scanf("%d",&m);
	
	printf("Enter the limit of the Second array: ");
	scanf("%d",&n);
	
	if(m > 50 && n > 50){
	
		printf("Invalid Input!!!");
		
	}else{
	
		printf("Enter the %d Numbers of the First array\n",m);
		for(i = 0; i < m; i++){
			scanf("%d", &arr1[i]);
		}
		
		printf("First Array");
		display_array(arr1, m);
		
		
		sort_array(arr1, m);
		printf("Sorted First Array");
		display_array(arr1, m);
		
		
		printf("Enter the %d Numbers of the Second array\n",n);
		for(i = 0; i < n; i++){
			scanf("%d", &arr2[i]);
		}
		
		
		printf("Second Array");
		display_array(arr2, n);
		
		
		sort_array(arr2, n);
		printf("Sorted Second Array");
		display_array(arr2, n);
		
		
		
		merge_array(arr1, arr2, arr3, m, n);
		printf("Merged Array");
		display_array(arr3, m+n);
		
		
		sort_array(arr3, m+n);
		printf("Sorted Merged Array");
		display_array(arr3, m+n);
		
	}

	return (0);
}
