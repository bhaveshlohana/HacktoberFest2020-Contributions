#include <stdio.h>
#include <stdlib.h>

// Program that lets the users enter their name and greets them along with their names 
int main(int argc, char *argv[])
{
    //Check usage
    if(argc!=2)
    {
        printf("Usage ./Hello_world_2020 your_name\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
