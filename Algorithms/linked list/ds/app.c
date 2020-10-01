#include <stdlib.h>
#include <stdio.h>
struct rem
{
	int date;
	int rem;
	char work[1000];
	struct rem *next;
} *head = NULL;
void rem(int);
int leap(int);
void date(struct rem *, int);

int main()
{
	int ye, monno;
	printf("Enter the year:");
	scanf("%d", &ye);
	printf("Input Month No : ");
	scanf("%d", &monno);
	int arr[12]={31,leap(ye),31,30,31,30,31,31,30,31,31};
    rem(arr[monno-1]);
}
int leap(int year)
{
	if (year % 400 == 0)
		return 29;
	else if (year % 100 == 0)
		return 28;
	else if (year % 4 == 0)
		return 29;
	else
		return 28;
}

void rem(int mon)
{
	int day;
	for (int a = 1, i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if ((mon + 1) == a)
			{

				break;
			}
			else
			{
				printf("%d\t", a);
				struct rem *temp, *temp1;
				temp = (struct rem *)malloc(sizeof(struct rem));
				temp->date = a;
				temp->rem = 0;
				temp->next = NULL;
				a++;
				if (head == NULL)
				{
					head = temp;
					temp1 = temp;
				}
				else
				{
					temp1->next = temp;
					temp1 = temp;
				}
			}
		}
		printf("\n");
	}
	printf("Enter the Day you want to select :\t");
	scanf("%d", &day);
	date(head, day);
}

void date(struct rem *head, int day)

{
	printf("%d  %d", head->date, day);
	if (head->date == day)
	{
		if (head->rem == 0)
		{
			printf("Enter your work");
			scanf("%s", head->work);
			head->rem = 1;
		}
		else
		{
			printf("The work is already alloted and the work is %s", head->work);
		}

		date(head->next, day);
	}
}