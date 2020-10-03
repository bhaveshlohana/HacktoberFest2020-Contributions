# include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x){
while(left<=right){
	int mid= left + (right-left)/2;
	if(arr[mid]==x){
		return mid;
	}
	else if(arr[mid]<x){
		left=mid+1;
	}
	else right=mid -1;
}	
return -1;
}
int main(){
    int num;
	int myarr[10];
	int output;	
	int i;
	cout<<"Enter 10 integers in ASCENDING ORDER: "<<endl;
	for(i<=0;i<10;i++){
		cin>>myarr[i];
	}
	cout<<"Enter the number you want to search: "<<endl;
	cin>>num;
	output=binarySearch(myarr, 0, 9, num);
	if(output==-1){
		cout<<"NO Match found"<<endl;
	}
	else{
		cout<<"Match found at index: "<<output<<endl;
	}
	
	
	return 0; 
}
