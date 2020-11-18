#include <iostream>
using namespace std;

int ld[30] = { 0 };
int rd[30] = { 0 };
int cl[30] = { 0 };

void printSolution(int board[][10],int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool solveNQUtil(int board[][10], int col,int N)
{

    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
    
        if ((ld[i - col + N - 1] != 1 &&
                rd[i + col] != 1) && cl[i] != 1) {
            
            board[i][col] = 1;
            ld[i - col + N - 1] =
                        rd[i + col] = cl[i] = 1;

        
            if (solveNQUtil(board, col + 1,N))
                return true;

            board[i][col] = 0; // BACKTRACK
            ld[i - col + N - 1] =
                        rd[i + col] = cl[i] = 0;
        }
    }

    return false;
}

bool solveNQ(int N)
{
    int board[10][10] = {0};

    if (solveNQUtil(board, 0,N) == false) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board,N);
    return true;
}

// driver program to test above function
int main()
{
    int n;
    cin>>n;
    solveNQ(n);
    return 0;
}
