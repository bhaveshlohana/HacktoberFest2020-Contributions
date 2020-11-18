#include <iostream>
using namespace std;

//Number of queens
int SIZE;

//chessboard
int board[100][100];
 
static void calculate_valid(int *valid, const int *pos)
{
    int val=1;
    int q;
    int c;
    for (q=1; q<SIZE; ++q)
    {
        if (val) // This is just an optimization
        {
            for (c=0; c<q; ++c)
            {
                val = val && (pos[c] != pos[q]) && (pos[c] + (q-c) != pos[q]) && (pos[c] != pos[q] + (q-c));
            }
        }
        valid[q] = val;
    }
 
} // end of calculate_valid
 
static void print_all(const int *p)
{
    int q;
 
    for (q=0; q<SIZE; ++q)
    {
       cout << "queen no." << q << " " << "column no."<< q << " " << "Row no."<< p[q] << endl;
    }
    printf("\n");
} // end of print_all
 
int main()
{
    printf("Enter the value of N for NxN chessboard\n");
       cin >> SIZE;
    int pos[SIZE];
    int valid[SIZE];
    int q;
    int solutions = 0;
    int iterations = 0;
 
    for (q=0; q<SIZE; ++q)
    {
        pos[q] = 0;
        valid[q] = 1;
    }
 
    while (1)
    {
        iterations++;
 
        calculate_valid(valid, pos);
        if (valid[SIZE-1])
        {
            solutions++;
            print_all(pos);
        }
 
        for (q=SIZE-1; q>=0; --q)
        {
            int val = (q==0) || (valid[q-1]);
            if (val && (pos[q]<SIZE-1))
            {
                pos[q]++;
                break; // out of for loop
            }
            pos[q] = 0;
        }
 
        if (q<0)
        {
            break; // out of while loop
        }
 
    } // end of while (1)
 
   
   
 
    return 0;
} // end of main
