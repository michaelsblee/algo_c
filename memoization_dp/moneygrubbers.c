#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double min(double v1, double v2) {
    if (v1 < v2)
        return v1;
    else
        return v2;
}

double solve_k(int num[], double price[], int num_schemes,
            double unit_price, int num_apples) {
    double best, result;
    int i;
    if (num_apples==0)
        return 0;
    else {
        result = solve_k(num, price, num_schemes, unit_price,
                         num_apples - 1);
        best = result + unit_price;
        for (i=0;i<num_schemes;i++)
            if (num_apples - num[i] >= 0) {
                result = solve_k(num, price, num_schemes, unit_price,
                                 num_apples - num[i]);
                best = min(best, result + price[i]);
        }
        return best;
    }
}