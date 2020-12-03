#include <stdio.h>
void main(){
        int a,i,b,c,d,e,o;
        printf("Enter the array size\t");
        scanf("%d",&a);
        int ar[a];
        printf("Enter the element you want to enter in array:\t");
        for (i=0;i<a;i++){
        scanf("%d",&ar[i]);
    }
printf("the array is :\n");
    for (i=0;i<a;i++){
        printf("%d\t",ar[i]);
    }
printf("If u want to Insert  array press 1 \n if u want to delete array press 2");
scanf("%d",&o);
    if (o==1){
    printf("Enter the new elements you want \nFrom starting press 1\n from ending press 2 \n By index press 3: ");
    scanf("%d",&c);
    printf("Enter the elements size: ");
    scanf("%d",&d);
    int arr[a+d];
    if (c==1){
        
        for(i=0;i<d;i++)
        {
            printf("Enter the element you want to enter in array:\t");
            for (i=0;i<d;i++){
            scanf("%d",&arr[i]);
            }
            for(i=0;i<a;i++)
            {
                arr[d+i]=ar[i];
                printf("%d",arr[d+i]);
            }
        }
        printf("the array is :\n");
        for (i=0;i<(a+d);i++){
            printf("%d\t",arr[i]);
        }
    }

    else if (c==2)
    {
        for(i=0;i<d;i++)
        {
            printf("Enter the element you want to enter in array:\t");
            for (i=0;i<d;i++){
            scanf("%d",&arr[i]);}
            for(i=0;i<d;i++)
            { ar[a+i]=arr[i];}
        }
        printf("the array is :\n");
        for (i=0;i<(a+d);i++){
            printf("%d\t",ar[i]);}
    }
    else if (c==3){
        int temp[a];
            for ( i=0;i<(a+d);i++){
            temp[i]=ar[i];
            }
        printf("Enter the index number:\t");
        scanf("%d",&e);
        printf("Enter the element you want to enter in array:\t");
            for (i=0;i<d;i++){
            scanf("%d",&arr[i]);
            }
            for(i=0;i<d;i++)
            {
                ar[e+i]=arr[i];
            }
            for (i=0;i<a+d;i++)
            {
                ar[a+d-e+i-1]=temp[i+e];
            }
        }
            printf("the array is :\n");
            for (i=0;i<(a+d);i++){
                printf("%d\t",ar[i]);}
}



