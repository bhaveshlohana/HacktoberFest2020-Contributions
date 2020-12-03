#include<stdio.h>
void quicksort(int number[25],int first,int last){
   int i, j, p, temp;

   if(first<last){
      p=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[p]&&i<last)
            i++;
         while(number[j]>number[p])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[p];
      number[p]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int i, count, number[25];

   printf("Enter how many elements are you wanna get sorted : ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(number,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}