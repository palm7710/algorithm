#include <stdio.h>

long long N, K;
long long A[100000];

int check(long long x)
{
    long long sum;
    int i;
    sum = 0;
    i = 1;
    while (i <= N)
    {
        sum += x / A[i];
        i++;
    }
    return (sum >= K);
}

int main()
{
    int i;
    long long Left;
    long long Right;
    long long Mid;
    int ans;
    scanf("%lld %lld", &N, &K);
    i = 1;
    while (i <= N)
    {
        scanf("%lld", &A[i]);
        i++;
    }
    Left = 1;
    Right = 1000000000LL; // 10^9
    while (Left < Right)
    {
        Mid = (Left + Right) / 2;
        ans = check(Mid);
        if (!ans)
            Left = Mid + 1; // 答えがMid +１
        if (ans)
            Right = Mid; // 答えがMid以下
    }
    printf("%lld\n", Left);
}