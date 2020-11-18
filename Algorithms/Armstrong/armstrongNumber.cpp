#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,temp,sum=0,r;
	printf("enter the number\n");
	scanf("%d",&n);
	temp=n;
	while(temp>0)
	{
		r=temp%10;
		sum=sum+(r*r*r);
		temp=temp/10;
	}
	if(sum==n)
	{
		printf("%d is an armstrong number",n);
	}
	else
	{
		printf("%d is not an armstrong number",n);
	}
}
