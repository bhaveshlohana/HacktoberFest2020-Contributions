#include<iostream>
using namespace std;
//time complexity is O(n**2)

void InsertionSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {  int value=A[i];
       int hole=i;
       while(hole>0 && A[hole-1]>value)
       {
           A[hole]=A[hole-1];
           hole=hole-1;
       }
       A[hole]=value;
    }
}
int main()
{  int n;
    std::cout<<"Enter the size of array"<<"\n";
    std::cin>>n;
    int A[n];
    std::cout<<"Enter the elements of array"<<"\n";
    for(int i=0;i<n;i++)
    {

        cin>>A[i];
    }
    InsertionSort(A,n);
  std::cout<<"The array after Bubble sort is"<<"\n";
   for(int i=0;i<n;i++)
    {

        cout<<A[i]<<" " ;
    }



}




