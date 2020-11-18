#include<stdio.h>

void main(){

   int count, temp, i, j, number[30];

   printf("How many number you want to enter: ");
   scanf("%d",&count);

   printf("Enter %d numbers: ",count);

   for(i=0;i<count;i++)
   scanf("%d",&number[i]);


   for(i=count-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(number[j]>number[j+1]){
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }

   printf("Elements in sorted order: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
}
