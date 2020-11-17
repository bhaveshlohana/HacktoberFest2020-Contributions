#include<stdio.h>
int main()
{int a=0,b,c,d;
printf("enter number to be checked");
scanf("%d",&b);
c=b;
while(b>0)
{d=b%10;
a=a+(d*d*d);
b=b/10;
}if(a==c)
{
    printf("number is arm strong number");}
else{
    printf("number is not armstrong");
        return 0;}
}
