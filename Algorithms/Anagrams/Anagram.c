#include<stdio.h>
int anagram(char [],char []);
int main()
{
	char a[50],b[50];
	puts("Enter first string");
	gets(a);
	puts("Enter Second string");
	gets(b);
	if(anagram(a,b)==1)
	{
		printf("string are anagram");
	}
	else
	{
		printf("String aren't anagram");
	}
	
}
int anagram(char a[],char b[])
{
	int first[26]={0},second[26]={0},c=0;
	while(a[c]!=0)
	{
		first[a[c]-'a']++;
		c++;
	}
	c=0;
	while(b[c]!=0)
	{
		second[b[c]-'a']++;
		c++;
	}
	for(c=0;c<26;c++)
	{
		if(first[c]!=second[c])
		{
			return 0;
		}
	}
	return 1;
	
}