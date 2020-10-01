#include<stdio.h>
int factorial(int n);
void main()
{
    int n,a;
    printf("enter no. of rows of pascal triangle: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int s=n-1-i;s>0;s--)
        {
            printf(" ");
        }
        for(int j=0;j<=i;j++)
        {
            a=(factorial(i))/(factorial(j)*factorial(i-j));
            printf("%d ",a);
        }
        printf("\n");
    }
}
int factorial(int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
    {
            f=f*i;
    }
    return f;
}
