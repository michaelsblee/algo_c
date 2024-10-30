#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int v1, int v2) {
    if (v1 > v2)
        return v1;
    else
        return v2;
}

int solve_t(int m, int n, int t) {
    // m, n are ints of minutes that it takes to eat each burger; t is total min
    // return -1 if no lincom of m and n equals t
    // if return 0 or more, else

    if (t == 0)
        return;
    // assume final burger is a m-burger
    int first; // store optimal solution to the t-m subproblem
    if (t >= m)
        first = solve_t(m, n, t-m);
    else
        first = -1;

    int second; // store optimal solution to the t-m subproblem
    if (t >= n)
        second = solve_t(m, n, t-n);
    else
        second = -1;
    if (first == -1 && second == -1)
        return -1;
    return max(first, second) + 1;
}

void solve(int m, int n, int t) {
    int result, i;
    result = solve_t(m, n, t);
    if (result >= 0)
        printf("%d\n", result);
    else {
        i = t - 1;
        result = solve_t(m,n,i);
        while (result == -1) {
            i--;
            result = solve_t(m,n,i);
        }
        printf("%d %d\n", result, t-1);
    }
}

int main(void) { 
    int m, n, t;
    while (scanf("%d%d%d", &m, &n, &t) != -1)
        solve(m, n, t);
    return 0;
}
