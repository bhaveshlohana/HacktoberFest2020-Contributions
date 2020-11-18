//To find the total number of possible solution and the time taken to compute for different value of 'n' in the knight's tour problem.
#include <stdio.h>
#include <time.h> 

int N;
int marked[100][100];  // marked[][] serves two purposes -
					  // 1. It keep track of squares involved the Knight's tour.
					 // 2. It stores the order in which the squares are marked
int counts=0,flag=0;
int row[] = { 2, 1, -1, -2, -2, -1, 1, 2 , 2 }; // 8 locsible movements for a knight.
int col[] = { 1, 2, 2, 1, -1, -2, -2, -1, 1 };

bool check(int m, int n) // Check if (m,n) is valid chess board coordinates as a knight cannot go out of the chessboard
{
	if (m < 0 || n < 0 || m >= N || n >= N)
		return false;

	return true;
}

// Recursive function to perform the Knight's tour using backtracking
void Knight_Tour(int m, int n, int loc)
{
	marked[m][n] = loc;	// mark the current locition as marked

	if (loc >= N*N) // if all squares are marked, print the solution
	{   static int k=1;
	 k++;
	    if(flag==0){
        printf("Solution -\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
					
					printf("%d\t",marked[i][j]);
				
			printf("\n");
			flag++;
		}
	    printf("\n");
	}
		counts=k;
		marked[m][n] = 0;  // backtrack before returning
		return;
	}

	for (int k = 0; k < 8; k++) // check for all 8 locsible movements for a knight and recur for each valid movement
	{
		int currX = m + row[k]; // Get the new locition of Knight from current locition on chessboard
		int currY = n + col[k];

		if (check(currX, currY) && !marked[currX][currY]) // if new locition is a valid and not marked yet
			Knight_Tour(currX, currY, loc + 1);
	}

	marked[m][n] = 0; // backtrack from current locition and remove it from the current path
}

int main()
{    
	int m,n;
    printf("Enter the number of knights(N) to be placed on a N*N chessboard:\n");
    scanf("%d",&N); // input number of knights

	printf("\nEnter the location (m,n coordinates) of knight \n");
	scanf("%d%d",&m,&n);
	if(m>N || n>N){
			printf("Incorrect coordinates !! The number is larger than the size(n)\n");
		}
    else{

		int loc = 1;
	    clock_t start,end;
	    start = clock();
		Knight_Tour(m,n,loc); // start knight tour from (m,n) coordinates
	    end = clock();

    double total_time = (double(end - start) / double(CLOCKS_PER_SEC)); //subtract the value & divide by no. of CLOCKS_PER_SEC to get processor time
	printf("\nProgram took %f seconds to execute \n", total_time);
	if(counts>=1){
			printf("\nTotal no. of solutions = %d",counts-1); // Print all locsible Knight's Tours in a chessboard
	}
	else{
            printf("The solution does not exist !!\n");
	}
	}
	return 0;
}

