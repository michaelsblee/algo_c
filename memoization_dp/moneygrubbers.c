#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200
#define MAX_SCHEMES 20
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

double solve(int num[], double price[], int num_schemes,
             double unit_price, int num_apples) {
    double best;
    int i;
    best = solve_k(num, price, num_schemes,unit_price,num_apples);
    for (i=0;i<num_schemes;i++)
        best = min(best,solve_k(num,price,num_schemes,unit_price,i));
    return best; 
}

int get_number(int *num) {
    int ch;
    int ret=0;
    ch = getchar();
    while (ch!=' ' && ch!='\n'){
        ret=ret*10+ch-'0';
        ch=getchar();
    }
    *num=ret;
    return ch==' ';
}

int main(void) {
    int test_case,num_schemes,num_apples,more,i;
    double unit_price,result;
    int num[MAX_SCHEMES];
    double price[MAX_SCHEMES];
    test_case=0;
    //1
    while(scanf("%lf%d ", &unit_price, &num_schemes)!=-1){
        test_case++;
        for (i=0;i<num_schemes;i++)
            //2
            scanf("%d%lf ", &num[i], &price[i]);
        printf("Case %d:\n", test_case);
        more=get_number(&num_apples);
        //3
        while(more) {
            result = solve(num,price,num_schemes,
                unit_price,num_apples);
            printf("Buy %d for $%.2f\n",num_apples,result);
            more=get_number(&num_apples);
        }
        //4
        result=solve(num,price,num_schemes,unit_price,num_apples);
        printf("Buy %d for $%.2f\n", num_apples, result);
    }
    return 0;
}