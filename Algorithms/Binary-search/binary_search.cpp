#include<iostream>
using namespace std;


int main(){
	int n;
	cin>>n;
	int a[100];
	for(int i=0; i<n;i++)
	{
		cin>>a[i];
	}
    int key;
    cin>>key;
	int s=0;
   int e = n-1;
   int mid;

   while(s<e){
        mid = (s+e)/2;
		 if(a[mid]==key){
            cout<<mid;
            break;
        }
        else if(a[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
   }
    if(s>e){
        return -1;
		}

return 0;
}
