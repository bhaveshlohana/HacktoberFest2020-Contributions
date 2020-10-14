#include<stdio.h>
#include<conio.h>
int fact1(int);
int fact2(int);
int fact3(int);
int combo(int);
main()
{
    int N,R,r1,r2,r3,res;
    printf("No. of items");
    scanf("%d",&N);
    printf("No. of selections");
    scanf("%d",&R);
    r1=fact1(N);
    r2=fact2(R);
    r3=fact3(N-R);
    res=combo(r1,r2,r3);
    printf("No. of combinations=%d",res);
    getch();
}
int fact1(int n)
{
    int f=1;
    while(n>0)
    {
        f=f*n;
        n--;
    }
    return f;
}
int fact2(int r)
{
    int f=1;
    while(r>0)
    {
        f=f*r;
        r--;
    }
    return f;
}
int fact3(int p)
{
    int f=1;
    while(p>0)
    {
        f=f*p;
        p--;
    }
    return f;
}
int combo(int R1,int R2,int R3)
{
    int c;
    c=R1/(R2*R3);
    return c;
}
