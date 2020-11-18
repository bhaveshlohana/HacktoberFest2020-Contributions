#include <stdio.h>
#include <math.h>
#include<stdlib.h>
long dectobi(int decimalnum)
{
    long binarynum = 0;
    int rem, temp = 1;

    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    return binarynum;
}

int main(int argc, char *argv[])
{ 
    int decimalnum;
    decimalnum=atoi(argv[1]);
    printf("Equivalent Binary Number is: %ld", dectobi(decimalnum));
    return 0;
}

