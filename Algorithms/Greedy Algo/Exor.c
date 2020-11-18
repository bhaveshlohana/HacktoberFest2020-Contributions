#include <stdio.h>
int main()
{
	int n,x=0,i,j,y;
	scanf("%d", &n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&y);
		x=x^y;
	}
	//if else representation in a single line
	int c=x==0?-1:1;
	printf("%d",c);
}
