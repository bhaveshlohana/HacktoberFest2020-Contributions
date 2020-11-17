#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void hollowDiamondPattern(int n){
    int half;
    if(n % 2 == 1)
        n++;
    half = n/2;
    for(int i = 1; i <= half; i++){
        for(int j = 1; j <= half - i; j++)
            printf(" ");
        if(i == 1)
            printf("*");
        else {
            printf("*");
            for(int j = 1; j <= 2 * i - 3; j++)
                printf(" ");
            printf("*");
        }
        printf("\n");  
    }
    for(int i = half + 1; i < n; i++){
        for(int j = 1; j <= i - half; j++)
            printf(" ");
        if(i == n - 1)
            printf("*");
        else{
            printf("*");
            for(int j = 1;j <= (2 * (n - i)) - 3; j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int t, n;
    scanf("%d",&t);
    for(int k = 0; k < t; k++){
        printf("Case #%d:\n", k + 1);
        scanf("%d", &n);
        hollowDiamondPattern(n);
    }   
    return 0;
}
