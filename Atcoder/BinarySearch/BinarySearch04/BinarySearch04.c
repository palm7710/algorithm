#include <stdio.h>
#include <math.h> // dounle用

double N;

//x^3 + x = Nを満たす正の実数を求める
int main()
{
    double left;
    double right;
    double mid;
    long long x;
    scanf("%lf", &N);
    left = 0;
    right = 1000000; // 1e6
    while (right - left > 0.001)
    {
        mid = (left + right) / 2;
        x = mid * mid * mid + mid;
        if (x < N)
            left = mid + 1;
        else
            right = mid;
    }
    printf("%f\n", left);
}