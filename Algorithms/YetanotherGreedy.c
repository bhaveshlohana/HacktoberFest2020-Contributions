#include <stdio.h>
#include <stdlib.h>
 
void print_solution(const unsigned int *system, const unsigned int *coins, size_t n, FILE *fout)
{
    unsigned int coin;
    /* Print the number of each coin type used */
    for (coin = 0; coin < n; coin++) {
        if (coins[coin]) {
            fprintf(fout, "%d x %d\n", coins[coin], system[coin]);
        }
    }
}
 
int main(void)
{
    unsigned int system[] = {200, 100, 50, 20, 10, 5, 2, 1};
    const size_t n = sizeof(system) / sizeof(unsigned int);
 
    unsigned int *coins = calloc(n, sizeof(unsigned int));
    const unsigned int amount = 1741;
    unsigned int result = make_change(system, coins, n, amount);
    if (result) {
        print_solution(system, coins, n, stdout);
    }
    else {
        printf("No solution!\n");
    }
    free(coins);
    return 0;
}
