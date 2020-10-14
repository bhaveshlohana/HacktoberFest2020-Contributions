#include <iostream> 
using namespace std;

int fibonacciSearch(int arr[], int x, int n){
    int m2 = 0;
    int m1 = 1;
    int m = m2+m1;

    while (n > m){
        m2 = m1;
        m1 = m;
        m = m1+m2;
    }

    int offset = -1;

    while (m>1){
        int i = min(offset+m2, n-1);

        if (arr[i] < x){
            m = m1;
            m1 = m2;
            m2 = m - m1;
            offset = i;
        }

        else if(arr[i] > x){
            m = m2;
            m1 = m1 - m;
            m2 = m - m1;
        }

        else{
            return i;
        }
    }

    if(arr[offset+1] == x){
        return offset+1;
    }

    return -1;
}

int main(){
    int arr[] = {-65, 1, 5, 9, 11, 54, 64, 85};
    int x = 85;
    int len = 8;

    int result = fibonacciSearch(arr, x, len);
    if (result==-1){
        cout<<"Element not found."<<endl;
    } else{
        cout<<"Element found at index "<<result<<endl;
    }

    return 0;
}
