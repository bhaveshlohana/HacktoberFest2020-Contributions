#include<iostream>
#include<conio.h>
 using namespace std;
 //optimize algo for bubble sort
 void opbubsort(int a[],int n)
 {
     for(int i=0;i<n-1;i++)
     {
         int flag=0;
         for(int j=0;j<n-1-i;j++)
         {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
         }
         if(flag==0)
         {
             break;
         }
     }
     for(int k=0;k<n;k++)
     {
        cout<<a[k]<<" ";
     }

 }
 int main()
{
    int a[]={12,1,45,23,4};
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" " ;
    }
    cout<<" "<<endl;
    opbubsort(a,5);
    return 0;
}
