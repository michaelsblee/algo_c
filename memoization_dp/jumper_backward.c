#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

int min(int v1, int v2) {
    if (v1 < v2)
        return v1;
    else
        return v2;
}

int solve_ij(int cost[], int n, int i, int j, int memo[SIZE+1][SIZE+1]) {
    /*
    cost: array of entry costs
    n: number of squares in the row
    i: the ending square for this subproblem
    j: the final jump distance for this subproblem
    memo: the memoization array
    */
    int first, second;
    
    if (memo[i][j]!=-2)
        return memo[i][j];
    if (i==2 && j==1) {
        memo[i][j]=0;
        return memo[i][j];
    }
    if (i - j >= 1 && j >= 2)
        first = solve_ij(cost, n, i - j, j - 1, memo);
    else
        first = -1;
    if (i + j <= n)
        second = solve_ij(cost, n, i + j, j, memo);
    else
        second = -1;
    if (first == -1 && second == -1) {
        memo[i][j] = -1;
        return memo[i][j];
    } else if (second == -1) {
        memo[i][j] = first + cost[i];
        return memo[i][j];
    } else if (first == -1) {
        memo[i][j] = second + cost[i];
        return memo[i][j];
    } else {
        memo[i][j] = min(first, second) + cost[i];
        return memo[i][j];
    }
    
}

int solve(int cost[], int n) {
    int i, j, best, result;
    static int memo[SIZE+1][SIZE+1];
    for (i=1;i<=SIZE;i++)
        for (j=1;j<=SIZE;j++)
            memo[i][j] = -2;
    best = -1;
    for (j=1;j<=n;j++) {
        result = solve_ij(cost, n, n, j, memo);
        if (result != -1) {
            if (best == -1)
                best = cost[2] + result;
            else
                best = min(best, cost[2] + result);
        }
    }
    return best;
}

int main(void) {
    int i,n;
    int cost[SIZE+1];
    scanf("%d ", &n);
    for (i=1;i<=n;i++)
        scanf("%d", &cost[i]);
    printf("%d\n", solve(cost, n));
    return 0;
}