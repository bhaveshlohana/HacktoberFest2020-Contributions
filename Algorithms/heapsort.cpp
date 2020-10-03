#include<iostream>
#include<vector>
using namespace std;
 void heapify(int v[],int index,int n){
        int left = 2*index;
        int right = 2*index+1;
        int curr = v[index];
        int minIndex = index;
        if(left< n && v[left]<curr){
            minIndex = left;
        }
        if(right< n && v[right]<v[minIndex]){
            minIndex = right;
        }
        swap(v[index],v[minIndex]);
        if(minIndex!=index){
            heapify(v,minIndex,n);
        }
    }
void createHeap(int arr[],int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,i,n);
    }
}
void heapSort(int arr[],int n){
    for(int i=1;i<n;i++){
        swap(arr[1],arr[n-i]);
        heapify(arr,1,n-i);
    }

}
int main(){
int arr[] = {-1,5,2,7,1,3};
createHeap(arr,6);
heapSort(arr,6);
for(int i=1;i<6;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}

