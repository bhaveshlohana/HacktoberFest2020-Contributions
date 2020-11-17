#include<iostream>
using namespace std;

int partition(int a[],int s, int e){
	int pivot = a[e];
	int pindex = s;
	for(int i=s;i<=(e-1);i++){
		if(a[i]<pivot){
			int z;
			z = a[i];
			a[i] = a[pindex];
			a[pindex] = z;
			pindex++;
		}
	}
	int temp;
	temp = a[e];
	a[e] = a[pindex];
	a[pindex] = temp;
	return pindex;
}
void quicksort(int a[], int s, int e){
	if(s<e){
		int p = partition(a,s,e);
		quicksort(a,s,(p-1));
		quicksort(a,(p+1),e);
	}
}
int main(){
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements in the array: ";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	cout<<"Unsorted array: ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	quicksort(arr,0,(size-1));
	cout<<"Sorted array: ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}