#include <stdlib.h>
#define N 20

void printSeq(int a[], int n)
{
  printf("[");
  for (int i=0; i<n; i++)
    printf("%d ", a[i]);
  if (n==0)
    printf("]\n");
  else
    printf("\b]\n");
}

void quicksort(int arr[], int n)
{
  if(n<2) return;
  int larr[n], rarr[n], pivot=arr[0];
  int i, li=0, ri=0;
  for(i=1;i<n;i++)
    if(arr[i]<pivot)
      larr[li++]=arr[i];
    else rarr[ri++]=arr[i];
  printf("larr=");
  printSeq(larr,li);
  printf("pivot=%d\n", pivot);
  printf("rarr=");
  printSeq(rarr,ri);
  quicksort(larr,li);
  quicksort(rarr,ri);
  for(i=0;i<li;i++)
    arr[i]=larr[i];
  arr[i]=pivot;
  for(i++;i<n;i++)
    arr[i]=rarr[i-li-1];
  return;
}

int main()
{
  int a[N], n, i;
  printf("Sequence length (>0, <20) = ");
    scanf("%d", &n);
  if (n<1)
  {
    printf("Illegal length\n");
    exit(0);
  }
  printf("\nGive seq. elements sep. by white space = ");
  for (i=0; i<n; i++)
    scanf("%d", &a[i]);
  printf("\nOriginal sequence = ");
  printSeq(a, n);
  quicksort(a, n);
  printf("\nSorted sequence = ");
  printSeq(a, n);
  return 0;
}
