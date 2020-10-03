#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	printf("Enter no. of elements: ");
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	printf("Enter %d elements of array in ascending order: ", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
	int key;
	printf("Enter key to be searched for: ");
	scanf("%d", &key);
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == a[mid])
		{
			printf("Element found at position %d", mid);
			break;
		}
		else if (key < a[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	if (low > high)
	{
		return -1;
	}
}