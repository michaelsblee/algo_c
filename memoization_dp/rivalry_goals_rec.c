#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
INPUT: for one test case, info over five lines
1: int n, the number of games that each team plays
2: string of length n, where each char is W or L; this line is outcome of each game played by team Heroes
3: series of n ints, each of which represents number of goals scored in each game by the Heroes
4: string of length n, where each char is W or L; this line is outcome of each game played by team Villains
5: series of n ints, each of which represents number of goals scored in each game by the Villains

OUTPUT: a single integer = max number of goals scored in possible rivalry games
*/
int max(int v1, int v2) {
    if (v1>v2)
        return v1;
    else
        return v2;
}

int solve(char outcome1[], char outcome2[],
        int goals1[], int goals2[],
        int i, int j) /*
        1 for Heroes, 2 for Villains, i and j number of Heroes/Villains games being considered for this subproblem
        */
{
int first, second, third, fourth;

if (i==0 || j==0)
    return 0;

//TODO OPTIONS

return(0);
}