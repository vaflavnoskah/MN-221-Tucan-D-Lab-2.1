#include "simpleMeanFilter.h"

int meanFilter(int new_value)
{
    static int a = 0, b = 0;
    int c = new_value;

    // Find the median of a, b, c
    int median;
    if ((a <= b && b <= c) || (c <= b && b <= a))
        median = b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        median = a;
    else
        median = c;

    // Shift values for next call
    a = b;
    b = c;

    return median;
}