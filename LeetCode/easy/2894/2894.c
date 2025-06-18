#include <stdio.h>

int differenceOfSums(int n, int m)
{
    int i;
    int sum1 = 0;
    int sum2 = 0;
    int ans = 0;
    i = 1;
    while (i <= n)
    {
        if (i % m != 0)
            sum1 += i;
        if (i % m == 0)
            sum2 += i;
        i++;
    }
    ans = sum1 - sum2;
    return ans;
}

int main()
{
    printf("%d\n",differenceOfSums(10, 3));
    printf("%d\n",differenceOfSums(5, 6));
    printf("%d\n",differenceOfSums(5, 1));
}