#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
/*
INPUT: for one test case, info over five lines
1: int n, the number of games that each team plays
2: string of length n, where each char is W or L; this line is outcome of each game played by team Heroes
3: series of n ints, each of which represents number of goals scored in each game by the Heroes
4: string of length n, where each char is W or L; this line is outcome of each game played by team Villains
5: series of n ints, each of which represents number of goals scored in each game by the Villains

OUTPUT: a single integer = max number of goals scored in possible rivalry games
*/

// use memo[][] with two dimensions s.t. memo[i][j] holds solution to subproblem
// on the first i Heroes and the first j Villains games
int max(int v1, int v2) {
    if (v1>v2)
        return v1;
    else
        return v2;
}

int solve(char outcome1[], char outcome2[], int goals1[], int goals2[],
        int i, int j, int memo[SIZE+1][SIZE+1]) /*
        1 for Heroes, 2 for Villains, i and j number of Heroes/Villains games being considered for this subproblem
        */
{
    int first, second, third, fourth;

    if (memo[i][j]!=-1)
        return memo[i][j];

    if (i==0 || j==0)
        memo[i][j] = 0;
        return memo[i][j];

    if ((outcome1[i]=='W' && outcome2[j]=='L' && goals1[i]>goals2[j]) ||
        (outcome1[i]=='L' && outcome2[j]=='W' && goals1[i]<goals2[j]))
            first=solve(outcome1, outcome2, goals1, goals2, i-1, j-1, memo) + 
            goals1[i] + goals2[j];
    else
        first=0;
    second=solve(outcome1,outcome2,goals1,goals2,i-1,j-1, memo); // option 2, when last games for both teams don't matter
    third=solve(outcome1,outcome2,goals1,goals2, i-1, j, memo); // option, when last game for Heroes doesn't matter
    fourth=solve(outcome1,outcome2,goals1,goals2, i, j-1, memo);
    memo[i][j] = max(first, max(second, max(third,fourth)));
    return memo[i][j];
}
int main(void) {
    int i, j, n, reesult;
    char outcome1[SIZE+1], outcome2[SIZE+1];
    int goals1[SIZE+1], goals2[SIZE+1];
    static int memo[SIZE+1][SIZE+1];
    scanf("%d ", &n);
    for (i=1;i<=n;i++)
        scanf("%c", &outcome1[i]);
    for (i=1;i<=n;i++)
        scanf("%d ", &goals1[i]);
    for (i=1;i<=n;i++)
        scanf("%c", &outcome2[i]);
    for (i=1;i<=n;i++)
        scanf("%d", &goals2[i]);
    for (i=0; i<=SIZE; i++)
        for (j=0; j<=SIZE; j++)
            memo[i][j] = -1;
    result = solve(outcome1, outcome2, goals1, goals2, n, n, memo);
    print("%d\n", result);
    return 0;
}