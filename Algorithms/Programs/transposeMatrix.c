#include <stdio.h>
#include <stdlib.h>

void main(){
	int **a;
	int r,c;
	int i,j;
	printf("\nenter rows and columns for matrix :");
	scanf("%d %d", &r, &c);
	a = (int **) malloc(sizeof(int *)*r);
	for( i = 0;i < r; i++)
		a[i]=(int *) malloc(sizeof(int*)*c);
	printf("\n enter matrix one %d by %d\n",r, c);
	for(i=0;i < r; i++)
		for(j=0;j < c; j++)
			scanf("%d",&a[i][j]);
	printf("Enter the actual matrix:\n");
	for(i=0;i < r; i++) {
		for(j=0;j < c; j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("\n Transpose of matrix one and two is\n");
	for(i=0;i < c; i++) {
		for(j=0;j < r; j++)
			printf("%d\t",a[j][i]);
		printf("\n");
	}
	for(i=0;i < r; i++)
		free(a[i]);
	free(a);
}
