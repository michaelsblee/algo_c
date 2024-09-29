#include <stdio.h>
#include <stdarg.h>

int identical_right(int snow1[], int snow2[], int start)
{
    int offset;
    for (offset = 0; offset < 6; offset++) {
        if (snow1[offset] != snow2[(start + offset) % 6])
            return 0;
    }
    return 1;
}

int identical_left(int snow1[], int snow2[], int start)
{
    int offset, snow2_index;
    for (offset = 0; offset < 6; offset++) {
        snow2_index = start - offset;
        if (snow2_index <= -1)
            snow2_index += 6;
        if (snow1[offset] != snow2[snow2_index])
            return 0;
    }
    return 1;
}

int are_identical(int snow1[], int snow2[])
{
    int start;
    for (start = 0; start < 6; start++) {
        if (identical_right(snow1, snow2, start))
            return 1;
        if (identical_left(snow1, snow2, start))
            return 1;
    }
    return 0;
}

void identify_identical(int snowflakes[][6], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (are_identical(snowflakes[i], snowflakes[j])) {
                printf("%d and %d are identical\n", i + 1, j + 1);
                return;
            }
        }
    }
    printf("No two snowflakes are identical\n");
}



#define SIZE 100000

int code(int snowflake[]) {
    return (snowflake[0] + snowflake[1] * 10 + snowflake[2] * 100 + snowflake[3] * 1000 + snowflake[4] * 10000 + snowflake[5]) % SIZE;
}
int main(void) {
    static int snowflakes[SIZE][6];
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < 6; j++)
            scanf("%d", &snowflakes[i][j]);
    identify_identical(snowflakes, n);
    return 0;
}
