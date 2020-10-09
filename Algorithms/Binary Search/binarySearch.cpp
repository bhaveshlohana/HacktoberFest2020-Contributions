#include <stdio.h>

void main()
{int a[10], i,n, elemm, beg,mid, end, flag;

cout<< "enter number of elements:";
cin>> n;
cout<<"enter elements in increasing order:";
for(i=0; i<n;i++)
{cin>> a[i];
}

cout<< "enter element to be searched:";
cin>> elem;

flag=0;
while (beg< end)
  mid= (beg+ end)/2
{ if (a[mid]==elem}
    cout<< mid;
    flag=1;
    break;
    
  else if (a[mid]< elem)
    beg=mid;
    
 else 
  end=mid;
}  

if (flag==0)
{cout<< "elem not in list!";

}
