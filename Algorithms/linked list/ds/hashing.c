#include <stdio.h>
#include <stdlib.h>
int hash(int, int[], int, int);
int isfull(int *, int);
int main()
{

    int a, value, key;
    printf("How many Elements you want to enter '?' ");
    scanf("%d", &a);
    int arr[a];
    for (int i = 0; i <= a; i++)
    {
        arr[i] = -1;
    }
    int j = 0;
    do
    {

        printf("Enter the any number:");
        scanf("%d", &value);
        key = value % a;
        printf("%d", key);
        hash(key, arr, value, a);
        j++;
    } while (j < a);
    printf("________________________________\n|\tKEY\t|\tVALUE\t|");
    for (int i = 0; i < a; i++)
    {
        printf("\n________________________________\n|\t%d\t|\t%d\t|", i, arr[i]);
    }
    printf("\n________________________________");
}
int hash(int key, int arr[], int value, int a)
{
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("________________________________\n|\tKEY\t|\tVALUE\t|");
        for (int i = 0; i < a; i++)
        {
            printf("\n________________________________\n|\t%d\t|\t%d\t|", i, arr[i]);
        }
        printf("\n________________________________");
    }

    else
    {
        for (int i = key + 1; i < a; i++)
        {
            if (arr[i] == -1)
            {
                arr[i] = value;

                printf("________________________________\n|\tKEY\t|\tVALUE\t|");
                for (int i = 0; i < a; i++)
                {
                    printf("\n________________________________\n|\t%d\t|\t%d\t|", i, arr[i]);
                }
                printf("\n________________________________");
            }
        }
        for (int i = 0; i < key; i++)
        {
            if(arr[i]==-1){
            printf("%d %d\t",arr[i],i);
            arr[i] = value;
            printf("%d\t", value);
            printf("%d",arr[i]);
            return 0;
            printf("________________________________\n|\tKEY\t|\tVALUE\t|");
            for (int i = 0; i < a; i++)
            {
                printf("\n________________________________\n|\t%d\t|\t%d\t|", i, arr[i]);
            }
            printf("\n________________________________");
            }
        break;
        }
    }
    return 0;
}
