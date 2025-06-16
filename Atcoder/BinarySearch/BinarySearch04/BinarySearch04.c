#include <stdio.h>

int N;

//x^3 + x = Nを満たす正の実数を求める
int main()
{
    int left;
    int right;
    int mid;
    long long x;
    scanf("%d", &N);
    left = 1;
    right = 100000;
    while (left < right)
    {
        mid = (left + right) / 2;
        x = 1LL * mid * mid * mid + mid;
        if (x < N)
            left = mid + 1;
        else
            right = mid;
    }
    printf("%d\n", left);
}