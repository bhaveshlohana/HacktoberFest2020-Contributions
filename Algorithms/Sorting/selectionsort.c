#include<stdio.h>
int main()
{
  //variable declaration
  int i,n,j;
  int temp,min;
  //user input
  printf("\nEnter the total number of entries :");
  scanf("%d",&n);
int a[n];
printf("\nEnter your numbers one by one with a space or press enter after each entry:");

  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
//selection sort
int x,y;
  for(x=0;x<n-1;x++)
  {
    min=x;
    for(y=x+1;y<n;y++)
    {
      if(a[y]<a[min])
      min=y;
    }
    temp=a[x];
    a[x]=a[min];
    a[min]=temp;
  }
    //printing out soted array
    printf("The sorted numbers are:\n");
  for(j=0;j<n;j++)
    {
      printf("%d",a[j]);
    }
}
