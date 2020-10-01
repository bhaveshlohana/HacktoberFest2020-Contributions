#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[100], find;
    int a;
    int b;

    printf ("Enter the array size\n");
    scanf ("%d", &b);

    printf ("Enter %d amount of integer(s)\n", b);
    
    //adding integers to the array
    while (a < b){
    scanf("%d", &arr[a]);
    a++;
    }

    printf ("Enter the number to find\n");
    scanf ("%d", &find);
    
    //recursively trying to find the equal value.
    for (a = 0; a < b; a++){
        if (arr[a] == find){
            printf ("%d is located in %d\n", find, a + 1);
            break;
        }
    }
    //value doesn't have a match in the array.
    if (find != arr[a]){
        printf ("%d is not located in the array\n", find);
    }
    return 0;
}