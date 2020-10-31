#include<stdio.h>
#include<conio.h>
#include<math.h>
int SIZE = 0;

int getValue(char message[]);
void setArray(int arr[SIZE]);
void printArray(int arr[SIZE]);
void sortArray(int arr[SIZE]);
int searchValueUsingBinaryIterative(int searchValue, int arr[SIZE]);
int searchValueUsingBinaryRecursive(int searchValue, int arr[SIZE], int low, int high);

int main(){
	
	SIZE = getValue("Enter Array Size: ");
	int arr[SIZE], search;
	int pos;
	
	setArray(arr);
	printArray(arr);
	sortArray(arr);
	printArray(arr);
	
	//searching a value;
	search = getValue("\nEnter a value you want to search: ");
	
	
	pos = searchValueUsingBinaryIterative(search, arr);
	if(pos != -1){
		printf("\n%d value found at position %d", search, pos);
	}
	else{
		printf("\nThe value is not avaliable in array");
	}
		
	//Recursive statement
	pos = searchValueUsingBinaryRecursive(search, arr, 0, SIZE);
	if(pos != -1){
		printf("\n%d value found at position %d", search, pos);
	}
	else{
		printf("\nThe value is not avaliable in array");
	}
	return 0;
}

int getValue(char message[]){
	int size;
	printf("\n%s",message);
	scanf("%d", &size);
	return size;
}

void setArray(int arr[SIZE]){
	printf("\n");
	int i = 0;
	for(;i<SIZE;i++){		
		printf("Enter %d element: ",(i+1));
		scanf("%d", &arr[i]);		
	}
	
}

void printArray(int arr[SIZE]){
	printf("\n");
	int i;
	for(i=0; i<SIZE; i++){
		printf("%d ",arr[i]);
	}
}

void sortArray(int arr[SIZE]){
	
	int i,j;
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			if(arr[j] > arr[i]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
}

int searchValueUsingBinaryIterative(int searchValue, int arr[SIZE]){
	
	int low, high, mid;
	low = 0;
	high = SIZE-1;
	while(low <= high){
		mid = floor((low+high)/2);
		if(arr[mid] == searchValue)
			return mid+1;
		else if(searchValue < arr[mid])
			high = mid - 1;
		else
			low = mid+1;
	}
	
	return -1;
}

int searchValueUsingBinaryRecursive(int searchValue, int arr[SIZE], int low, int high){
	
	int mid;
	mid = floor((low+high)/2);
	
	if(low > high)
		return -1;
	
	if(arr[mid] == searchValue)
		return mid+1;
	else if(searchValue < arr[mid])
		return searchValueUsingBinaryRecursive(searchValue, arr, low, mid - 1);
	else
		return searchValueUsingBinaryRecursive(searchValue, arr, mid+1, high);

}
