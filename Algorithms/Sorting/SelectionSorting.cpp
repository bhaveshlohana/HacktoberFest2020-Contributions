#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<list>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    int arr[10] = { 9,8,7,5,6,4,2,3,1,0 };
    for(int i=0; i<10; i++){
        int minIndex = i;
        for(int j=i; j<10; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    for(int k: arr){
        cout<<k<<" ";
    }
    return 0;
}
