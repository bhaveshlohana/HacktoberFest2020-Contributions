#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<list>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    int arr[10] = {1,5,8,7,4,6,3,9,2,0};
    for(int i =0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int k: arr){
        cout<<k<<" ";
    }
    return 0;
}
