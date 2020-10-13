#include <iostream.h>
#include <stdio.h>
int main(void){
    char *p = "Hello, World!";
    
    for (int i = 0; i <= 13; i++)
        printf("%c", *(p+i));
    
    printf("\n");
    
    return 0;
}
