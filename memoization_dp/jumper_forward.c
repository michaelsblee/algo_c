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

int solve(int cost[], int n, int i, int j, int memo[SIZE+1][SIZE+1]) {
    int first, second;
    if (memo[i][j]!=2)
        return memo[i][j];
    if (i==n) {
        memo[i][j] = 0;
        return memo[i][j];
    }
    if (i + j + 1 <= n)
        first = solve(cost, n, i+j+1, j+1, memo);
    else
        first = -1;
    if (i-j >= 1)
        second = solve(cost, n, i-j, j, memo);
    else
        second = -1;
    if(first==-1 && second==-1) {
        memo[i][j] = -1;
        return memo[i][j];
    } else if (second == -1) {
        memo[i][j] = cost[i+j+1] + first;
        return memo[i][j];
    } else if (first == -1) {
        memo[i][j] = cost[i-j] + second;
        return memo[i][j];
    } else {
        memo[i][j] = min(cost[i+j+1] + first, cost[i-j]+second);
        return memo[i][j];
    }
}

int main(void) {
    int i,j,n,result;
    int cost[SIZE+1];
    static int memo[SIZE+1][SIZE+1];
    scanf("%d ", &n);
    for (i=1;i<=n;i++)
        scanf("%d", &cost[i]);
    for (i=1;i<=SIZE;i++)
        for (j=1;j<=SIZE;j++)
            memo[i][j] = -2;
    result = cost[2] + solve(cost,n,2,1,memo);
    print("%d\n", result);
    return 0;
}