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

int main(void) {
    int s1[] = {1, 2, 3, 4, 5, 6};
    int s2[] = {3, 2, 1, 6, 5, 4};
    int answer;
    answer = are_identical(s1, s2);
    if (answer == 1)
        puts("Yes");
    else
        puts("No");
    return 0;
}
